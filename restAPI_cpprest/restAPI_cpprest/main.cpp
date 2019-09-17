// brew install cpprestsdk
// Header Search Path : /usr/local/include; /usr/local/opt/openssl@1.1/include
// Library Seradh Path : /usr/local/opt/cpprestsdk/lib; /usr/local/opt/boost/lib; /usr/local/opt/openssl@1.1/lib
// Other Linker Flag : -lcpprest -lssl -lcrypto -lboost_system -lboost_thread-mt -lboost_chrono-mt

#include <iostream>
#include <vector>
#include <cstring>
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>

using namespace std;
using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams

string action[7] = {"STOP","UP","DOWN","OPEN","CLOSE","ENTER","EXIT"};

json::value makeJson(int id, int command, int call_id=-1) {
    json::value v;
    v["elevator_id"]=id;
    v["command"]=json::value::string(U(action[command]));

    if (call_id!=-1) {
        json::value arr;
        arr[0]=call_id;
        v["call_ids"]=arr;
    }
    
    return v;
}

int main(int argc, char* argv[]) {
    //start
    string token = "";
    http_client client_post(U("http://localhost:8000/start/tester/2/1"));
    json::value value = client_post.request(methods::POST).get().extract_json(true).get();
    token = value.at("token").as_string().c_str();
    
    http_client client_get(U("http://localhost:8000/oncalls"));
    http_request request_get(methods::GET);
    request_get.headers().add("X-Auth-Token", token);

    http_client client_action(U("http://localhost:8000/action"));
    http_request request_action(methods::POST);
    request_action.headers().add("X-Auth-Token", token);
    request_action.headers().add("Content-Type","application/json");
    
    while(1) {
        //oncall
        value = client_get.request(request_get).get().extract_json(true).get();
        if (value.at("is_end").as_bool()) break;
        
        json::array elevators = value.at("elevators").as_array();
        json::array calls = value.at("calls").as_array();
        printf("calls size : %d\n", (int)calls.size());
        if ((int)calls.size()==0 && elevators[0].at("passengers").size()==0) {
            json::value command = makeJson(0, 0);  // stop
            json::value commands; commands[0] = command;
            json::value action; action["commands"]=commands;
            request_action.set_body(action);
        } else {
            string status = elevators[0].at("status").as_string().c_str();
            json::value command, commands, action;
            bool is_passenger = (elevators[0].at("passengers").size()?true:false);
            if (status=="STOPPED") {    // stop, open, down, up
                if (is_passenger) {
                    if (elevators[0].at("passengers").at(0).at("end").as_integer()>elevators[0].at("floor").as_integer()) {
                        command = makeJson(0, 1);  // up
                    } else if (elevators[0].at("passengers").at(0).at("end").as_integer()<elevators[0].at("floor").as_integer()) {
                        command = makeJson(0, 2);  // down
                    } else
                        command = makeJson(0, 3);  // open
                } else {
                    if (calls[0].at("start").as_integer()>elevators[0].at("floor").as_integer()) {
                        command = makeJson(0, 1);  // up
                    } else if (calls[0].at("start").as_integer()<elevators[0].at("floor").as_integer()) {
                        command = makeJson(0, 2);  // down
                    } else
                        command = makeJson(0, 3);  // open
                }
            } else if (status=="OPENED") {  // open, enter, exit, close
                if (is_passenger) {
                    if (elevators[0].at("passengers").at(0).at("end").as_integer()==elevators[0].at("floor").as_integer()) {
                        int id = elevators[0].at("passengers").at(0).at("id").as_integer();
                        command = makeJson(0, 6, id);  // exit
                    } else
                        command = makeJson(0, 4);  // close
                } else {
                    if (calls[0].at("start").as_integer()==elevators[0].at("floor").as_integer()) {
                        int id = calls[0].at("id").as_integer();
                        command = makeJson(0, 5, id);  // enter
                    } else
                        command = makeJson(0, 4);  // close
                }
            } else if (status=="UPWARD") {  // stop, up
                if (is_passenger) {
                    if (elevators[0].at("passengers").at(0).at("end").as_integer()==elevators[0].at("floor").as_integer()) {
                        command = makeJson(0, 0);  // stop
                    } else
                        command = makeJson(0, 1);  // up
                } else {
                    if (calls[0].at("start").as_integer()==elevators[0].at("floor").as_integer()){
                        command = makeJson(0, 0);  // stop
                    } else
                        command = makeJson(0, 1);  // up
                }
            } else {    // stop, down
                if (is_passenger) {
                    if (elevators[0].at("passengers").at(0).at("end").as_integer()==elevators[0].at("floor").as_integer()) {
                        command = makeJson(0, 0);  // stop
                    } else
                        command = makeJson(0, 2);  // down
                } else {
                    if (calls[0].at("start").as_integer()==elevators[0].at("floor").as_integer()){
                        command = makeJson(0, 0);  // stop
                    } else
                        command = makeJson(0, 2);  // down
                }
            }
            commands[0] = command;
            action["commands"]=commands;
            request_action.set_body(action);
            printf("status : %s / action : %s\n",status.c_str(),command.at("command").as_string().c_str());
        }
        
//        printf("%d\n",client_action.request(request_action).get().status_code());
        client_action.request(request_action).get();
    }
}


// GET
//    http_client client(U("https://swapi.co/api/people/?search=Luke%20Skywalker"));
//    http_request request(methods::GET);
//    client.request(request).then([=](http_response response) {
//        printf("%d\n",response.status_code());
//        printf("%s\n",response.headers().content_type().c_str());
//        response.extract_json(true).then([](json::value value) {
//            auto array = value.at("results").as_array();
//            for (int i=0; i<array.size(); i++)
//                printf("%d : %s\n", i, array[i].at(U("name")).as_string().c_str());
//        }).wait();
//    }).wait();
//
//    // POST
//    http_client client(U("https://httpbin.org/post"));
//    json::value postData;
//    postData["name"] = json::value::string(U("Luke Skywalker"));
//
//    client.request(methods::POST,U("/"),postData).then([=](http_response responese) {
//        printf("%d\n",responese.status_code());
//        responese.extract_json(true).then([](json::value value) {
//            printf("%s\n", value.serialize().c_str());
//        }).wait();
//    }).wait();
