//
//  main.cpp
//  16947. 서울 지하철 2호선
//
//  Created by carrot on 2019/10/15.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#define loop(a,b) for(int a=0; a<b; a++)
using namespace std;
int N;
vector<vector<int>> vc(3001);
struct Info {
    int now,prev,cnt;
};

void findCycle(int idx) {
    map<int,int> cycle; // idx, distance
    stack<Info> s; // now, prev
    s.push({idx,-1,0});
    while(!s.empty()) {
        Info inf=s.top(); s.pop(); cycle[inf.now]=inf.cnt;
        loop(i,vc[inf.now].size()) {
            if (vc[inf.now][i]==inf.prev) continue;
            if (cycle.count(vc[inf.now][i])) {cout << cycle[vc[inf.now][i]] << " "; return;}
            s.push({vc[inf.now][i],inf.now,inf.cnt+1});
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    
    int a,b;
    loop(i,N) { cin >> a >> b; vc[a].push_back(b); vc[b].push_back(a); }
    loop(i,N) findCycle(i+1);
    
    return 0;
}
