//
//  main.cpp
//  15486. 퇴사2(2)
//
//  Created by carrot on 07/10/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#define MAX(A,B) (A>B?A:B)
using namespace std;
int N, dp[1500001], day[1500001][2];

void df(int idx) {
    int next=idx+day[idx][0]-1;
    if (next>N)
        dp[N]=MAX(dp[N],dp[idx]);
    else
        dp[next]=MAX(dp[next],dp[idx-1]+day[idx][1]);
    
    if(idx<N) {
        dp[idx+1]=MAX(dp[idx+1],dp[idx]);
        df(idx+1);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d",&N);
    for (int i=1; i<=N; i++) scanf("%d %d",&day[i][0],&day[i][1]);
    dp[0]=0;
    df(1);
    printf("%d",dp[N]);
    return 0;
}
