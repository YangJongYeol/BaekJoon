//
//  main.cpp
//  1256. K번째 접미어
//
//  Created by carrot on 31/07/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false); cin.tie(0);
    
    int T;
    cin >> T;
    
    for (int t=1; t<=T; t++) {
        int num; string str;
        cin >> num;
        cin >> str;
        
        vector<string> vc;
        for (int i=0; i<str.length(); i++) {
            string tmp = str.substr(i,str.length()-i);
            
            vc.push_back(tmp);
        }
        
        sort(vc.begin(), vc.end());
        
        cout << "#" << t << " " << vc[num-1] << "\n";
    }
    return 0;
}
