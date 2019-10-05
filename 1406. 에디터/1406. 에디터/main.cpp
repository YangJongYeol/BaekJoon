//
//  main.cpp
//  1406. 에디터
//
//  Created by carrot on 05/10/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <stack>
#define loop(a,b) for(int a=0; a<b; a++)
#define MAX 600000
using namespace std;
string str;
int N;

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    stack<char> head; stack<char> tail;
    cin >> str >> N;
    loop(i,str.length()) head.push(str[i]);
    loop(i,N) {
        char command; cin >> command;
        switch (command) {
            case 'L':
                if (!head.empty()) {
                    tail.push(head.top());
                    head.pop();
                }
                break;
            case 'D':
                if (!tail.empty()) {
                    head.push(tail.top());
                    tail.pop();
                }
                break;
            case 'B':
                if (!head.empty())
                    head.pop();
                break;
            case 'P':
                char ch; cin >> ch;
                head.push(ch);
                break;
        }
    }
    
    while(!head.empty()) {
        tail.push(head.top());
        head.pop();
    }
    
    while(!tail.empty()) {
        cout << tail.top();
        tail.pop();
    }
    return 0;
}
