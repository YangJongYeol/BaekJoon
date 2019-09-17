//
//  main.cpp
//  14502
//
//  Created by 양종열 on 2018. 4. 12..
//  Copyright © 2018년 양종열. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int map[8][8];
int copiedMap[8][8];
bool visited[8][8];
int N,M;
int maxValue = 0;
int value = 0;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

// 지도 복사
void copyMap(){
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            copiedMap[i][j] = map[i][j];
            visited[i][j] = false;
        }
    }
}

// 벽 세개 세우기
bool buildWall(int a){
    int x = a%M;
    int y = a/M;
    
    if (copiedMap[y][x] == 0) {
        copiedMap[y][x] = 1;
        return true;
    }
    
    return false;
}

// 바이러스 퍼트리기
void spreadVirus(int i, int j){
    for (int a=0; a<4; a++) {
        int i_mod = i+dx[a];
        int j_mod = j+dy[a];
        
        if (i_mod < 0 || i_mod >= N || j_mod < 0 || j_mod >= M) {
            continue;
        }
        
        if (copiedMap[i_mod][j_mod] == 0) {
            copiedMap[i_mod][j_mod] = 2;
            spreadVirus(i_mod, j_mod);
        }
    }
}


// 클린 지역 구하기
void cal(int i, int j){
    if (visited[i][j]) {
        return;
    }
    
    if (copiedMap[i][j] == 0) { value++; }
    visited[i][j] = true;
    
    for (int a=0; a<4; a++) {
        int i_mod = i+dx[a];
        int j_mod = j+dy[a];
        
        if (i_mod < 0 || i_mod >= N || j_mod < 0 || j_mod >= M) {
            return;
        }
        
        if (copiedMap[i_mod][j_mod] == 1) {
            cal(i_mod, j_mod);
        }
    }
}

void check(){
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (copiedMap[i][j] == 2) {
                spreadVirus(i, j);
            }
        }
    }
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (copiedMap[i][j] != 1)
                cal(i, j);
        }
    }
    
    if (value != 0)
        maxValue = max(value, maxValue);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false);

    cin>>N>>M;
    
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            map[i][j] = -1;
        }
    }
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin>>map[i][j];
        }
    }
    
    copyMap();
    
    for (int i=0; i<N*M; i++) {
        for (int j=i+1; j<N*M; j++) {
            for (int k=j+1; k<N*M; k++) {
                if (buildWall(i) && buildWall(j) && buildWall(k)) {
                    value = 0;
                    //cout<<i<<" "<<j<<" "<<k<<endl;
                    check();
                }
                copyMap();
            }
        }
    }
    
    cout<<maxValue;
    return 0;
}
