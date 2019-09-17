//
//  main.cpp
//  15685. 드래곤 커브
//
//  Created by carrot on 19/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int N,x,y,d,g;
int dir_x[] = {1,0,-1,0};
int dir_y[] = {0,-1,0,1};
bool map[101][101];
vector<int> his;

void curve() {
    for (int i=(int)his.size()-1; i>=0; i--) {
        int nd = (his[i]+3)%4; // curve
        nd = (nd+2)%4;
        his.push_back(nd);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d %d %d %d", &x, &y, &d, &g);
        his.clear();
        int nx = x+dir_x[d];
        int ny = y+dir_y[d];
        if (0<=nx&&nx<101 && 0<=ny&&ny<101) {
            map[x][y] = true; map[nx][ny] = true;
            his.push_back(d);
        }
        for (int j=1; j<=g; j++) {
            curve();
            for (int k=pow(2,j-1); k<his.size(); k++) {
                nx = nx + dir_x[his[k]];
                ny = ny + dir_y[his[k]];
                if (0<=nx&&nx<101 && 0<=ny&&ny<101) {
                    map[nx][ny] = true;
                }
            }
        }
    }
    
    int count = 0;
    for (int i=0; i<100; i++)
        for (int j=0; j<100; j++)
            if (map[i][j] && map[i][j+1] && map[i+1][j] && map[i+1][j+1]) count++;
    
    printf("%d", count);
    return 0;
}
