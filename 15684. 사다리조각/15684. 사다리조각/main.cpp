//
//  main.cpp
//  15684. 사다리조각
//
//  Created by carrot on 31/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
using namespace std;
int N, M, H, ans;
int map[31][11];

bool move() {
    int r,c;
    for (int i=1; i<=N; i++) {
        c=i; r=1;
        
        while (r<=H) {
            if (map[r][c]) c++;
            else if (c!=1 && map[r][c-1]) c--;
            r++;
        }
        
        if (c!=i)
            return false;
    }
    
    return true;
}

void dfs(int r, int c, int num) {
    if (ans!=-1 && num>=ans) {return;}
    
    for (int i=r; i<=H; i++) {
        for (int j=1; j<N; j++) {
            if (map[i][j]) continue;
            if (map[i][j+1]) continue;
            if (j>1 && map[i][j-1]) continue;
            
            map[i][j] = 1;
            if (move()) { ans=num+1; map[i][j] = 0; return; }
            
            if (num<2)
                dfs(i,j,num+1);
            map[i][j] = 0;
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d %d %d", &N, &M, &H); ans=-1;
    
    int r,c;
    for (int i=0; i<M; i++) {
        scanf("%d %d", &r, &c);
        map[r][c] = 1;
    }
    
    if (move()) {printf("%d", 0); return 0;}
    for (int i=1; i<=H; i++) {
        for (int j=1; j<N; j++) {
            if (map[i][j]) continue;
            if (map[i][j+1]) continue;
            if (j>1 && map[i][j-1]) continue;
            
            map[i][j]=1;
            if (move()) {printf("%d", 1); return 0;}
            else dfs(i,j,1);
            map[i][j]=0;
        }
    }
    
    printf("%d", ans);
    
    return 0;
}
