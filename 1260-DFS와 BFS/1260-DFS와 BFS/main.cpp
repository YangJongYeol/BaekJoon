//
//  main.cpp
//  1260-DFS와 BFS
//
//  Created by 양종열 on 2018. 5. 11..
//  Copyright © 2018년 양종열. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n,m,v;
vector<vector<int>> vc(1001);

bool check_dfs[1001];
void dfs (int v) {
    check_dfs[v] = true;
    cout<<v<<" ";
    for (int i=0; i<vc[v].size(); i++) {
        sort(vc[v].begin(), vc[v].end());
        if (!check_dfs[vc[v][i]]) {
            dfs(vc[v][i]);
        }
    }
    
    return;
}

bool check_bfs[1001];
void bfs (int n) {
    queue<int> qu;
    qu.push(n);
    check_bfs[n] = true;
    while (!qu.empty()) {
        int v = qu.front(); qu.pop();
        
        cout<<v<<" ";
        
        for (int i=0; i<vc[v].size(); i++) {
            sort(vc[v].begin(), vc[v].end());
            if (!check_bfs[vc[v][i]]) {
                int tmp = vc[v][i];
                check_bfs[tmp] = true;
                qu.push(tmp);
            }
        }
    }
    
    return;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false);
    
    cin>>n>>m>>v;
    
    int a,b;
    for (int i=0; i<m; i++) {
        cin>>a>>b;
        vc[a].push_back(b); vc[b].push_back(a);
    }
    
    dfs(v);
    cout<<"\n";
    
    bfs(v);
    
    return 0;
}
