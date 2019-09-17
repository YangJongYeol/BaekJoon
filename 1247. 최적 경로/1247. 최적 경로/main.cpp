//
//  main.cpp
//  1247. 최적 경로
//
//  Created by carrot on 29/07/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector<pair<int, int>> vc;
int dist[12][12];
int e, n;
int ans;

int tsp (int current, int visited) {
    int ret = 20000;
    
    if (visited == e) return dist[current][n+1];
    
    for (int i=1; i<=n; i++) {
        if(visited&(1<<i)) continue;
            // visited의 i번째 bit가 1이면 true
        ret = min(ret, tsp(i,visited|(1<<i))+dist[current][i]);
                                // visited의 i번째 bit를 1로 킨다.
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false); cin.tie(0);
    
    int T;
    scanf("%d",&T);
    
    for (int t=1; t<=T; t++) {
        memset(dist, 0, sizeof(dist));
        vc.clear();
        scanf("%d",&n);
        
        e = (1<<(n+1))-1;
        
        int x, y;
        scanf("%d %d", &x, &y);
        vc.push_back(make_pair(x,y));
        
        int x_home, y_home;
        scanf("%d %d", &x_home, &y_home);
        
        for (int i=0; i<n; i++) {
            scanf("%d %d", &x, &y);
            vc.push_back(make_pair(x,y));
        }
        
        vc.push_back(make_pair(x_home, y_home));
        
        for (int i=0; i<n+2; i++) {
            for (int j=0; j<n+2; j++) {
                dist[i][j] = abs(vc[i].first-vc[j].first)+abs(vc[i].second-vc[j].second);
            }
        }
        
        printf("#%d %d\n", t, tsp(0,1));
    }
    return 0;
}
