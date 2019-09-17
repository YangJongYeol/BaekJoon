//
//  main.cpp
//  12869. 뮤탈리스크
//
//  Created by carrot on 21/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
using namespace std;
int N, scv[3];
int dp[61][61][61];
int m[6][3] = {
    {9,3,1}, {9,1,3}, {3,9,1},
    {3,1,9}, {1,9,3}, {1,3,9}
};

void d(int x, int y, int z) {
    if (x==0 && y==0 && z==0)
        return;
    
    int nx=x; int ny=y; int nz=z;
    for (int i=0; i<6; i++)  {
        nx = x-m[i][0]; ny = y-m[i][1]; nz = z-m[i][2];
        if (nx<0) nx=0; if (ny<0) ny=0; if (nz<0) nz=0;
        
        if (!dp[nx][ny][nz]) {
            dp[nx][ny][nz]=dp[x][y][z]+1;
        } else {
            if (dp[nx][ny][nz]<=dp[x][y][z]+1) continue;
            dp[nx][ny][nz] = dp[x][y][z]+1;
        }
        d(nx,ny,nz);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", &scv[i]);
    
    dp[scv[0]][scv[1]][scv[2]]=0;
    d(scv[0],scv[1],scv[2]);
    
    printf("%d", dp[0][0][0]);
    return 0;
}
