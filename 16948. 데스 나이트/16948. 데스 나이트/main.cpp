//
//  main.cpp
//  16948. 데스 나이트
//
//  Created by carrot on 30/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int N, from[2], to[2];
int dir_r[]={-2,-2,0,0,2,2}, dir_c[]={-1,1,-2,2,-1,1};
struct Pos {int r,c,amt;};
bool visited[201][201];

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d", &N);
    scanf("%d %d %d %d", &from[0], &from[1], &to[0], &to[1]);
    queue<Pos> q; q.push({from[0],from[1],0}); visited[from[0]][from[1]]=true;
    while(!q.empty()) {
        Pos pos = q.front(); q.pop();
        for (int i=0; i<6; i++) {
            int nr=pos.r+dir_r[i]; int nc=pos.c+dir_c[i];
            if (0>nr || nr>=N || 0>nc || nc>=N || visited[nr][nc]) continue;
            if (nr==to[0] && nc==to[1]) { printf("%d", pos.amt+1); return 0; }
            visited[nr][nc]=true; q.push({nr,nc,pos.amt+1});
        }
    }
    
    printf("-1");
    return 0;
}
