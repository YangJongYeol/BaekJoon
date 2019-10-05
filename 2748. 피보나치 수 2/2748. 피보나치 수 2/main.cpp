//
//  main.cpp
//  2748. 피보나치 수 2
//
//  Created by carrot on 04/10/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
using namespace std;
int n;
long dp[91];

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d", &n);
    dp[0]=0; dp[1]=1;
    for (int i=2; i<=n; i++)
        dp[i]=dp[i-1]+dp[i-2];
    
    printf("%ld",dp[n]);
    return 0;
}
