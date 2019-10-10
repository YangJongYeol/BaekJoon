//
//  main.cpp
//  10026. 적록색약
//
//  Created by carrot on 07/10/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <queue>
#define loop(a,b,c) for(int a=b; a<c; a++)
using namespace std;
int N,ans[2],dir_r[]={1,-1,0,0},dir_c[]={0,0,1,-1}; char map[100][100]; bool visited[100][100][2];

void bfs(int r, int c, int type) {
    visited[r][c][type]=true;
    
    queue<pair<int,int>> q;
    q.push(make_pair(r,c));
    while(!q.empty()) {
        pair<int,int> p=q.front(); q.pop();
        loop(i,0,4) {
            int nr=p.first+dir_r[i], nc=p.second+dir_c[i];
            if (0>nr||nr>=N||0>nc||nc>=N) continue;
            if (visited[nr][nc][type]) continue;
            if (map[nr][nc]!=map[r][c]) continue;
            visited[nr][nc][type]=true;
            q.push(make_pair(nr,nc));
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d", &N);
    loop(i,0,N) loop(j,0,N) scanf(" %1c",&map[i][j]);
    loop(i,0,N) loop(j,0,N) if(!visited[i][j][0]) {ans[0]++; bfs(i,j,0);}
    loop(i,0,N) loop(j,0,N) if(map[i][j]=='R') map[i][j]='G';
    loop(i,0,N) loop(j,0,N) if(!visited[i][j][1]) {ans[1]++; bfs(i,j,1);}
    
    printf("%d %d",ans[0],ans[1]);
    return 0;
}
