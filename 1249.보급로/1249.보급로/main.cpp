//
//  main.cpp
//  1249.보급로
//
//  Created by carrot on 16/06/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int dir_x[4] = {0,0,1,-1};
int dir_y[4] = {1,-1,0,0};
int map[100][100];
int res[100][100];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int tc;
    scanf("%d", &tc);
    
    for (int i=1; i<=tc; i++) {
        int n;
        scanf("%d", &n);
        
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                scanf("%1d",&map[j][k]);
                res[j][k] = -1;
            }
        }
        
        queue<pair<int, int>> list;
        list.push(make_pair(0,0));
        res[0][0]=0;
        while(!list.empty()) {
            int p_x = list.front().first;
            int p_y = list.front().second;
            list.pop();
            
            for (int j=0; j<4; j++) {
                int x = p_x + dir_x[j];
                int y = p_y + dir_y[j];
                
                if ((0<=x && x<n) && (0<=y && y<n)) {
                    int tmp = res[p_x][p_y] + map[x][y];
                    if (res[x][y] == -1) {
                        res[x][y] = tmp;
                        list.push(make_pair(x,y));
                    }
                    else if ((tmp < res[x][y]) && (res[x][y] != -1)) {
                        res[x][y] = tmp;
                        list.push(make_pair(x,y));
                    }
                }
            }
        }
        
        printf("#%d %d\n",i,res[n-1][n-1]);
    }
    
    return 0;
}
