//
//  main.cpp
//  5656. 벽돌 깨기
//
//  Created by carrot on 17/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int T, N, W, H, map[15][12], origin[15][12], ans;
int dir_r[] = {1,-1,0,0}, dir_c[] = {0,0,1,-1};

struct Info {
    int r,c,p;
};

void show() {
    printf("\n");
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) printf("%d ", map[i][j]);
        printf("\n");
    }
}

void dfs(int c, int count) {
    int r=0;
    
    while (map[r][c]==0) {
        r +=1;
        if (r==H) break;
    }
    if (r<H) {
        queue<Info> q;
        q.push({r,c,map[r][c]});
        int nr, nc;
        while (!q.empty()) {
            Info inf = q.front(); q.pop();
            map[inf.r][inf.c]=0;
            for (int i=1; i<inf.p; i++) {
                for (int j=0; j<4; j++) {
                    nr = inf.r+dir_r[j]*i; nc = inf.c+dir_c[j]*i;
                    if (0<=nr && nr<H && 0<=nc && nc<W) {
                        if (map[nr][nc]>1) q.push({nr,nc,map[nr][nc]});
                        map[nr][nc]=0;
                    }
                }
            }
        }
        
        for (int i=0; i<W; i++) {
            bool flag = false;
            for (int j=0; j<H-1; j++) {
                if (map[j][i]!=0 && map[j+1][i]==0) {
                    flag = true;
                    map[j+1][i]=map[j][i];
                    map[j][i]=0;
                }
            }
            if (flag) i--;
        }
    }
    
    if (count==N-1) {
        int amt = 0;
        for (int i=0; i<H; i++) for (int j=0; j<W; j++) if (map[i][j]!=0) amt++;
        if (amt < ans) {
//            show();
            ans = amt;
        }
        return;
    }
    
    int tmp[15][12];
    for (int i=0; i<H; i++) for (int j=0; j<W; j++) tmp[i][j] = map[i][j];
    
    for (int i=0; i<W; i++) {
        dfs(i,count+1);
        for (int j=0; j<H; j++) for (int k=0; k<W; k++) map[j][k] = tmp[j][k];
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; test_case++) {
        scanf("%d %d %d", &N, &W, &H);
        for (int i=0; i<H; i++)
            for (int j=0; j<W; j++) {
                scanf("%d", &map[i][j]);
                origin[i][j] = map[i][j];
            }
        
        ans = W*H;
        for (int i=0; i<W; i++) {
            dfs(i,0);
            for (int j=0; j<H; j++) for (int k=0; k<W; k++) map[j][k] = origin[j][k];
        }
        printf("#%d %d\n", test_case, ans);
    }
    
    return 0;
}

