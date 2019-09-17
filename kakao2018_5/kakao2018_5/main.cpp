//
//  main.cpp
//  kakao2018_5
//
//  Created by carrot on 03/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool comp (string a, string b) {
    if (a.size()<b.size()) return true;
    return false;
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end(), comp);
    
    for (int i=0; i<phone_book.size(); i++) {
        for (int j=0; j<phone_book.size(); j++) {
            if (i==j) continue;
            if (phone_book[i].find(phone_book[j], 0)!=string::npos) {
                return false;
                
            }
        }
    }
    return answer;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    cout << solution({"111", "111", "789"});
    return 0;
}
