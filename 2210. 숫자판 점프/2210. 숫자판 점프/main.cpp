//
//  main.cpp
//  2210. 숫자판 점프
//
//  Created by carrot on 17/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <queue>
#include <set>
using namespace std;
int dir_r[]={0,0,1,-1};
int dir_c[]={1,-1,0,0};
struct Info {
    int r,c,num;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    int map[5][5]; set<int> se;
    for (int i=0; i<5; i++) for (int j=0; j<5; j++) scanf("%d",&map[i][j]);

    for (int i=0; i<5; i++) for (int j=0; j<5; j++) {
        queue<Info> q;
        q.push({i,j,map[i][j]});
        for (int t=1; t<=5; t++) {
            int size = (int)q.size();
            for (int k=0; k<size; k++) {
                Info inf = q.front(); q.pop();
                for (int d=0; d<4; d++) {
                    int r = inf.r + dir_r[d]; int c = inf.c + dir_c[d];
                    if (0<=r && r<5 && 0<=c && c<5) {
                        q.push({r,c,inf.num*10+map[r][c]});
                    }
                }
            }
        }

        int size = (int)q.size();
        for (int s=0; s<size; s++) {
            se.insert(q.front().num); q.pop();
        }
    }

    printf("%d", (int)se.size());
    return 0;
}

