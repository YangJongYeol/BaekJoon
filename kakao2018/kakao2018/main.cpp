//
//  main.cpp
//  kakao2018
//
//  Created by carrot on 02/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    string str, str1, str2, str3; int num;
    //vector<pair<string,string>> parse;
    vector<pair<string,string>> tmp;
    map<string,string> m;
    for (int i=0; i<record.size(); i++) {
        num = 0; stringstream ss(record[i]);
        while (ss>>str) {
            if (num==0) {str1=str; num++;}
            else if (num==1) {str2=str; num++;}
            else {str3=str; num++;}
        }
        
        if (str1=="Enter") tmp.push_back(make_pair(str2, "님이 들어왔습니다."));
        if (str1=="Leave") { tmp.push_back(make_pair(str2, "님이 나갔습니다.")); continue; }

//        bool flag = true;
//        for (int j=0; j<parse.size(); j++) {
//            if (parse[j].first==str2) {
//                parse[j].second=str3;
//                flag=false;
//            }
//        }
//        if (flag) parse.push_back(make_pair(str2, str3));
        if (m.find(str2)==m.end())
            m.insert(make_pair(str2,str3));
        else
            m.at(str2) = str3;
    }
    
    for (int i=0; i<tmp.size(); i++) {
//        for (int j=0; j<parse.size(); j++) {
//            if (tmp[i].first==parse[j].first) {
//                answer.push_back(parse[j].second+tmp[i].second);
//                break;
//            }
//        }
        answer.push_back(m.at(tmp[i].first)+tmp[i].second);
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]
    vector<string> record;
    record.push_back("Enter uid1234 Muzi");
    record.push_back("Enter uid4567 Prodo");
    record.push_back("Leave uid1234");
    record.push_back("Enter uid1234 Prodo");
    record.push_back("Change uid4567 Ryan");
    vector<string> answer = solution(record);
    
    for (int i=0; i<answer.size(); i++)
        cout << answer[i] << endl;
    return 0;
}
