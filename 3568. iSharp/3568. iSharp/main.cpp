//
//  main.cpp
//  3568. iSharp
//
//  Created by carrot on 17/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string type;
    cin >> type;
    
    string str;
    getline(cin,str);
    
    int valf=1;
    for (int i=1; i<str.length(); i++) {
        if (str[i]==',' || str[i]==';') {
            cout << type;
            for (int j=i-1; j>=1; j--) {
                if (str[j]=='&' || str[j]=='*') cout << str[j];
                else if (str[j]=='[') cout << ']';
                else if (str[j]==']') cout << '[';
                else break;
            }
            
            cout <<" ";
            for (int j=valf; j<i; j++) {
                if (str[j]=='[' || str[j]==']' || str[j]=='&' || str[j]=='*') break;
                else cout << str[j];
            }
            cout << ";\n";
            valf = i+2;
            i++;
        }
    }
    return 0;
}
