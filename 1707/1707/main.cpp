//
//  main.cpp
//  1707
//
//  Created by 양종열 on 2018. 7. 9..
//  Copyright © 2018년 양종열. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> vc(20001);
int color[20001];   // 0: not yet, 1: red, 2: blue
bool flag = false;

void dfs(int a, int ac) {
    color[a] = ac;

    for (int i=0; i<vc[a].size(); i++) {
        if (color[vc[a][i]] == 0) {
            if (color[a] == 1) {
                color[vc[a][i]] = 2;
                dfs(vc[a][i], 2);
            } else {
                color[vc[a][i]] = 1;
                dfs(vc[a][i], 1);
            }
        }
    }
    
    return;
}

bool check(int v) {
    for (int i=1; i<=v; i++) {
        for (int j=0; j<vc[i].size(); j++) {
            if (color[i] == color[vc[i][j]]) {
                return false;
            }
        }
    }
    
    return true;
}

void clean(int v) {
     for (int i=1; i<=v; i++) {
        vc[i].clear();
        color[i] = 0;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false);
    
    int K;
    cin >> K;
    
    for (int i=0; i<K; i++) {
        int V, E;
        cin >> V >> E;
        
        for (int i=0; i<E; i++) {
            int v1, v2;
            cin >> v1 >> v2;
            
            vc[v1].push_back(v2);
            vc[v2].push_back(v1);
        }
        
        for (int i=1; i<=V; i++) {
            if (color[i] == 0) {
                dfs(i, 1);
            }
        }
        
        if (check(V)) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        
        clean(V);
        cout<< endl;
    }
    return 0;
}
