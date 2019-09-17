//
//  main.cpp
//  주사위 굴리기
//
//  Created by carrot on 13/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
int map[20][20];
int N, M, x, y, K;
int dir_x[4] = {0,0,-1,1};
int dir_y[4] = {1,-1,0,0};

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d %d %d %d %d",&N,&M,&x,&y,&K);
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            scanf("%d", &map[i][j]);

    int east=0, west=0, north=0, south=0, up=0, down=0;
    for (int i=0; i<K; i++) {
        int order;
        scanf("%d", &order);
        
        x = x+dir_x[order-1];
        y = y+dir_y[order-1];
        
        if (0<=x&&x<N&&0<=y&&y<M) {
            if (order==1) { //east
                int tmp = east;
                east = up;
                up = west;
                west = down;
                down = tmp;
            } else if (order==2) {//west
                int tmp = west;
                west = up;
                up = east;
                east = down;
                down = tmp;
            } else if (order==3) {//north
                int tmp = north;
                north = up;
                up = south;
                south = down;
                down = tmp;
            }else { //south
                int tmp = south;
                south = up;
                up = north;
                north = down;
                down = tmp;
            }
            
            if (map[x][y]==0) {
                map[x][y] = down;
            } else {
                down=map[x][y];
                map[x][y] = 0;
            }
            
            printf("%d\n", up);
        } else {
            x = x-dir_x[order-1];
            y = y-dir_y[order-1];
        }
    }
    
    return 0;
}
