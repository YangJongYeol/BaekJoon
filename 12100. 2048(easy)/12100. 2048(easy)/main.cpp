//
//  main.cpp
//  12100. 2048(easy)
//
//  Created by carrot on 26/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
using namespace std;
int N, dir_r[]={-1,1,0,0}, dir_c[]={0,0,1,-1}, ans;

void show(int (*map)[20]) {
    printf("\n");
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            printf("%d ",map[i][j]);
        printf("\n");
    }
}

void dfs(int map[20][20], int dir, int cnt) {
    if (dir==0) { // up
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++) {
                if (map[i][j]) {    // 숫자 발견
                    int r=i; int c=j;
                    do {
                        r+=dir_r[dir]; c+=dir_c[dir];
                        if (0>r || r>=N || 0>c || c>=N) {
                            r-=dir_r[dir]; c-=dir_c[dir];
                            break;
                        }
                    } while (!map[r][c]);   // 벽 또는 다른 숫자를 만날때까지 이동
                    
                    if (r==i && c==j) continue; // 이동이 없으면 pass
                    
                    if (map[r][c]) {    // 숫자를 만났는데
                        if (map[r][c]==map[i][j]) { // 그게 나랑 같다
                            map[r][c]*=2; map[r][c]*=-1;    // 합침
                        } else {                    // 그게 나랑 다르다
                            r-=dir_r[dir]; c-=dir_c[dir];
                            if (r==i && c==j) continue; // 이동이 없으면 pass
                            else
                                map[r][c]=map[i][j];  // 그 전 위치에
                        }
                    } else  // 그냥 벽이다.
                        map[r][c]=map[i][j];
                    map[i][j]=0;    // 원래 자리는 0으로
                }
            }
    } else if (dir==1) { // down
        for (int i=N-1; i>=0; i--)
            for (int j=N-1; j>=0; j--) {
                if (map[i][j]) {    // 숫자 발견
                    int r=i; int c=j;
                    do {
                        r+=dir_r[dir]; c+=dir_c[dir];
                        if (0>r || r>=N || 0>c || c>=N) {
                            r-=dir_r[dir]; c-=dir_c[dir];
                            break;
                        }
                    } while (!map[r][c]);   // 벽 또는 다른 숫자를 만날때까지 이동
                    
                    if (r==i && c==j) continue; // 이동이 없으면 pass
                    
                    if (map[r][c]) {    // 숫자를 만났는데
                        if (map[r][c]==map[i][j]) { // 그게 나랑 같다
                            map[r][c]*=2; map[r][c]*=-1;    // 합침
                        } else {                    // 그게 나랑 다르다
                            r-=dir_r[dir]; c-=dir_c[dir];
                            if (r==i && c==j) continue; // 이동이 없으면 pass
                            else
                                map[r][c]=map[i][j];  // 그 전 위치에
                        }
                    } else  // 그냥 벽이다.
                        map[r][c]=map[i][j];
                    map[i][j]=0;    // 원래 자리는 0으로
                }
            }
    } else if (dir==2) { // right
        for (int j=N-1; j>=0; j--)
            for (int i=N-1; i>=0; i--) {
                if (map[i][j]) {    // 숫자 발견
                    int r=i; int c=j;
                    do {
                        r+=dir_r[dir]; c+=dir_c[dir];
                        if (0>r || r>=N || 0>c || c>=N) {
                            r-=dir_r[dir]; c-=dir_c[dir];
                            break;
                        }
                    } while (!map[r][c]);   // 벽 또는 다른 숫자를 만날때까지 이동
                    
                    if (r==i && c==j) continue; // 이동이 없으면 pass
                    
                    if (map[r][c]) {    // 숫자를 만났는데
                        if (map[r][c]==map[i][j]) { // 그게 나랑 같다
                            map[r][c]*=2; map[r][c]*=-1;    // 합침
                        } else {                    // 그게 나랑 다르다
                            r-=dir_r[dir]; c-=dir_c[dir];
                            if (r==i && c==j) continue; // 이동이 없으면 pass
                            else
                                map[r][c]=map[i][j];  // 그 전 위치에
                        }
                    } else  // 그냥 벽이다.
                        map[r][c]=map[i][j];
                    map[i][j]=0;    // 원래 자리는 0으로
                }
            }
    } else { // left
        for (int j=0; j<N; j++)
            for (int i=0; i<N; i++) {
                if (map[i][j]) {    // 숫자 발견
                    int r=i; int c=j;
                    do {
                        r+=dir_r[dir]; c+=dir_c[dir];
                        if (0>r || r>=N || 0>c || c>=N) {
                            r-=dir_r[dir]; c-=dir_c[dir];
                            break;
                        }
                    } while (!map[r][c]);   // 벽 또는 다른 숫자를 만날때까지 이동
                    
                    if (r==i && c==j) continue; // 이동이 없으면 pass
                    
                    if (map[r][c]) {    // 숫자를 만났는데
                        if (map[r][c]==map[i][j]) { // 그게 나랑 같다
                            map[r][c]*=2; map[r][c]*=-1;    // 합침
                        } else {                    // 그게 나랑 다르다
                            r-=dir_r[dir]; c-=dir_c[dir];
                            if (r==i && c==j) continue; // 이동이 없으면 pass
                            else
                                map[r][c]=map[i][j];  // 그 전 위치에
                        }
                    } else  // 그냥 벽이다.
                        map[r][c]=map[i][j];
                    map[i][j]=0;    // 원래 자리는 0으로
                }
            }
    }
    
    for (int i=0; i<N; i++) for (int j=0; j<N; j++) if (map[i][j]<0) map[i][j]*=-1;
    
    int tmp[20][20];
    for (int i=0; i<N; i++) for (int j=0; j<N; j++)
        tmp[i][j] = map[i][j];
    
    if (cnt==5) {
        for (int i=0; i<N; i++) for (int j=0; j<N; j++)
            if (map[i][j]>ans) ans=map[i][j];
        return;
    } else {
        for (int i=0; i<N; i++) for (int j=0; j<N; j++)
            if (map[i][j]>ans) ans=map[i][j];

        for (int i=0; i<4; i++) {
            dfs(map,i,cnt+1);
            for (int i=0; i<N; i++) for (int j=0; j<N; j++)
                map[i][j] = tmp[i][j];
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d",&N); int map[20][20], tmp[20][20]; ans=0;
    for (int i=0; i<N; i++) for (int j=0; j<N; j++) {
        scanf("%d",&map[i][j]);
        tmp[i][j]=map[i][j];
    }
    for (int i=0; i<4; i++) {
        dfs(map, i, 1);
        for (int j=0; j<N; j++) for (int k=0; k<N; k++) map[j][k]=tmp[j][k];
    }
    printf("%d",ans);
    return 0;
}
