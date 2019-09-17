//
//  main.cpp
//  1225.암호생성기
//
//  Created by carrot on 25/05/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
int t, num[8];

void cycle(int begin) {
    int mCnt=1;
    for (int i=0; i<5; i++) {
        int index;
        if (begin+i>=8) {
            num[begin+i-8] -= mCnt;
            index = begin+i-8;
        } else {
            num[begin+i] -= mCnt;
            index = begin+i;
        }
        mCnt++;
        
        if (num[index]<=0) {
            num[index]=0;
            
            for (int j=1; j<=8; j++) {
                if (index+j>=8) {
                    cout << num[index+j-8] << " ";
                } else {
                    cout <<  num[index+j] << " ";
                }
            }
            
            return;
        }
    }
    
    if (begin+5>=8) {
        return cycle(begin-3);
    } else {
        return cycle(begin+5);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    for (int tc=1; tc<=10; tc++) {
        cin >> t;
        for (int i=0; i<8; i++) {
            cin >> num[i];
        }
        
        cout <<"#"<<tc<<" ";
        cycle(0);
        cout <<"\n";
    }
    
    return 0;
}
