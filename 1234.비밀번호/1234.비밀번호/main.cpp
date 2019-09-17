//
//  main.cpp
//  1234.비밀번호
//
//  Created by carrot on 12/05/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

string cal(int length, string password) {
    for (int i=1; i<length; i++) {
        if (password[i] == password[i-1]) {
            password.erase(i-1,2);
            
            return cal(length-2, password);
        }
    }
    
    return password;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    for (int tc=1; tc<=10; tc++) {
        int length;
        string password;
        
        cin >> length >> password;
        
        cout << "#" << tc << " " << cal(length, password) << "\n";
    }
    
    return 0;
}
