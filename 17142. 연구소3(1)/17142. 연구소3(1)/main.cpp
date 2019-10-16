//
//  main.cpp
//  17142. 연구소3(1)
//
//  Created by carrot on 2019/10/16.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#define loop(a,b) for(int a=0; a<b; a++)
#define MAX 2500
using namespace std;
int N,M,space,map[50][50],tmp[50][50],ans,dir_r[]={-1,0,1,0},dir_c[]={0,1,0,-1};
vector<pair<int,int>> virus;
struct Info {int r,c;};
bool visited[50][50];

void move_virus(int comb) {
    int cnt=space;
    int amt=0;
    queue<Info> q;
    loop(i,(int)virus.size()) {
        if (comb&(1<<i)) {
            map[virus[i].first][virus[i].second]=2;
            q.push({virus[i].first,virus[i].second});
            visited[virus[i].first][virus[i].second]=true;
        } else {
            map[virus[i].first][virus[i].second]=3;
        }
        cnt--;
    }
    
    while(!q.empty()) {
        amt++;
        int size = (int)q.size();
        loop(t,size) {
            Info inf = q.front(); q.pop();
            loop(i,4) {
                int nr=inf.r+dir_r[i], nc=inf.c+dir_c[i];
                if (0>nr||nr>=N||0>nc||nc>=N) continue;
                if (map[nr][nc]==-1||visited[nr][nc]) continue;
                if (map[nr][nc]!=3) cnt--;
                map[nr][nc]=amt;
                q.push({nr,nc}); visited[nr][nc]=true;
            }
        }
        if (cnt==0) break;
    }
    
//    cout << "\n"; loop(i,N) { loop(j,N) cout << map[i][j] << " "; cout << "\n";}
    
    bool isAll=true;
    loop(i,N) loop(j,N) if(map[i][j]==0) isAll=false;
    if (!isAll) { /*cout << "fail!\n";*/ return; }

    if (ans>amt) ans=amt;
//    cout << "ans: " << ans << "\n";
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M; ans=MAX;
    loop(i,N) loop(j,N) {
        cin >> map[i][j];
        if (map[i][j]==2) {
            virus.push_back(make_pair(i,j));
            map[i][j]=0;
            space++;
        }
        else if (map[i][j]==0) space++;
        else map[i][j]=-1;
        
        tmp[i][j]=map[i][j];
    }
    if (space==(int)virus.size()) {cout << "0"; return 0;}
    // 활성화할 바이러스를 정하고
    queue<pair<int,int>> q;
    loop(i,(int)virus.size()) { q.push(make_pair(1<<i,1)); }
    while(!q.empty()) {
        pair<int,int> p = q.front(); q.pop();
        if (p.second==M) {
            move_virus(p.first);
            loop(i,N) loop(j,N) {
                visited[i][j]=false;
                map[i][j]=tmp[i][j];
            }
            continue;
        }
        loop(i,(int)virus.size()) {
            if (p.first&(1<<i)) break;
            q.push(make_pair(p.first|(1<<i),p.second+1));
        }
    }
    
    cout << (ans==MAX?-1:ans);
    return 0;
}
