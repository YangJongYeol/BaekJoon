//
//  main.cpp
//  17070. 파이프 옮기기1
//
//  Created by carrot on 05/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int N, map[17][17], ans;

struct Info {
    int r, c, status;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d", &N); ans=0;
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
            scanf("%d", &map[i][j]);
    
    if (map[N][N]==1) { printf("0"); return 0;}
    
    queue<Info> q;
    q.push({1,2,1});
    while(!q.empty()) {
        int size = (int)q.size();
        for (int s=0; s<size; s++) {
            Info inf = q.front(); q.pop();
            if (inf.r==N && inf.c==N) {ans++; continue;}
            // 돌리고
            if (inf.status==1) { // row
                if (inf.c<N) { // right
                    if (map[inf.r][inf.c+1]==0) {
                        q.push({inf.r,inf.c+1,1});
                    }
                }
                if (inf.r<N && inf.c<N) { // cross
                    if (map[inf.r][inf.c+1]==0 && map[inf.r+1][inf.c+1]==0 && map[inf.r+1][inf.c]==0) {
                        q.push({inf.r+1,inf.c+1,3});
                    }
                }
            } else if (inf.status==2) { // col
                if (inf.r<N) { // down
                    if (map[inf.r+1][inf.c]==0) {
                        q.push({inf.r+1,inf.c,2});
                    }
                }
                if (inf.r<N && inf.c<N) { // cross
                    if (map[inf.r][inf.c+1]==0 && map[inf.r+1][inf.c+1]==0 && map[inf.r+1][inf.c]==0) {
                        q.push({inf.r+1,inf.c+1,3});
                    }
                }
            } else { // cross
                if (inf.c<N) { // right
                    if (map[inf.r][inf.c+1]==0) {
                        q.push({inf.r,inf.c+1,1});
                    }
                    
                }
                if (inf.r<N) { // down
                    if (map[inf.r+1][inf.c]==0) {
                        q.push({inf.r+1,inf.c,2});
                    }   
                }
                if (inf.r<N && inf.c<N) { // cross
                    if (map[inf.r][inf.c+1]==0 && map[inf.r+1][inf.c+1]==0 && map[inf.r+1][inf.c]==0) {
                        q.push({inf.r+1,inf.c+1,3});
                    }
                }
                
            }
        }
    }
    
    printf("%d", ans);
    return 0;
}
