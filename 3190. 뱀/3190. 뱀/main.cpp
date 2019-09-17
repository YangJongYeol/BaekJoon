//
//  main.cpp
//  3190. 뱀
//
//  Created by carrot on 01/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
using namespace std;
int N,K,L,t,head[2],tail[2],na,dir_h,dir_t;
int map[101][101];  // 1:apple, 2:snack, 3:snack which turn left, 4: snack which turn right
int action[100][2];
int dir_r[] = {0,1,0,-1};
int dir_c[] = {1,0,-1,0};

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d", &N); t=0;
    scanf("%d", &K);
    int r, c;
    for (int i=0; i<K; i++) {
        scanf("%d %d", &r, &c);
        map[r][c] = 1;
    }
    scanf("%d", &L);
    char d;
    for (int i=0; i<L; i++) {
        scanf("%d %c", &action[i][0], &d);
        action[i][1] = (d=='L'?0:1);
    }
    na = 0; // next action index
    
    map[1][1] = 2; dir_h=0; dir_t=0;
    head[0] = 1; head[1] = 1;
    tail[0] = 1; tail[1] = 0;
    while(1) {
        t++;
        // first head move
        head[0] += dir_r[dir_h];
        head[1] += dir_c[dir_h];
        
        // if there has apple
        if (map[head[0]][head[1]]==1) {}
        else {
            map[tail[0]][tail[1]] = 0;  // remove
            
            tail[0] += dir_r[dir_t];    // move
            tail[1] += dir_c[dir_t];
            
            if (map[tail[0]][tail[1]]==3) dir_t = (dir_t+3)%4;  // set tail direction
            else if (map[tail[0]][tail[1]]==4) dir_t = (dir_t+1)%4;
        }
        
        // check end condition
        if (map[head[0]][head[1]]>=2) break;
        if (1>head[0] || head[0]>N || 1>head[1] || head[1]>N) break;
        map[head[0]][head[1]] = 2;
        
        // finish move and do action
        if (action[na][0]==t) {
            if (action[na][1]==0) {
                map[head[0]][head[1]]=3;
                dir_h = (dir_h+3)%4;
            } else {
                map[head[0]][head[1]]=4;
                dir_h = (dir_h+1)%4;
            }
            
            if (na<L-1) na++;
        }
        
        printf("%d: head (%d,%d) / tail(%d,%d) \n", t,head[0],head[1],tail[0],tail[1]);
    }
    
    printf("%d",t);
    return 0;
}
