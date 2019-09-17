//
//  main.cpp
//  11724
//
//  Created by 양종열 on 2018. 7. 9..
//  Copyright © 2018년 양종열. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> vc(1001);
bool visited[1001];
int cc = 0;

void dfs(int a) {
    visited[a] = true;
    bool flag = false;
    
    for (int i=0; i<vc[a].size(); i++) {
        if (!visited[vc[a][i]]) {
            flag = true;
            dfs(vc[a][i]);
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    
    int n, m;
    for (int i=0; i<M; i++) {
        cin >> n >> m;
        vc[n].push_back(m);
        vc[m].push_back(n);
    }
    
    for (int i=1; i<=N; i++) {
        if (!visited[i]) {
            dfs(i);
            cc++;
        }
    }
    
    
    cout<<cc;
    return 0;
}
