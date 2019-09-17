//
//  main.cpp
//  1221.GNS
//
//  Created by carrot on 25/05/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
int numCnt[10];
string numStr[10] = {"ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN"};

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    for (int tc=1; tc<=t; tc++) {
        string str;
        int num;
        cin >> str >> num;
        
        memset(numCnt, 0, sizeof(numCnt));
        
        string tmp;
        for (int i=0; i<num; i++) {
            cin >> tmp;
            for (int j=0; j<10; j++) {
                if (tmp == numStr[j]) {
                    numCnt[j]++;
                    break;
                }
            }
        }
        
        cout << "#" << tc << "\n";
        
        for (int i=0; i<10; i++) {
            for (int j=0; j<numCnt[i]; j++) {
                cout << numStr[i] << " ";
            }
        }
        
        cout << "\n";
    }
    
    return 0;
}
