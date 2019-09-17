//
//  main.cpp
//  연구소
//
//  Created by carrot on 13/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
using namespace std;
int N, M;
int map[8][8];
bool visited[8][8];
int v[100][2];
int vNum;
int T;
int dir_r[4] = {0,0,1,-1};
int dir_c[4] = {1,-1,0,0};

int clean() {
    int count = 0;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++) {
            if (map[i][j]==-1) {
                map[i][j]=0;
                count++;
            }
        }
    
    return count;
}

void dfs(int r, int c) {
    bool flag = true;
    
    for (int i=0; i<4; i++) {
        int nr = r+dir_r[i];
        int nc = c+dir_c[i];
        
        if (0<=nr && nr<N && 0<=nc && nc<M) {
            if (map[nr][nc]==0) {
                map[nr][nc]=-1;
                dfs(nr,nc);
                flag = false;
            }
        }
    }
    
    return;
}

int third(int r, int c) {
    int min = T-3;
    
    for (int i=r; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (map[i][j]==0) {
                map[i][j]=1;
                for (int k=0; k<vNum; k++) {
                    dfs(v[k][0],v[k][1]);
                }
                int tmp = clean();
                if (min>tmp)
                    min = tmp; // -1이 제일 적은 걸 반환
                map[i][j]=0;
                
            }
        }
    }
    
    return min;
}

int second(int r, int c) {
    int min = T;
    int t = T-1;
    for (int i=r; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (map[i][j]==0) {
                map[i][j]=1;
                int tmp=third(i,j);
                if (min>tmp)
                    min = tmp; // -1이 제일 적은 걸 반환
                t--;
                map[i][j]=0;
            }
            
            if (t==0) break;
        }
        if (t==0) break;
    }
    
    return min;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false);
    vNum = 0; T = 0;
    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j]==2) {
                v[vNum][0] = i;
                v[vNum++][1] = j;
            }
            
            if (map[i][j]==0) T++;
        }
    }
    
    int min = T-3;
    int t = T-2;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (map[i][j]==0) {
                map[i][j]=1;
                int tmp = second(i,j);
                if (min > tmp)
                    min = tmp;
                t--;
                map[i][j]=0;
            }
            
            if (t==0) break;
        }
        if (t==0) break;
    }
    
    printf("%d", T-3-min);

    return 0;
}
