//
//  main.cpp
//  1874
//
//  Created by 양종열 on 2018. 2. 11..
//  Copyright © 2018년 양종열. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false);
    stack<int> stack;
    stack.push(0);
    
    int n;
    cin>>n;
    
    int tmp;
    int popMax = 0;
    string result = "";
    while(n--) {
        cin>>tmp;
        
        if(stack.top() < tmp) {
            while (stack.top() != tmp) {
                popMax++;
                stack.push(popMax);
                result += "+\n";
            }
            
            stack.pop();
            result += "-\n";
        } else if(stack.top() == tmp) {
            stack.pop();
            result += "-\n";
        } else {
            result = "NO";
            break;
        }
    }
    
    
    cout<<result;
    return 0;
}
