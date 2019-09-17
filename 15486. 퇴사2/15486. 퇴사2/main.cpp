//
//  main.cpp
//  15486. 퇴사2
//
//  Created by carrot on 30/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#define max(X,Y) (X)>(Y)?(X):(Y)
using namespace std;
int N, list[1500002][2], dp[1500002], d;

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d", &N);
    for (int i=1; i<=N; i++)
        scanf("%d %d", &list[i][0], &list[i][1]);
    
    for (int i=1; i<=N+1; i++) {
        d = max(d,dp[i]);
        if (i+list[i][0]>N+1) continue;
        dp[i+list[i][0]] = max(d+list[i][1],dp[i+list[i][0]]);
    }
    
    printf("%d", d);
    return 0;
}
