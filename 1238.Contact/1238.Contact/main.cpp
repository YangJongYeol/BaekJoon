//
//  main.cpp
//  1238.Contact
//
//  Created by carrot on 11/07/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <queue>
#include <vector>
using namespace std; 
bool map[101][101];
bool visited[101];

int main(int argc, const char * argv[]) {
    // insert code here...
    
    for (int tc=1; tc<=10; tc++) {
        memset(map,0,sizeof(map));
        memset(visited,0,sizeof(visited));
        int length;
        int start;
        
        scanf("%d %d",&length, &start);
        
        vector<int> vc[101];
        int from, to;
        for (int i=0; i<length/2; i++) {
            scanf("%d %d", &from, &to);
            if (!map[from][to]) {
                map[from][to] = 1;
                vc[from].push_back(to);
            }
        }
        
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        while(!q.empty()) {
            int b = 0;
            int s = (int)q.size();
            for (int i=0; i<s; i++) {
                int t = q.front();
                q.pop();
                
                if (t > b) b = t;
                
                for (int j=0; j<vc[t].size(); j++) {
                    int tmp = vc[t][j];
                    if (!visited[tmp]) {
                        visited[tmp] = 1;
                        q.push(tmp);
                    }
                }
            }
            
            if (q.empty()) printf("#%d %d\n",tc,b);
        }
    }
    
    return 0;
}
