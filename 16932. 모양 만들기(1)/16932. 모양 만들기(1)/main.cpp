//
//  main.cpp
//  16932. 모양 만들기(1)
//
//  Created by carrot on 2019/10/14.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <map>
#define loop(a,b) for(int a=0; a<b; a++)
using namespace std;
int N, M, ans, cnt, m[1000][1000], dir_r[]={-1,0,1,0}, dir_c[]={0,1,0,-1};
bool visited[1000][1000];
vector<pair<int,int>> vc;
map<int,int> group;

void dfs(int r, int c, int idx) {
    cnt++;
    m[r][c]=idx;
    visited[r][c]=true;
    loop(i,4) {
        int nr=r+dir_r[i], nc=c+dir_c[i];
        if (0>nr||nr>=N||0>nc||nc>=M) continue;
        if (m[nr][nc]!=1) continue;
        if (visited[nr][nc]) continue;
        dfs(nr,nc,idx);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    loop(i,N) loop(j,M) {
        cin >> m[i][j];
        if (m[i][j]) vc.push_back(make_pair(i,j));
    }

    int idx=1;
    loop(i,vc.size()) {
        if (!visited[vc[i].first][vc[i].second]) {
            cnt = 0;
            dfs(vc[i].first, vc[i].second, idx);
            group.insert(make_pair(idx,cnt));
            idx++;
        }
    }
    
    loop(i,N) loop(j,M) {
        int amt=0; set<int> s;
        loop(t,4) {
            int nr=i+dir_r[t], nc=j+dir_c[t];
            if (0>nr||nr>=N||0>nc||nc>=M) continue;
            if (m[nr][nc]) s.insert(m[nr][nc]);
        }
        
        for (auto ite=s.begin(); ite!=s.end(); ite++)
            amt += group.at(*ite);
        amt++;
        
        if (ans<amt) ans=amt;
    }

    cout << ans;
    return 0;
}
