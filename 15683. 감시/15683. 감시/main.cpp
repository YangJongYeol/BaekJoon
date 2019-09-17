//
//  main.cpp
//  15683. 감시
//
//  Created by carrot on 30/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
using namespace std;
int N,M, map[8][8], cctv[8][2], cidx, amt, ans;
int dir[6][4][4];
int dir_r[] = {0,0,-1,0,1};
int dir_c[] = {0,1,0,-1,0};

int cal() {
    int tmp=0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            //printf("%d ", map[i][j]);
            if (map[i][j]==-1) tmp++;
        }
        //printf("\n");
    }
    
    return amt-tmp;
}

void chck(int r, int c, int kind, int idx) {
    int nr, nc;
    for (int i=0; i<4; i++) {
        nr=r; nc=c;
        if (!dir[kind][idx][i]) continue;
        while (1) {
            nr+=dir_r[dir[kind][idx][i]]; nc+=dir_c[dir[kind][idx][i]];
            if (0>nr || nr>=N || 0>nc || nc>=M || map[nr][nc]==6) break;
            if (map[nr][nc]==0) map[nr][nc] = -1;
        }
    }
}

void dfs(int idx) {
    if (idx==cidx) {
        int amt = cal();
        if (amt < ans) ans = amt;
        return;
    }
    
    int r = cctv[idx][0], c = cctv[idx][1];
    int kind = map[r][c];
    int tmp[8][8];
    for (int i=0; i<4; i++) {
        if (i==2 && kind==2) break;
        for (int k=0; k<N; k++)
            for (int l=0; l<M; l++)
                tmp[k][l] = map[k][l];
        
        map[r][c]=-1;
        chck(r,c,kind,i);
        dfs(idx+1);
        
        for (int k=0; k<N; k++)
            for (int l=0; l<M; l++)
                map[k][l] = tmp[k][l];
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    dir[1][0][0] = 1; dir[1][1][0] = 2; dir[1][2][0] = 3; dir[1][3][0] = 4;
    dir[2][0][0] = 1; dir[2][0][1] = 3; dir[2][1][0] = 2; dir[2][1][1] = 4;
    dir[3][0][0] = 1; dir[3][0][1] = 2; dir[3][1][0] = 2; dir[3][1][1] = 3; dir[3][2][0] = 3; dir[3][2][1] = 4; dir[3][3][0] = 4; dir[3][3][1] = 1;
    dir[4][0][0] = 1; dir[4][0][1] = 2; dir[4][0][2] = 3; dir[4][1][0] = 2; dir[4][1][1] = 3; dir[4][1][2] = 4; dir[4][2][0] = 3; dir[4][2][1] = 4; dir[4][2][2] = 1; dir[4][3][0] = 4; dir[4][3][1] = 1; dir[4][3][2] = 2;
    dir[5][0][0] = 1; dir[5][0][1] = 2; dir[5][0][2] = 3; dir[5][0][3] = 4;
    
    scanf("%d %d", &N, &M); cidx=0; ans=0; amt=0;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j]!=0 && map[i][j]!=6) {
                cctv[cidx][0] = i; cctv[cidx++][1] = j;
            }
            if (map[i][j]!=6) amt++;
        }
    
    ans = amt;
    if (cidx==0) {printf("%d", ans); return 0;}
    dfs(0);
    
    printf("%d", ans);
    return 0;
}
