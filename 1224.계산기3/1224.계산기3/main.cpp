//
//  main.cpp
//  1224.계산기3
//
//  Created by carrot on 29/06/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    for (int tc=1; tc<=10; tc++) {
        int n=0;
        scanf("%d",&n);
        
        char str[n];
        scanf("%s",str);
        
        stack<long> s;
        for (int i=0; i<n; i++) {
            if (str[i]=='(') {
                s.push(-1);
            } else if (str[i]==')') {
                long tmp = 0;
                while (true) {
                    if (s.top()==-1) {
                        s.pop();
                        if (!s.empty() && s.top()==-2) {
                            s.pop();
                            tmp *= s.top();
                            s.pop();
                        }
                        s.push(tmp);
                        break;
                    } else {
                        tmp += s.top();
                        s.pop();
                    }
                }
            } else if (str[i]=='+') { continue; }
            else if (str[i]=='*') {
                if (str[i+1]=='(') {
                    s.push(-2);
                } else {
                    long tmp = str[i+1]-'0';
                    //printf("%d\n",tmp);
                    tmp *= s.top();
                    s.pop();
                    s.push(tmp);
                    i++;
                }
            } else {
                s.push(str[i]-'0');
            }
        }
        
        printf("#%d %ld\n",tc, s.top());
    }
    
    return 0;
}
