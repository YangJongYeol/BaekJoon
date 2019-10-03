//
//  main.cpp
//  2916. 자와 각도기
//
//  Created by carrot on 03/10/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#define loop(a,b) for(int a=0; a<b; a++)
using namespace std;
int N, K;
int angle[10], dp[10][360], ans[360];

void df(int idx, int amt) {
    if (idx>N || dp[idx][amt]!=-1) return;
    dp[idx][amt]=1; ans[amt]=1;
    df(idx,(360+amt-angle[idx])%360);
    df(idx+1,amt);
    df(idx,(360+amt+angle[idx])%360);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d %d", &N, &K);
    loop(i,N) scanf("%d", &angle[i]);
    sort(angle, angle+N);
    memset(dp,-1,sizeof(dp));
    df(0,0);
    
    int goal;
    loop(i,K) {
        scanf("%d", &goal);
        if (!ans[goal]) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
