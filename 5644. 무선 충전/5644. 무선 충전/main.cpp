//
//  main.cpp
//  5644. 무선 충전
//
//  Created by carrot on 16/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
int T, M, A, ans;
int step[2][100];
int bc[8][4]; // r,c,range,power
int dir_r[] = {0,0,1,0,-1};
int dir_c[] = {0,-1,0,1,0};
struct Info {
    int r,c;
};
Info man1,man2;
int e[2][2][2]; // per,rank,(bc,e)
int choice() {
    for (int i=0; i<2; i++)
        for (int j=0; j<2; j++) {
            e[i][j][0] = -1;
            e[i][j][1] = 0;
        }
    
    for (int i=0; i<A; i++) {
        int dist1 =abs(man1.r-bc[i][0])+abs(man1.c-bc[i][1]);
        if (dist1<=bc[i][2]) {
            if (e[0][0][1] < bc[i][3]) {
                e[0][1][0] = e[0][0][0];
                e[0][1][1] = e[0][0][1];
                
                e[0][0][0] = i;
                e[0][0][1] = bc[i][3];
            } else if (e[0][1][1] < bc[i][3]) {
                e[0][1][0] = i;
                e[0][1][1] = bc[i][3];
            }
        }
        
        int dist2 = abs(man2.r-bc[i][0])+abs(man2.c-bc[i][1]);
        if (dist2<=bc[i][2]) {
            if (e[1][0][1] < bc[i][3]) {
                e[1][1][0] = e[1][0][0];
                e[1][1][1] = e[1][0][1];
                
                e[1][0][0] = i;
                e[1][0][1] = bc[i][3];
            } else if (e[1][1][1] < bc[i][3]) {
                e[1][1][0] = i;
                e[1][1][1] = bc[i][3];
            }
        }
    }
    
    int amt = 0;
    if (e[0][0][0]!=e[1][0][0])                 // 두 첫번째가 다른 경우
        amt = e[0][0][1] + e[1][0][1];
    else                                        // 두 첫번째가 같은데
//        if (e[0][1][0]==0 && e[1][1][0]==0)         // 두 번째가 없을 경우
//            amt = e[0][0][1];
//        else
        if (e[0][1][1] > e[1][1][1])            // man12 > man 22
            amt = e[1][0][1] + e[0][1][1];          // man21 + man12
        else                                   // man22 > man 12
            amt = e[0][0][1] + e[1][1][1];          // man11 + man22
    
    return amt;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        ans = 0;
        man1 = {1,1};
        man2 = {10,10};
        scanf("%d %d", &M, &A);
        for (int i=0; i<M; i++)
            scanf("%d", &step[0][i]);
        for (int i=0; i<M; i++)
            scanf("%d", &step[1][i]);
        
        for (int i=0; i<A; i++)
            scanf("%d %d %d %d", &bc[i][0], &bc[i][1], &bc[i][2], &bc[i][3]);
        
        ans += choice();
        for (int i=0; i<M; i++) {
            man1.r += dir_r[step[0][i]];
            man1.c += dir_c[step[0][i]];
            man2.r += dir_r[step[1][i]];
            man2.c += dir_c[step[1][i]];
            
            int amt = choice();
//            printf("%d ", amt);
            ans += amt;
        }
        
        printf("#%d %d\n",t,ans);
    }
    
    return 0;
}
