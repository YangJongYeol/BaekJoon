//
//  main.cpp
//  2115. 벌꿀채취
//
//  Created by carrot on 05/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
using namespace std;
int map[11][11];
int dp[1<<5][2];
int N, M, C;
struct glid_type {
    int r, c, Cost;
};

int d(int index, int maxV, int r, int c) {
    int e = (1<<M)-1;
    if (index == e) return maxV;
    
    for (int i=0; i<M; i++) {
        int newIndex = index|(1<<i);
        if (newIndex == index) continue;
        int cost = dp[index][0] + map[r][c+i];
        int value = dp[index][1] + (map[r][c+i]*map[r][c+i]);
        if (cost <= C) {
            dp[newIndex][0] = cost;
            dp[newIndex][1] = value;
            maxV = value;
        } else {
            if (dp[newIndex][1] < dp[index][1]) {
                dp[newIndex][0] = dp[index][0];
                dp[newIndex][1] = dp[index][1];
                maxV = dp[index][1];
            }
        }
        
        d(newIndex, maxV, r, c);
    }
 
    return maxV;
}

int findSubOptimal(int r, int c) {
    for (int i=0; i<(1<<M)-1; i++) {
        dp[i][0] = 0; dp[i][1] = 0;
    }
    
    int maxV = 0;
    for (int i=0; i<M; i++) {
        int index = 1<<i;
        dp[index][0] = map[r][c+i];
        dp[index][1] = map[r][c+i]*map[r][c+i];
        maxV = dp[index][1];
        
        d(index, maxV, r, c);
    }
    
    return dp[(1<<M)-1][1];
}

int findOptimal() {
    glid_type glid[2];
    glid[0].Cost = 0; glid[0].r = -1; glid[0].c = -1;
    glid[1].Cost = 0; glid[1].r = -1; glid[1].c = -1;
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N-M+1; j++) {
            int tmp = findSubOptimal(i, j);
            if (glid[1].Cost < tmp) {
                if (glid[0].Cost < tmp) {
                    if (glid[0].c <= j && j <= glid[0].c+M-1 && glid[0].r == i) {
                        glid[0].Cost = tmp;
                        glid[0].r = i; glid[0].c = j;
                    } else {
                        glid[1].Cost = glid[0].Cost;
                        glid[1].r = glid[0].r; glid[1].c = glid[0].c;
                        glid[0].Cost = tmp;
                        glid[0].r = i; glid[0].c = j;
                    }
                } else {
                    if (glid[0].c <= j && j <= glid[0].c+M-1 && glid[0].r == i) continue;
                    glid[1].Cost = tmp;
                    glid[1].r = i; glid[1].c = j;
                }
            }
        }
    
    return glid[1].Cost + glid[0].Cost;
}


void setMark() {
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int T;
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        scanf("%d %d %d", &N, &M, &C);
        
        for (int i=1; i<=N; i++)
            for (int j=1; j<=N; j++)
                scanf("%d", &map[i][j]);
        
        printf("#%d %d\n", t, findOptimal());
    }
    return 0;
}


//    for (int i=1; i<=M; i++) {
//        for (int j=c; j<=c+M-i; j++) {
//            int cost = 0, value = 0;
//            for (int k=0; k<i; k++) {
//                cost += map[r][j+k];
//                value += map[r][j+k]*map[r][j+k];
//            }
//
//            if (cost<=C && maxV<value)
//                maxV = value;
//        }
//    }
