//
//  main.cpp
//  3184. 양
//
//  Created by carrot on 01/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int R, C, wolf, sheep;
char map[250][250];
bool checked[250][250];
int dir_r[] = {0,0,1,-1};
int dir_c[] = {1,-1,0,0};
struct Info {
    int r, c;
};

void bfs(int i, int j) {
    int w=0, o=0;
    queue<Info> q;
    q.push({i,j});
    checked[i][j] = true;
    if (map[i][j]=='v') w++;
    if (map[i][j]=='o') o++;
    
    int nr, nc, r, c;
    while (!q.empty()) {
        r = q.front().r;
        c = q.front().c;
        q.pop();
        
        for (int i=0; i<4; i++) {
            nr=r+dir_r[i]; nc=c+dir_c[i];
            if (0<=nr && nr<R && 0<=nc && nc<C) {
                if (map[nr][nc]=='#') continue;
                if (checked[nr][nc]) continue;
                
                if (map[nr][nc]=='v') w++;
                if (map[nr][nc]=='o') o++;
                
                checked[nr][nc] = true;
                q.push({nr,nc});
            }
        }
    }
    
    if (o>w)
        sheep += o;
    else
        wolf += w;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d %d", &R, &C);
    for (int i=0; i<R; i++)
        for (int j=0; j<C; j++) {
            scanf(" %1c", &map[i][j]);
            //if (map[i][j]=='v') wolf++;
            //if (map[i][j]=='o') sheep++;
        }
    
    for (int i=0; i<R; i++)
        for (int j=0; j<C; j++)
            if (map[i][j]!='#' && !checked[i][j])
                bfs(i,j);
    
    printf("%d %d", sheep, wolf);
    return 0;
}
