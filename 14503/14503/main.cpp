//
//  main.cpp
//  14503
//
//  Created by 양종열 on 2018. 4. 12..
//  Copyright © 2018년 양종열. All rights reserved.
//

/*
 1. 현재 위치를 청소한다.
 2. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
 3. 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
 4. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
 5. 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
 6. 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
 */

#include <iostream>
using namespace std;

int map[50][50];    // 0: 안간곳, 1: 벽, 2: 청소한곳
int cNum = 0;

bool checkGo(int r, int c) {
    if (map[r][c] == 0) {
        return true;
    }
    
    return false;
}

bool isWall(int r, int c) {
    if (map[r][c] == 1) {
        return true;
    }
    
    return false;
}

void dfs(int r, int c, int direction, int trial) {
    //cout<<"r: "<<r<<" c: "<<c<<endl;
    if (trial == 4) {
        switch (direction) {    // 후진
            case 0: // 북 -> 남
                if(!isWall(r+1, c)) { dfs(r+1, c, 0, 0); }
                break;
                
            case 1: // 동 -> 서
                if(!isWall(r, c-1)) { dfs(r, c-1, 1, 0); }
                break;
                
            case 2: // 남 -> 북
                if(!isWall(r-1, c)) { dfs(r-1, c, 2, 0); }
                break;
                
            case 3: // 서 -> 동
                if(!isWall(r, c+1)) { dfs(r, c+1, 3, 0); }
                break;
        }
        
        return;
    }
    
    if (map[r][c] == 0) {
        map[r][c] = 2;
        cNum++;
        //cout<<cNum<<endl;
    }
    
    
    switch (direction) {
        case 0: // 북 -> 서
            if (checkGo(r, c-1)) { dfs(r, c-1, 3, 0); }
            else {
                trial += 1;
                dfs(r, c, 3, trial);
                
            }
            break;
            
        case 1: // 동 -> 북
            if (checkGo(r-1, c)) { dfs(r-1, c, 0, 0); }
            else {
                trial += 1;
                dfs(r, c, 0, trial);
            }
            break;
            
        case 2: // 남 -> 동
            if (checkGo(r, c+1)) { dfs(r, c+1, 1, 0); }
            else {
                trial += 1;
                dfs(r, c, 1, trial);
            }
            break;
            
        case 3: // 서 -> 남
            if (checkGo(r+1, c)) { dfs(r+1, c, 2, 0); }
            else {
                trial += 1;
                dfs(r, c, 2, trial);
            }
            break;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false);
    
    int n,m;
    cin>>n>>m;
    
    int r,c,direction;
    cin>>r>>c>>direction;
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin>>map[i][j];
        }
    }
    
    
    
    dfs(r,c,direction,0);
    
    
    cout<<cNum;
    return 0;
}
