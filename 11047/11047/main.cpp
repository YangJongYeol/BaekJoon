//
//  main.cpp
//  11047
//
//  Created by 양종열 on 2018. 7. 3..
//  Copyright © 2018년 양종열. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false);
    
    long long K, N, count = 0;
    cin>>N>>K;
    
    long long tmp, num;
    vector<long long> vc;
    for (int i=0; i<N; i++) {
        cin>>tmp;
        vc.push_back(tmp);
    }
    
    for (long long i=N-1; i>=0; i--) {
        if (K/vc[i] != 0) {
            num = K/vc[i];
            count += num;
            K = K - num*vc[i];
        }
    }
    
    cout<<count;
    return 0;
}
