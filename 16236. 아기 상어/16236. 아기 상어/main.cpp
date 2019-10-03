//
//  main.cpp
//  16236. 아기 상어
//
//  Created by carrot on 26/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int N, map[20][20], remains, clerk, shark_size, dir_r[]={0,0,1,-1}, dir_c[]={1,-1,0,0}, eat;
pair<int,int> shark;
bool visited[20][20];
struct Info {
    int r,c,amt;
};
vector<Info> fishes[7];

bool comp(const pair<int,int>& a, const pair<int,int>& b) {
    Info infa = fishes[a.first][a.second]; Info infb = fishes[b.first][b.second];
    if (infa.r < infb.r) return true;
    else if (infa.r == infb.r) {
        if (infa.c < infb.c) return true;
        else return false;
    } else return false;
}

int dist (int a, int b) {
    int amt=0;
    memset(visited,0,sizeof(visited));
    
    // 가는길에 shark보다 큰 물고기가 있으면 돌아가야함
    // 못간다면 -1
    queue<Info> q; q.push({shark.first, shark.second, 0}); visited[shark.first][shark.second]=true;
    while(!q.empty()) {
        Info inf = q.front(); q.pop();
        for (int i=0; i<4; i++) {
            int r=inf.r+dir_r[i]; int c=inf.c+dir_c[i];
            if (0>r || r>=N || 0>c || c>=N) continue;
            if (visited[r][c] || map[r][c]>shark_size) continue;
            if (r==a && c==b) {
                amt=inf.amt+1;
                return amt;
            }
            visited[r][c]=true; q.push({r,c,inf.amt+1});
        }
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d",&N); shark_size=2; eat=0;
    for (int i=0; i<N; i++) for (int j=0; j<N; j++) {
        scanf("%d",&map[i][j]);
        if (map[i][j] && map[i][j]!=9) { fishes[map[i][j]].push_back({i,j,0}); remains++; }
        if (map[i][j]==9) {shark = make_pair(i,j);}
    }
    
    while(remains) {
        // shark보다 작은 fishes가 없다면 break
        bool is_finished = true;
        for (int i=1; i<shark_size; i++) {
            if ((int)fishes[i].size()) {is_finished=false; break;}
        }
        if (is_finished) break;
        
        // shark보다 작은 fishes의 최소 거리 구하기
        int min = 400;
        for (int i=1; i<shark_size; i++) {
            for (int j=0; j<fishes[i].size(); j++) {
                fishes[i][j].amt = dist(fishes[i][j].r, fishes[i][j].c);
                if (fishes[i][j].amt!=-1 && min>fishes[i][j].amt) min=fishes[i][j].amt;
            }
        }
        if (min==400) break; // shark보다 작은 fish는 있는데 갈 수 가 없는 경우
        
        // 최소 거리에 해당하는 fishes들의 개수 구하기
        vector<pair<int,int>> v;
        for (int i=1; i<shark_size; i++) {
            for (int j=0; j<fishes[i].size(); j++) {
                if (min==fishes[i][j].amt) {
                    v.push_back(make_pair(i,j));
                }
            }
        }
        
        Info inf; map[shark.first][shark.second]=0;
        if ((int)v.size()!=1) // 1마리이면 eat
            sort(v.begin(),v.end(),comp);
        
        inf = fishes[v[0].first][v[0].second];
        remains--; fishes[v[0].first].erase(fishes[v[0].first].begin()+v[0].second);
        map[inf.r][inf.c]=9;
        shark.first=inf.r; shark.second=inf.c;
        eat++;
        if (eat==shark_size && shark_size<8) {
            shark_size++;
            eat=0;
        }
        clerk += inf.amt;
        
//        printf("\n");
//        printf("shark size : %d\n", shark_size);
//        printf("clerk : %d\n", clerk);
//        for (int i=0; i<N; i++) {
//            for (int j=0; j<N; j++)
//                printf("%d ",map[i][j]);
//            printf("\n");
//        }
    }
    
    printf("%d",clerk);
    return 0;
}
