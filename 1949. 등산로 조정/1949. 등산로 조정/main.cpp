//
//  main.cpp
//  1949. 등산로 조정
//
//  Created by carrot on 18/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
using namespace std;
int T, N, K, ans, biggest;
int map[8][8];
int dir_r[] = {0,0,-1,1};
int dir_c[] = {1,-1,0,0};

void dfs(int r, int c, int dir, bool isK, int amt) {
    bool flag = false;
    for (int i=0; i<4; i++) {
        if ((dir==0 && i==1)||(dir==1 && i==0)||(dir==2 && i==3)||(dir==3 && i==2)) continue;
        int nr = r+dir_r[i]; int nc = c+dir_c[i];
        if ((0<=nr&&nr<N && 0<=nc&&nc<N)) {
            if (map[nr][nc]<map[r][c]) { flag = true;
                dfs(nr,nc,i,isK,amt+1);
            } else if (isK && (map[nr][nc]-K)<=(map[r][c]-1)) { flag = true;
                int tmp = map[nr][nc];
                map[nr][nc] = map[r][c]-1;
                dfs(nr,nc,i,false,amt+1);
                map[nr][nc] = tmp;
            }
        }
    }
    
    if (!flag && ans<amt) {
        ans=amt;
        return;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        ans = 0; biggest = 0;
        scanf("%d %d",&N,&K);
        
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++) {
                scanf("%d", &map[i][j]);
                if (map[i][j]>biggest) biggest = map[i][j];
            }
        
        while (biggest!=0) {
            for (int i=0; i<N; i++)
                for (int j=0; j<N; j++) {
                    if (map[i][j]==biggest)
                        dfs(i,j,-1,true,1);
                }
        }
        
        printf("#%d %d\n",t,ans);
    }
    return 0;
}
