//
//  main.cpp
//  1215.회문1
//
//  Created by carrot on 14/05/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    for (int tc = 1; tc<=10; tc++) {
        int count = 0;
        
        int N;
        cin >> N;
        
        string map[8];
        for (int i=0; i<8; i++) {
            cin >> map[i];
        }
        
        for (int i=0; i<8; i++) {
            for (int j=0; j<=8-N; j++) {
                string str_origin = map[i].substr(j, N);
                string str_reverse = str_origin;
                reverse(str_reverse.begin(), str_reverse.end());
                
                if (str_origin.compare(str_reverse)==0) {
                    count++;
                }
            }
        }
        
        for (int i=0; i<8; i++) {
            for (int j=0; j<=8-N; j++) {
                string str_origin = "";
                
                for (int k=0; k<N; k++) {
                    str_origin += map[j+k][i];
                }
                
                string str_reverse = str_origin;
                reverse(str_reverse.begin(), str_reverse.end());
                
                if (str_origin.compare(str_reverse)==0) {
                    count++;
                }
            }
        }
        
        cout << "#" << tc << " " << count << "\n";
    }
    
    return 0;
}
