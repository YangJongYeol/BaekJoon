//
//  main.cpp
//  5653. 줄기세포배양
//
//  Created by carrot on 20/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int map[350][350];
int Count = 0, ans = 0, T, N, M, K;
int dir_r[] = {0,0,1,-1};
int dir_c[] = {1,-1,0,0};
struct Info {
    int r,c,e;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        for(int i=0; i<350; i++) for (int j=0; j<350; j++) map[i][j]=0;
        queue<Info> q[11];
        scanf("%d %d %d",&N,&M,&K); ans = 0;
        for (int i=0; i<N; i++)
            for (int j=0; j<M; j++) {
                scanf("%d", &map[i+150][j+150]);
                if (map[i+150][j+150]==0) continue;
                q[map[i+150][j+150]].push({i+150,j+150,2*map[i+150][j+150]});
            }
        
        while (K--) {
            for (int E=10; E>0; E--) {
                Count = (int)q[E].size();
                for (int n=0; n<Count; n++) {
                    Info inf = q[E].front(); q[E].pop();
                    
                    if (inf.e==E)
                        for (int i=0; i<4; i++) {
                            int nr = inf.r+dir_r[i];
                            int nc = inf.c+dir_c[i];
                            if (!map[nr][nc]) {
                                q[E].push({nr,nc,E*2});
                                map[nr][nc] = E;
                            }
                        }
                    if (--inf.e) q[E].push(inf);
                }
            }
        }
        
        for (int E = 10; E > 0; E--)
            ans += q[E].size();
        printf("#%d %d\n", t, ans);
    }
    return 0;
}

