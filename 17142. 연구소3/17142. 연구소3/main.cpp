//
//  main.cpp
//  17142. 연구소3
//
//  Created by carrot on 01/10/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <queue>
#include <bitset>
#include <cstring>
#define loop(i) for(int i=0; i<N; i++)
#define MAX 1000000
using namespace std;
int N,M,map[50][50], v[10][2], vIdx, ans, dir_r[]={0,0,1,-1}, dir_c[]={1,-1,0,0}, amt;
bool visited[50][50];
struct Pos {int r,c;};

//bool is_finished() {
//    loop(i) loop(j)
//        if (map[i][j]==0 && !visited[i][j])
//            return false;
//    return true;
//}

void check(int selection) {
//    cout <<bitset<10>(selection)<<endl;
//    memset(visited,0,sizeof(visited));
    loop(i) loop(j) visited[i][j]=false;
    if (ans==0) return;

    queue<Pos> q;
    for (int i=0; i<vIdx; i++)
        if (selection&(1<<i)) {q.push({v[i][0],v[i][1]}); visited[v[i][0]][v[i][1]]=true;}
    
    int t=0, cnt=0;
    while(!q.empty()) {
        t++; int size = (int)q.size();
        for (int j=0; j<size; j++) {
            Pos pos = q.front(); q.pop();
            for (int k=0; k<4; k++) {
                int nr=pos.r+dir_r[k]; int nc=pos.c+dir_c[k];
                if (0>nr || nr>=N || 0>nc || nc>=N) continue;
                if (visited[nr][nc] || map[nr][nc]==1) continue;
                visited[nr][nc]=true; q.push({nr,nc}); cnt++;
            }
        }

        if (cnt==amt-M) {
//        if (is_finished()) {
            if (ans>t)
                ans=t;
            break;
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d %d", &N, &M); ans=MAX; amt=0;
    loop(i) loop(j) {
        scanf("%d", &map[i][j]);
        if (map[i][j]==2) {
            v[vIdx][0]=i;
            v[vIdx++][1]=j;
            amt++;
        }
        if (map[i][j]==0) amt++;
    }
    
//    if (is_finished()) {printf("0"); return 0;}
    if (amt==0) {printf("0"); return 0;}
    
    // select
    queue<pair<int,int>> q;
    for (int i=0; i<vIdx; i++)
        q.push(make_pair(1<<i,1));
    
    while(!q.empty()) {
        pair<int,int> p = q.front(); q.pop();
        for (int j=0; j<vIdx; j++) {
            if (p.first&(1<<j)) break;
            if (p.second+1==M) {check(p.first|(1<<j));}
            else q.push(make_pair(p.first|(1<<j),p.second+1));
        }
    }
    
    printf("%d", (ans==MAX?-1:ans));
    return 0;
}
