//
//  main.cpp
//  11722
//
//  Created by 양종열 on 2018. 7. 5..
//  Copyright © 2018년 양종열. All rights reserved.
//

/*
10 30 10 20 40 30 20 10
 1
 1 1
 1 1 2
 1 1 2 2
 1 1 2 2 1
 1 1 2 2 1 2
 1 1 2 2 1 2 max(1+1, 0) -> max(2+1, 2) => 3
 1 1 2 2 1 2 3 max(2+1, 0) -> max(3+1, 3) => 4
*/

#include <iostream>
#include <cmath>
int dp[1001];
int arr[1001];
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    
    for (int i=1; i<=N; i++) {
        cin >> arr[i];
        dp[i] = 1;
    }
    
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=i; j++) {
            if (arr[j] > arr[i]) {
                dp[i] = max(dp[i], dp[j]+1);
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
