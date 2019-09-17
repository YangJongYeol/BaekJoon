//
//  main.cpp
//  1953. 탈주범 검거
//
//  Created by carrot on 27/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int T,N,M,R,C,L,ans,map[50][50];
int dir_r[] = {1,-1,0,0};
int dir_c[] = {0,0,1,-1};
int types[8][4] = {
    {-1,-1,-1,-1},  //0
    {0,1,2,3},      //1
    {0,1,-1,-1},    //2
    {-1,-1,2,3},    //3
    {2,-1,-1,1},    //4
    {-1,2,-1,0},    //5
    {-1,3,0,-1},    //6
    {3,-1,1,-1}
};
struct Info {
    int r,c,dir;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        ans=0;
        scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
        for (int i=0; i<N; i++)
            for (int j=0; j<M; j++)
                scanf("%d", &map[i][j]);
        
        queue<Info> q;
        q.push({R,C,-1});
        while(L--) {
            int size = (int)q.size();
            for (int i=0; i<size; i++) {
                Info inf = q.front();
                int type = map[inf.r][inf.c];
                q.pop();
                if (inf.dir!=-1 && types[type][inf.dir]==-1) continue;
                ans++;
                
                map[inf.r][inf.c]=0;    // 사용처리
                for (int j=0; j<4; j++) {
                    if (type==1 || j==inf.dir || inf.dir==-1) { // 파이프가 4차로거나, 들어가는 방향과 동일하거나, 처음이거나
                        int dir=types[type][j];
                        if (dir==-1) continue;
                        
                        int nr = inf.r + dir_r[dir];
                        int nc = inf.c + dir_c[dir];
                        if (0<=nr&&nr<N && 0<=nc&&nc<M) {
                            if (map[nr][nc]==0) continue;
                            q.push({nr,nc,dir});
                        }
                    }
                }
            }
        }
        
        printf("#%d %d\n", t, ans);
    }
    
    return 0;
}
