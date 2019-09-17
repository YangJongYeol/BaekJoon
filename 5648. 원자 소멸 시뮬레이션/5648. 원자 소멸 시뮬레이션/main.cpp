//
//  main.cpp
//  5648. 원자 소멸 시뮬레이션
//
//  Created by carrot on 15/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include<iostream>
#include<queue>
using namespace std;

int T,N;
int map[4001][4001];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

struct info{
    int x,y,d,e;
};

int main(int argc, const char * argv[]) {
    
    scanf("%d", &T);
    
    for(int t=1;t<=T;t++){
        
        scanf("%d", &N);
        int ans = 0;
        int x,y,e,d;
        queue<info> q;
        
        for(int i=0;i<N;i++){
            scanf("%d %d %d %d", &x, &y, &d, &e);
            
            x = (x+1000)*2;
            y = (y+1000)*2;
            
            map[x][y] = e;
            q.push(info{x,y,d,e});
        }
        
        while(!q.empty()){
            info cur = q.front();
            q.pop();
            
            if(cur.e < map[cur.x][cur.y]){
                ans += map[cur.x][cur.y];
                map[cur.x][cur.y] = 0;
                continue;
            }
            
            
            int nx = cur.x + dx[cur.d];
            int ny = cur.y + dy[cur.d];
            
            if(nx <0 || ny <0|| nx > 4000 || ny >4000) continue;
            
            
            if(map[nx][ny] == 0){
                map[nx][ny] = cur.e;
                q.push(info{nx,ny,cur.d,cur.e});
            }
            else{
                map[nx][ny] += cur.e;
            }
            
            map[cur.x][cur.y] = 0;
        }
        
        printf("#%d %d\n", t, ans);
    }
    return 0;
}
