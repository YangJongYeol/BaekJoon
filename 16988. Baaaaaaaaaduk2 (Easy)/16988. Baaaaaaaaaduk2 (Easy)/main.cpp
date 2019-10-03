//
//  main.cpp
//  16988. Baaaaaaaaaduk2 (Easy)
//
//  Created by carrot on 30/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>
#define loop for(int i=0; i<N; i++) for (int j=0; j<M; j++)
using namespace std;
int N, M, map[20][20], dir_r[]={1,-1,0,0}, dir_c[]={0,0,1,-1}, ans;
bool visited[20][20];
struct Info { int r,c; };

void check() {
    memset(visited,0,sizeof(visited));
    int result = 0;
    // map을 돌면서 2를 찾는다.
    loop if (map[i][j]==2 && !visited[i][j]) {
        int amt = 1;
        queue<Info> q; q.push({i,j}); visited[i][j]=true;
        bool flag = false;
        while(!q.empty()) {
            Info inf = q.front(); q.pop();
            for (int k=0; k<4; k++) {
                int nr=inf.r+dir_r[k]; int nc=inf.c+dir_c[k];
                if (0>nr || nr>=N || 0>nc || nc>=M || visited[nr][nc] || map[nr][nc]==1) continue;
                if (map[nr][nc]==0) { flag = true; continue; }
                amt++; visited[nr][nc]=true; q.push({nr,nc});
            }
        }
        
        if (!flag)
            result += amt;
    }
    
    if (ans<result)
        ans=result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d %d", &N, &M); ans=0;
    loop scanf("%d", &map[i][j]);
    for (int one_r=0; one_r<N; one_r++) {
        for (int one_c=0; one_c<M; one_c++) {
            if (map[one_r][one_c]==2 || map[one_r][one_c]==1) continue;
            map[one_r][one_c] = 1;
            for (int two_r=one_r; two_r<N; two_r++) {
                int two_c;
                if (two_r==one_r) two_c=one_c+1;
                else two_c=0;
                
                for (; two_c<M; two_c++) {
                    if (map[two_r][two_c]==2 || map[two_r][two_c]==1) continue;
                    map[two_r][two_c] = 1;
                    check();
                    map[two_r][two_c] = 0;
                }
            }
            map[one_r][one_c] = 0;
        }
    }
    
    printf("%d", ans);
    return 0;
}
