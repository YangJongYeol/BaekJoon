//
//  main.cpp
//  2579
//
//  Created by 양종열 on 2018. 7. 3..
//  Copyright © 2018년 양종열. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int dp[301];
vector<int> vc;

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false);
    
    int N;
    cin>> N;
    
    int tmp;
    for (int i=0; i<N; i++) {
        cin>>tmp;
        vc.push_back(tmp);
    }
    
    dp[0] = vc[0];
    dp[1] = vc[0]+vc[1];
    dp[2] = max(vc[0]+vc[1], vc[1]+vc[2]);
    for (int i=0; i<N; i++) {
        dp[i] = max(dp[i-2]+vc[i], dp[i-3]+vc[i]+vc[i-1]);
    }
    
    cout<<dp[N-1];
    return 0;
}
