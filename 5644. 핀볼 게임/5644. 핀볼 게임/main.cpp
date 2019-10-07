//
//  main.cpp
//  5644. 핀볼 게임
//
//  Created by carrot on 07/10/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#define loop(a,b) for(int a=0; a<b; a++)
using namespace std;
int ans, T, N, map[100][100], dir_r[]={-1,1,0,0}, dir_c[]={0,0,1,-1};
vector<pair<int,int>> hole[11];
int block[6][4] = {
    {-1,-1,-1,-1},
    {1,2,3,0},
    {2,0,3,1},
    {3,0,1,2},
    {1,3,0,2},
    {1,0,3,2}
};

void move(int r, int c, int dir) {
    int nr=r, nc=c, cnt=0;;
    do {
        nr += dir_r[dir];
        nc+=dir_c[dir];
        
        // wall
        if (0>nr||nr>=N||0>nc||nc>=N) {
            cnt++;
            dir=block[5][dir];
        }
        // block
        else if (1<=map[nr][nc] && map[nr][nc]<=5) {
            cnt++;
            dir=block[map[nr][nc]][dir];
        }
        
        // hole
        else if (map[nr][nc]>=6) {
            int h=map[nr][nc];
            if (hole[h][0].first==nr && hole[h][0].second==nc) {
                nr=hole[h][1].first; nc=hole[h][1].second;
            } else {
                nr=hole[h][0].first; nc=hole[h][0].second;
            }
        }
        
        if (nr==r && nc==c) break;
    } while (map[nr][nc]!=-1);
    
    if (ans<cnt)
        ans=cnt;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        memset(map,0,sizeof(map));
        loop(i,11) hole[i].clear();
        scanf("%d", &N); ans=0;
        loop(i,N) loop(j,N) {
            scanf("%d", &map[i][j]);
            if (map[i][j]>=6) {
                hole[map[i][j]].push_back(make_pair(i,j));
            }
        }
        
        loop(i,N) loop(j,N) if(map[i][j]==0) {
            loop(k,4) move(i,j,k);
        }
        
        printf("#%d %d\n",t,ans);
    }
    return 0;
}
