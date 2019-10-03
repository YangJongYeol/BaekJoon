//
//  main.cpp
//  16234. 인구 이동
//
//  Created by carrot on 02/10/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#define loop(a,b,c) for (int a=b; a<=c; a++)
using namespace std;
int N, L, R, map[51][51], group[51][51];
int dir_r[] = {0,0,1,-1}, dir_c[] = {1,-1,0,0};
struct Pos {int r,c;};
struct Info {int num, amt, cnt;};

Info bfs(int r, int c) {
    int cnt=1,amt=map[r][c];
    queue<Pos> q; q.push({r,c});
    while(!q.empty()) {
        Pos pos=q.front(); q.pop();
        loop(i,0,3) {
            int nr=pos.r+dir_r[i], nc=pos.c+dir_c[i];
            if (0>=nr||nr>N||0>=nc||nc>N) continue;
            if (group[nr][nc]==group[r][c]) continue;
            int tmp = abs(map[pos.r][pos.c]-map[nr][nc]);
            if (L<=tmp && tmp<=R) {
                group[nr][nc]=group[r][c];
                q.push({nr,nc});
                cnt++;
                amt+=map[nr][nc];
            }
        }
    }
    
    return {group[r][c],amt,cnt};
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d %d %d", &N, &L, &R);
    loop(i,1,N) loop(j,1,N) scanf("%d", &map[i][j]);
    
    // open
    int times=0;
    while(1) {
        vector<Info> vc;
        int count=1;
        loop(i,1,N) loop(j,1,N) group[i][j]=count++;
        
        count=1;
        loop(i,1,N) loop(j,1,N) {
            if (group[i][j]==count++) {
                Info inf = bfs(i,j);
                if (inf.cnt!=1)
                    vc.push_back(inf);
            }
        }
        
        if (vc.empty()) break;
        times++;
        
        loop(v,0,vc.size()-1) {
            int population = vc[v].amt/vc[v].cnt;
            loop(i,1,N) loop(j,1,N) {
                if (group[i][j]==vc[v].num) {
                    map[i][j]=population;
                }
            }
        }
    }
    
    printf("%d", times);
    return 0;
}
