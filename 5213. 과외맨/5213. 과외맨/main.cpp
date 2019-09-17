//
//  main.cpp
//  5213. 과외맨
//
//  Created by carrot on 29/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
using namespace std;
int W[4][8];

bool change(int w, int d) {    // d -> 0:left 1:right
    if (d==1 && W[w][2]!=W[w+1][6]) return true;
    if (d==-1 && W[w-1][2]!=W[w][6]) return true;
    return false;
}

void move(int w, int dir, int d) {
    if (d>=0 && w!=3 && change(w,1))
        move(w+1,(-1)*dir,1);
    if (d<=0 && w!=0 && change(w,-1))
        move(w-1, (-1)*dir, -1);
    
    if (dir==1) {
        int tmp = W[w][0];
        W[w][0] = W[w][7];
        W[w][7] = W[w][6];
        W[w][6] = W[w][5];
        W[w][5] = W[w][4];
        W[w][4] = W[w][3];
        W[w][3] = W[w][2];
        W[w][2] = W[w][1];
        W[w][1] = tmp;
    } else {
        int tmp = W[w][1];
        W[w][1] = W[w][2];
        W[w][2] = W[w][3];
        W[w][3] = W[w][4];
        W[w][4] = W[w][5];
        W[w][5] = W[w][6];
        W[w][6] = W[w][7];
        W[w][7] = W[w][0];
        W[w][0] = tmp;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int K,w,dir;
    for (int i=0; i<4; i++)
        for (int j=0; j<8; j++)
            scanf(" %1d", &W[i][j]);
    
    scanf("%d", &K);
    for (int i=0; i<K; i++) {
        scanf("%d %d", &w, &dir);
        move(w-1,dir,0);
    }
    printf("%d", W[0][0]+W[1][0]*2+W[2][0]*4+W[3][0]*8);
    return 0;
}
