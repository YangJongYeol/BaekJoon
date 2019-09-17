//
//  main.cpp
//  11726-2Xn 타일링
//
//  Created by 양종열 on 2018. 5. 11..
//  Copyright © 2018년 양종열. All rights reserved.
//

#include <iostream>
using namespace std;
int dp[1001];

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false);
    
    int n;
    cin>>n;
    
    dp[1] = 1; dp[2] = 2;
    for (int i=3; i<=n; i++) {
        dp[i] = (dp[i-1] + dp[i-2])%10007;
    }
    
    cout<<dp[n]%10007;
    return 0;
}
