//
//  main.cpp
//  16985. Maaaaaaaaaze
//
//  Created by carrot on 23/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int maze[5][5][5],map[5][5][5],ans,
    dir_r[] = {0,0,0,0,1,-1},
    dir_c[] = {0,0,1,-1,0,0},
    dir_h[] = {1,-1,0,0,0,0};
bool visited[5][5][5];
struct Info {
    int h,r,c,cnt;
};

void bfs() {
    for (int i=0; i<5; i++) for (int j=0; j<5; j++) for (int k=0; k<5; k++) visited[i][j][k]=false;
    queue<Info> q;
    q.push({0,0,0,0}); visited[0][0][0]=true;
    while(!q.empty()) {
        Info inf = q.front(); q.pop();
        for (int i=0; i<6; i++) {
            int nr = dir_r[i]+inf.r;
            int nc = dir_c[i]+inf.c;
            int nh = dir_h[i]+inf.h;
            
            if (0<=nr && nr<5 && 0<=nc && nc<5 && 0<=nh && nh<5) {
                if (!map[nh][nr][nc] || visited[nh][nr][nc]) continue;
                if (nr==4 && nh==4 && nc==4) {
                    if (ans>inf.cnt+1) ans=inf.cnt+1;
                    break;
                }
                q.push({nh,nr,nc,inf.cnt+1}); visited[nh][nr][nc]=true;
            }
        }
    }
}

void rotate(int board=0) {
    int tmp[5][5];
    for (int i=0; i<5; i++)
        for (int j=0; j<5; j++)
            tmp[i][j] = map[board][4-j][i];
    
    for (int i=0; i<5; i++)
        for (int j=0; j<5; j++)
            map[board][i][j] = tmp[i][j];
}

void pile(vector<int> vc={0,1,2,3,4}) {
    do {
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                for (int k=0; k<5; k++)
                    map[i][j][k] = maze[vc[i]][j][k];
            }
        }
        
        for (int i=0; i<4; i++) {
            rotate(0);
            if (!map[0][0][0]) continue;
            for (int j=0; j<4; j++) {
                rotate(1);
                for (int k=0; k<4; k++) {
                    rotate(2);
                    for (int m=0; m<4; m++) {
                        rotate(3);
                        for (int n=0; n<4; n++) {
                            rotate(4);
                            if (map[4][4][4]) bfs();
                        }
                    }
                }
            }
        }
    } while (next_permutation(vc.begin(), vc.end()));
    
    bfs();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    for (int i=0; i<5; i++) for (int j=0; j<5; j++) for (int k=0; k<5; k++) {
        scanf("%d",&maze[i][j][k]);
        map[i][j][k] = maze[i][j][k];
    }
    ans=300;
    // 1.각 판 회전하기
    pile();
//    for (int i=0; i<3; i++) {
//        printf("\n");
//        for (int j=0; j<5; j++) {
//            for (int k=0; k<5; k++)
//                printf("%d",maze[0][j][k]);
//            printf("\n");
//        }
//        rotate();
//    }
        
    printf("%d",(ans==300?-1:ans));
    return 0;
}
