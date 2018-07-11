//
//  main.cpp
//  10799
//
//  Created by 양종열 on 2018. 7. 11..
//  Copyright © 2018년 양종열. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false);
    
    string str;
    cin >> str;
    
    int total = 0;
    bool flag = false;
    stack<char> s;
    for (int i=0; i<str.length()-1; i++) {
        if (str[i] == '(') {
            if (str[i+1] != ')') {
                total ++;
            }
            
            s.push(str[i]);
            flag = false;
        } else {
            s.pop();
            
            if (!flag) {
                total += s.size();
                flag = true;
            }
        }
    }
    
    cout << total;
    return 0;
}
