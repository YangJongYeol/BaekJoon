//
//  main.cpp
//  1257. K번째 문자열
//
//  Created by carrot on 05/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    
    for (int t=1; t<=T; t++) {
        int k; string str; set<string> s; vector<string> vc;
        cin >> k >> str;
        
        for (int i=1; i<=str.length(); i++) {
            for (int j=0; j<=str.length()-i; j++){
                s.insert(str.substr(j,i));
            }
        }
        
        vc.assign(s.begin(), s.end());
        sort(vc.begin(), vc.end());
        
        cout << "#" << t << " " << vc[k-1] << "\n";
    }
    
    
    return 0;
}
