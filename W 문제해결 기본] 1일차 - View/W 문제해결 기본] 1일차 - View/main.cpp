//
//  main.cpp
//  W 문제해결 기본] 1일차 - View
//
//  Created by carrot on 06/05/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    for (int i=1; i<=10; i++) {
        int N, sum=0;
        cin >> N;
        
        int b[N];
        
        for (int j=0; j<N; j++) {
            cin >> b[j];
        }
        
        for (int j=2; j<N-2; j++) {
            int tmp = 255;
            for(int k=-2; k<=2; k++) {
                if (k==0) continue;
                
                if (b[j+k] > b[j]) {
                    tmp = 0;
                    break;
                }
                
                if (tmp>(b[j]-b[j+k]))
                    tmp = b[j]-b[j+k];
            }
            sum += tmp;
        }
        
        cout << "#" << i << " " << sum << endl;
    }
    
    return 0;
}
