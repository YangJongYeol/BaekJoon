//
//  main.cpp
//  1252. 단순도금비용
//
//  Created by carrot on 02/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <stdio.h>
using namespace std;
int map[100][100], Cost[4], AnsCnt, Answer[10000][3];
int S, N;
//1:2, 2:4, 3:7

struct gild_type {
    int row, col, cnt;
};

int countDamage(int row, int col, int size) {
    int cnt=0;
    for (int i=row; i<row+size; i++)
        for (int j=col; j<col+size; j++)
            if (map[i][j]==1) cnt++;
    
    return cnt;
}

gild_type findOptimal(int row, int col, int size, int gildSize) {
    int maxCnt = 0, maxR = -1, maxC = -1;
    for (int i=row; i<=row+size-gildSize; i++) {
        for (int j=col; j<=col+size-gildSize; j++) {
            int cnt = countDamage(i, j, gildSize);
            if (cnt > maxCnt) {
                maxCnt = cnt;
                maxR = i;
                maxC = j;
            }
        }
    }
    
    return {maxR, maxC, maxCnt};
}

void setMark(int row, int col, int size, int curValue, int newValue) {
    for (int i=row; i<row+size; i++)
        for (int j=col; j<col+size; j++)
            if (map[i][j]==curValue)
                map[i][j] = newValue;
}

int solve(int row, int col, int size, int gildSize, bool first) {
    int sumCost = 0, cost1, cost2;
    while (gildSize > 1) {
        gild_type gild1 = findOptimal(row, col, size, gildSize);
        if (gild1.cnt == 0) break;
        cost1 = Cost[gildSize];
        
        if (first && gildSize==3 && gild1.cnt <= 6) {
            int totalCost1 = solve(row, col, size, 3, false);
            int totalCost2 = solve(row, col, size, 2, false);
            if (totalCost2<totalCost1) {
                gildSize = 2;
                continue;
            }
        }
        
        cost2 = 0;
        if (gildSize > 2) {
            gild_type gild2 = findOptimal(gild1.row, gild1.col, gildSize, gildSize-1);
            cost2 = Cost[gildSize-1];
            setMark(gild2.row, gild2.col, gildSize-1, 1, 2);
            
            gild_type gild3;
            do {
                gild3 = findOptimal(gild1.row, gild1.col, gildSize, 2);
                if (gild3.cnt > 1) {
                    cost2 += Cost[2];
                    setMark(gild3.row, gild3.col, 2, 1, 2);
                }
            } while (gild3.cnt > 1);
        }
        
        cost2 += Cost[1] * countDamage(gild1.row, gild1.col, gildSize);
        setMark(gild1.row, gild1.col, gildSize, 2, 1);
        
        if (cost1 <= cost2) {
            setMark(gild1.row, gild1.col, gildSize, 1, first? 3:4);
            sumCost += cost1;
            
            if (first){
                Answer[AnsCnt][0] = gild1.row+1;
                Answer[AnsCnt][1] = gild1.col+1;
                Answer[AnsCnt++][2] = gildSize;
            }
        } else  --gildSize;
    }
    for (int i=row; i<row+size; i++)
        for (int j=col; j<col+size; j++)
            if (map[i][j]==1) {
                sumCost += Cost[1];
                if (first) {
                    Answer[AnsCnt][0] = i+1;
                    Answer[AnsCnt][1] = j+1;
                    Answer[AnsCnt++][2] = 1;
                }
            }
    if (!first) setMark(row, col, size, 4, 1);
    return sumCost;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Cost[1] = 2; Cost[2] = 4; Cost[3] = 7;
    int T, r,c;
    scanf("%d", &T);
    
    for (int t=1; t<=T; t++) {
        scanf("%d",&S);
        scanf("%d",&N);
        
        for (int i=0; i<S; i++)
            for (int j=0; j<S; j++)
                map[i][j] = 0;
        
        for (int i=0; i<N; i++) {
            scanf("%d %d",&r, &c);
            map[r-1][c-1]=1;
        }
        
        AnsCnt = 0;
        solve(0,0,S,3,true);
        
        printf("#%d %d",t, AnsCnt);
        for (int i=0; i<AnsCnt; i++)
            printf(" %d %d %d", Answer[i][0], Answer[i][1], Answer[i][2]);
        printf("\n");
    }
    return 0;
}
