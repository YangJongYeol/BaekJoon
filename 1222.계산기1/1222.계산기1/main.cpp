//
//  main.cpp
//  1222.계산기1
//
//  Created by carrot on 09/06/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    for (int tc = 1; tc <= 10; tc++) {
        int num, result=0;
        stack<int> s;
        cin >> num;
        
        string str;
        cin >> str;
        
        s.push(str[0]-'0');
        for (int i=1; i<str.length()-1; i++) {
            if (str[i]=='+') {
                s.push(str[i+1]-'0');
            } else if (str[i]=='*') {
                int tmp = s.top();
                s.pop();
                tmp *= (str[i+1]-'0');
                s.push(tmp);
            }
        }
        
        for (int i=0; i<s.size();) {
            result += s.top();
            s.pop();
        }
        
        cout << "#" << tc << " " << result << "\n";
    }
    
    return 0;
}
