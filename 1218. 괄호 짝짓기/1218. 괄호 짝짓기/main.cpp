//
//  main.cpp
//  1218. 괄호 짝짓기
//
//  Created by carrot on 01/06/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

//'()', '[]', '{}', '<>'
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    for (int tc=1; tc<=10; tc++) {
        string str; int num;
        cin >> num >> str;
        
        vector<char> vc;
        int flag = 1;
        for (int i=0; i<num; i++) {
            if (str[i]=='(' || str[i]=='[' || str[i]=='{' || str[i]=='<') {
                vc.push_back(str[i]);
            } else {
                if (str[i]==')' && vc[vc.size()-1]=='(') {
                    vc.pop_back();
                } else if (str[i]==']' && vc[vc.size()-1]=='[') {
                    vc.pop_back();
                } else if (str[i]=='}' && vc[vc.size()-1]=='{') {
                    vc.pop_back();
                } else if (str[i]=='>' && vc[vc.size()-1]=='<') {
                    vc.pop_back();
                } else {
                    flag = 0;
                    break;
                }
            }
        }
        
        cout << "#" << tc << " " << flag << "\n";
    }
    return 0;
}
