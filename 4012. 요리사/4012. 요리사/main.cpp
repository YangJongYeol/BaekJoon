//
//  main.cpp
//  4012. 요리사
//
//  Created by carrot on 21/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
int T, N, map[16][16];
int foods[2][8];
long long ans;

void cal(int a) {
    int f0=0, f1=0;
    for (int i=0; i<N; i++) {
        if (a&(1<<i)) foods[0][f0++]=i;
        else foods[1][f1++]=i;
    }
    
    int s0=0, s1=0;
    for (int i=0; i<f0; i++)
        for (int j=i+1; j<f0; j++)
            s0 = s0 + map[foods[0][i]][foods[0][j]] + map[foods[0][j]][foods[0][i]];
    for (int i=0; i<f1; i++)
        for (int j=i+1; j<f1; j++)
            s1 = s1 + map[foods[1][i]][foods[1][j]] + map[foods[1][j]][foods[1][i]];
    
    long long tmp = abs(s0-s1);
    if (ans>tmp) ans=tmp;
}

void food(int a, int num) {
    if (num==N/2) {
        cal(a);
        return;
    }
    
    for (int i=0; i<N; i++) {
        if (a&(1<<i)) break;
        food(a|(1<<i),num+1);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        scanf("%d", &N); ans=10000000;
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                scanf("%d", &map[i][j]);
        
        for (int i=0; i<N; i++) {
            int a = 1<<i;
            food(a,1);
        }
        
        printf("#%d %lld\n",t,ans);
    }
    
    return 0;
}
