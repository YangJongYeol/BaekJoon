//
//  main.cpp
//  1952. 수영장
//
//  Created by carrot on 06/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
int pay[4];
int calendar[13];
int cost;
using namespace std;

int min(int a, int b) {
    return (a<b? a:b);
}

void solve (int cur, int mCost) {
    if (cur >= 12) { cost=min(cost,mCost); return; }
    
    solve(cur+1, mCost+(calendar[cur]*pay[0]<pay[1]? calendar[cur]*pay[0]:pay[1]));
    solve(cur+3, mCost+pay[2]);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int T;
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        for (int i=0; i<4; i++)
            scanf("%d", &pay[i]);
        
        for (int i=0; i<12; i++) {
            scanf("%d", &calendar[i]);
        }
        
        cost = pay[3];
        solve(0,0);
        printf("#%d %d\n", t, cost);
    }
    return 0;
}
