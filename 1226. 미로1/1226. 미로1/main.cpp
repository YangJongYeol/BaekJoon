//
//  main.cpp
//  1226. 미로1
//
//  Created by carrot on 04/07/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <cstdio>
using namespace std;
int map[100][100];
bool visited[100][100];
int d_x[4] = {0,0,1,-1};
int d_y[4] = {1,-1,0,0};
int result;
void dfs(int x,  int y) {
    if (result == 1) return;
    
    visited[x][y] = true;
    
    if (map[x][y]==3) {
        result = 1;
        return;
    }
    
    for (int i=0; i<4; i++) {
        int n_x = d_x[i]+x;
        int n_y = d_y[i]+y;
        
        if(n_x >= 0 && n_x < 100 && n_y >= 0 && n_y < 100) {
            if (visited[n_x][n_y] == false && map[n_x][n_y]!=1)
                dfs(n_x,n_y);
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    for (int tc=1; tc<=10; tc++) {
        scanf("%d",&tc);
        int s_x=0, s_y=0;
        result = 0;
        for (int i=0; i<100; i++) {
            for (int j=0; j<100; j++) {
                scanf("%1d", &map[i][j]);
                visited[i][j] = false;
                if (map[i][j]==2) {
                    s_x = i; s_y = j;
                }
            }
        }
        
        dfs(s_x,s_y);
        
        printf("#%d %d\n", tc, result);
        
    }
    
    return 0;
}
