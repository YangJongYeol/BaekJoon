//
//  main.cpp
//  1258.행렬찾기
//
//  Created by carrot on 04/07/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int map[100][100];
bool visited[100][100];
int size;
struct Block {
    long row, col; long size;
    bool operator < (const Block &other) const {
        if (size == other.size) return col < other.col;
        else return size <other.size;
    }
    
};

int Row(int x, int y, int num) {
    if (y==size) return num;
    if (map[x][y+1]==0) return num;
    return Row(x,y+1,num+1);
}

int Col(int x, int y, int num) {
    if (x==size) return num;
    if (map[x+1][y]==0) return num;
    return Col(x+1,y,num+1);
}

void check(int x, int y, int row, int col) {
    for (int i=x; i<x+col; i++) {
        for (int j=y; j<y+row; j++) {
            visited[i][j] = true;
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int t;
    scanf("%d",&t);
    for (int tc=1; tc<=t; tc++) {
        scanf("%d", &size);
        
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                scanf("%d", &map[i][j]);
                visited[i][j] = false;
            }
        }
        
        vector<Block> vc;
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                if (visited[i][j]==false && map[i][j]!=0) {
                    int row = Row(i,j,1);
                    int col = Col(i,j,1);
                    vc.push_back({row,col,row*col});
                    check(i,j,row,col);
                }
            }
        }
    
        sort(vc.begin(), vc.end());
        
        unsigned long v = vc.size();
        printf("#%d %ld ", tc, v);
        for (int i=0; i<vc.size(); i++) {
            printf("%ld %ld ", vc[i].col, vc[i].row);
        }
        printf("\n");
    }
    
    return 0;
}
