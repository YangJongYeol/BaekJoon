//
//  main.cpp
//  5653. 줄기세포배양(1)
//
//  Created by carrot on 2019/10/16.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#define loop(a,b) for(int a=0; a<b; a++)
using namespace std;
int T,N,M,K,ans,dir_r[]={-1,0,1,0}, dir_c[]={0,1,0,-1};
struct Cell { int r,c,life,cur; bool isActive; };
set<pair<int,int>> map;

bool comp(const Cell &a, const Cell &b) {
    return (a.life>b.life?true:false);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int test_case=1; test_case<=T; test_case++) {
        cin >> N >> M >> K; ans=0; map.clear();
        vector<Cell> first; queue<Cell> cells;
        
        int num;
        loop(i,N) loop(j,M) {
            cin >> num;
            if (num) {
                // 1. 초기 비활성화
                cells.push({i,j,num,num,false});
                map.insert(make_pair(i,j));
            }
        }
        
        loop(k,K) {
            cout << (int)cells.size() << " -> ";
            
            int size = (int)cells.size();
            loop(i,size) {
                Cell cell = cells.front(); cells.pop();
                cell.cur--;
                if (!cell.isActive) {
                    if (cell.cur) { cells.push(cell); }
                    else {
                        // 2. X시간 동안 비활성화 -> 활성화
                        cell.isActive=true; cell.cur=cell.life;
                        cells.push(cell);
                    }
                } else {
                    if (cell.life-cell.cur==1) {
                        // 5. 활성화된 세포는 첫 1시간동안 번식
                        loop(j,4) {
                            int nr=cell.r+dir_r[j], nc=cell.c+dir_c[j];
                            if (map.count(make_pair(nr,nc))) continue;  // 7. 번식하려는 곳에 줄기 세포가 있는 경우 추가 번식 X
                            first.push_back({nr,nc,cell.life,cell.life,false});
                        }
                    }
                    if (cell.cur)
                        cells.push(cell);
                    // 3. X시간 동안 활성화 -> 죽음
                    // 4. 죽으면 해당 그리드 셀 차지
                }
            }
            
            if(!first.empty()) {
                // 8. 동시에 번식하려는 경우 생명력이 가장 높은 놈이 차지한다.
                sort(first.begin(), first.end(), comp);
                loop(i,(int)first.size()) {
                    if (map.count(make_pair(first[i].r,first[i].c))) continue;
                    map.insert(make_pair(first[i].r,first[i].c));
                    cells.push(first[i]);
                }
                first.clear();
            }
            
            cout << (int)cells.size() << endl;
        }
        
        cout << "#" << test_case << " " << (int)cells.size() << "\n";
    }
    return 0;
}
