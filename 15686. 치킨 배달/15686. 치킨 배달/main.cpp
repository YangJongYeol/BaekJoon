//
//  main.cpp
//  15686. 치킨 배달
//
//  Created by carrot on 06/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
int N, M, map[51][51], homes[100][2], h_idx, stores[13][2], s_idx,
    dir_r[]={0,0,1,-1}, dir_c[]={1,-1,0,0}, ans = 50000;
bool visited[51][51];

int dist(int i, int j) {
    return abs(homes[i][0]-stores[j][0]) + abs(homes[i][1]-stores[j][1]);
}

void cal(int sel) {
    int amt = 0;
    
    for (int i=0; i<h_idx; i++) {
        int tmp = 100;
        for (int j=0; j<s_idx; j++) {
            if (sel&(1<<j)) {
                tmp = (tmp>dist(i,j)?dist(i,j):tmp);
            }
        }
        amt += tmp;
    }
    
    if (amt<ans) ans=amt;
}

void select(int sel, int count) {
    if (count==M) {
        cal(sel);
        return;
    }
    
    for (int i=0; i<s_idx; i++) {
        if (sel&(1<<i)) break;
        select(sel|(1<<i),count+1);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d %d", &N, &M);
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j]==1) { homes[h_idx][0]=i; homes[h_idx++][1]=j; }
            if (map[i][j]==2) { stores[s_idx][0]=i; stores[s_idx++][1]=j; }
        }
    
    int sel=0;
    for (int i=0; i<s_idx; i++) {
        sel = 1<<i;
        select(sel,1);
    }
    
    printf("%d", ans);
    return 0;
}
