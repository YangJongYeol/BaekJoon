//
//  main.cpp
//  14442. 벽 부수고 이동하기2
//
//  Created by carrot on 02/10/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <queue>
#define loop(a,b) for (int a=1; a<=b; a++)
using namespace std;
int dir_r[]={1,-1,0,0}, dir_c[]={0,0,1,-1};
int N,M,K,ans,map[1001][1001];
bool visited[1001][1001][11];
struct Pos {int r,c,k;};

int main(int argc, const char * argv[]) {
    scanf("%d %d %d", &N, &M, &K); ans=0;
    if (N==1 && M==1) {printf("1"); return 0;}
    
    loop(i,N) loop(j,M) scanf(" %1d", &map[i][j]);
    int times=0; queue<Pos> q; visited[1][1][K]=true; q.push({1,1,K});
    while(!q.empty()) {
        times++; int size=(int)q.size();
        for (int i=0; i<size; i++) {
            Pos pos = q.front(); q.pop();
            for (int j=0; j<4; j++) {
                int nr=pos.r+dir_r[j]; int nc=pos.c+dir_c[j];
                if (nr==N && nc==M) {printf("%d",times+1); return 0;}
                if (0>=nr||nr>N||0>=nc||nc>M||visited[nr][nc][pos.k]) continue;
                if (map[nr][nc]==1) {
                    if (pos.k) {
                        visited[nr][nc][pos.k-1]=true;
                        q.push({nr,nc,pos.k-1});
                    }
                } else {
                    visited[nr][nc][pos.k]=true;
                    q.push({nr,nc,pos.k});
                }
            }
        }
        
    }
    
    printf("-1");
    return 0;
}
