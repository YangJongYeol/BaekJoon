//
//  main.cpp
//  14500. 테트로미노
//
//  Created by carrot on 14/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
using namespace std;
int N, M;
long ans;
int map[500][500];
int dir_r[4] = {0,0,1,-1};
int dir_c[4] = {1,-1,0,0};

void cal(int r, int c, int br, int bc, long num, int count) {
    if (count==4) {
        if (num > ans) ans = num;
        return;
    }
    
    if (count==2) {
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                int tr1 = r+dir_r[i];
                int tc1 = c+dir_c[i];

                int tr2 = r+dir_r[j];
                int tc2 = c+dir_c[j];

                if (tr1==br && tc1==bc) continue;
                if (tr2==br && tc2==bc) continue;
                if (tr2==tr1 && tc2==tc1) continue;

                if (0<=tr1&&tr1<N&&0<=tc1&&tc1<=M) {
                    if (0<=tr2&&tr2<N&&0<=tc2&&tc2<=M) {
                        cal(-1,-1,r,c,num+map[tr1][tc1]+map[tr2][tc2],count+2);
                    }
                }
            }
        }
    }
    
    for (int i=0; i<4; i++) {
        int tr = r+dir_r[i];
        int tc = c+dir_c[i];
        if (tr==br && tc==bc) continue;
        
        if (0<=tr&&tr<N&&0<=tc&&tc<=M) {
            cal(tr,tc,r,c,num+map[tr][tc],count+1);
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ans = 0;
    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            scanf("%d", &map[i][j]);
                  
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            cal(i,j,-1,-1,map[i][j],1);
    
    printf("%ld", ans);
    
    return 0;
}
