//
//  main.cpp
//  kakao2019_2
//
//  Created by carrot on 07/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool perfect(string str) {
    stack<char> s;
    for (int i=0; i<str.length(); i++) {
        if (str[i]=='(') s.push('(');
        if (str[i]==')' && !s.empty()) s.pop();
    }
    
    if (s.size()) return false;
    return true;
}

string solution(string p) {
    string answer = "";
    if (p=="") return "";
    
    string str = p;
    do {
        string u="", v="";
        int num_open=0, num_close=0; int idx;
        for (idx=0; idx<str.length(); idx++) {
            if (str[idx]=='(') { u+=str[idx]; num_open++; }
            if (str[idx]==')') { u+=str[idx]; num_close++; }
            if (num_open == num_close) break;
        }
        
        for (idx+=1; idx<str.length(); idx++)
            v+=str[idx];
        
        if (perfect(u)) {
            answer += u;
            str = v;
        } else {
            string tmp = "(";
            tmp += solution(v);
            tmp += ")";
            for (int i=1; i<u.length()-1; i++) {
                if (u[i]=='(') tmp += ")";
                if (u[i]==')') tmp += "(";
            }
            answer += tmp;
        }
    } while (answer.length()!=p.length());
    
    return answer;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<solution("()))((()")<<endl;
    return 0;
}
