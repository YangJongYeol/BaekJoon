//
//  main.cpp
//  11055
//
//  Created by 양종열 on 2018. 7. 5..
//  Copyright © 2018년 양종열. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
int dp[1001];
int arr[1001];

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    
    for (int i=1; i<=N; i++) {
        cin >> arr[i];
        dp[i] = arr[i];
    }
    
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[j]+arr[i], dp[i]);
            }
        }
    }
    
    int max = 0;
    for (int i=1; i<=N; i++) {
        if (dp[i] > max) {
            max = dp[i];
        }
    }
    
    cout<<max;
    return 0;
}
