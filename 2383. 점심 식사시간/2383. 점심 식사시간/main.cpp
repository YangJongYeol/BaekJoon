//
//  main.cpp
//  2383. 점심 식사시간
//
//  Created by carrot on 26/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int T,N,map[10][10],times,stairs[2][2],sindex,pnum;
struct Info {
    int r, c, dis_a, dis_b;
};
Info inf[10];

void cal(int cur) {
    
}

void dfs(int cur, int count, int pnum) {
    if (count==pnum) {
        cal(cur);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d" , &T);
    for (int t=1; t<=T; t++) {
        scanf("%d", &N); times=1000000000; sindex=0; pnum=0;
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++) {
                scanf("%d", &map[i][j]);
                if (map[i][j]>1) {
                    stairs[sindex][0] = i;
                    stairs[sindex++][1] = j;
                }
                if (map[i][j]==1) inf[pnum++]={i,j,0};
            }
        
        for (int i=0; i<pnum; i++) {
            inf[i].dis_a = abs(inf[i].r-stairs[0][0])+abs(inf[i].c-stairs[0][1]);
            inf[i].dis_b = abs(inf[i].r-stairs[1][0])+abs(inf[i].c-stairs[1][1]);
        }
        
        dfs(1,1,pnum);
        dfs(0,1,pnum);
        
        printf("#%d %d\n", t, times);
    }
    
    return 0;
}
