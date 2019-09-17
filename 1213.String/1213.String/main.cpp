//
//  main.cpp
//  1213.String
//
//  Created by carrot on 13/05/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    for (int tc = 1; tc<=10; tc++) {
        cin >> tc;
        string word, str;
        int count = 0;
        cin >> word >> str;
        
//        for (string::size_type index=0;;) {
//            index = str.find(word, index+word.size());
//
//            if (index == string::npos) {
//                break;
//            } else {
//                count++;
//            }
//        }
        
        for (int i=0; i<str.length()-word.size(); i++) {
            string tmp = str.substr(i,word.size());
            if (tmp.compare(word) == 0) {
                count++;
            }
        }
        
        cout << "#" << tc << " " << count << "\n";
    }
    
    return 0;
}
