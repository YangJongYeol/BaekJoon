//
//  main.cpp
//  4013. 특이한 자석
//
//  Created by carrot on 22/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
int T, K, ans;
int num, ro;
int a[5][8];

void rotate(int num, int ro, int dir) {
    if (dir<=0 && num-1>0 && a[num-1][2]!=a[num][6])
        rotate(num-1, ro*(-1), -1);
    if (dir>=0 && num+1<5 && a[num+1][6]!=a[num][2])
        rotate(num+1, ro*(-1), 1);
    
    int tmp = a[num][0];
    int index = 0;
    for (int i=0; i<7; i++) {
        a[num][index] = a[num][(index-ro+8)%8];
        index = (index-ro+8)%8;
    }
    a[num][index] = tmp;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        scanf("%d", &K); ans=0;
        for (int i=1; i<=4; i++)
            for (int j=0; j<8; j++)
                scanf("%d", &a[i][j]);
        
        for (int i=0; i<K; i++) {
            scanf("%d %d", &num, &ro);
            rotate(num,ro,0);
        }
        
        for (int i=1; i<=4; i++)
            ans += (a[i][0]==1? pow(2,i-1):0);
        printf("#%d %d\n",t,ans);
    }
    
    return 0;
}
