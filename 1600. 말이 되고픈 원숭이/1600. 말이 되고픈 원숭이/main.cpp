//
//  main.cpp
//  1600. 말이 되고픈 원숭이
//
//  Created by carrot on 03/10/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <queue>
#define loop(a,b) for(int a=0; a<b; a++)
using namespace std;
int dir_r[]={-1,0,1,0}, dir_c[]={0,1,0,-1};
int horse_r[]={-2,-1,1,2,2,1,-1,-2}, horse_c[]={1,2,2,1,-1,-2,-2,-1};
int K, W, H, ans, map[200][200];
bool visited[200][200][30];
struct Pos {int r,c,k,cnt;};

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d", &K); scanf("%d %d", &H, &W);
    if (W==1 && H==1) {printf("0"); return 0;}
    loop(i,W) loop(j,H) scanf("%d", &map[i][j]);
    queue<Pos> q; q.push({0,0,K,0}); visited[0][0][K]=true;
    while(!q.empty()) {
        Pos pos=q.front(); q.pop();
        loop(i,4) {
            int nr=pos.r+dir_r[i]; int nc=pos.c+dir_c[i];
            if (0>nr||nr>=W||0>nc||nc>=H) continue;
            if (visited[nr][nc][pos.k] || map[nr][nc]) continue;
            if (nr==W-1 && nc==H-1) {printf("%d", pos.cnt+1); return 0;}
            visited[nr][nc][pos.k]=true; q.push({nr,nc,pos.k,pos.cnt+1});
        }
        
        if (!pos.k) continue;
        loop(i,8) {
            int nr=pos.r+horse_r[i]; int nc=pos.c+horse_c[i];
            if (0>nr||nr>=W||0>nc||nc>=H) continue;
            if (visited[nr][nc][pos.k-1] || map[nr][nc]) continue;
            if (nr==W-1 && nc==H-1) {printf("%d", pos.cnt+1); return 0;}
            visited[nr][nc][pos.k-1]=true; q.push({nr,nc,pos.k-1,pos.cnt+1});
        }
    }
    
    printf("-1");
    return 0;
}
