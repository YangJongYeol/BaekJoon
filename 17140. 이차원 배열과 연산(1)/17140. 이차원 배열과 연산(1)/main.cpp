//
//  main.cpp
//  17140. 이차원 배열과 연산(1)
//
//  Created by carrot on 2019/10/16.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define loop(a,b) for(int a=0; a<b; a++)
#define MAX(A,B) (A)>(B)?(A):(B)
using namespace std;
int r,c,k,ans,arr[100][100];
int Row,Col;

bool comp (const pair<int,int> &a, const pair<int,int> &b) {
    if (a.second < b.second) return true;
    else if (a.second == b.second) {
        if (a.first < b.first) return true;
        else return false;
    } else return false;
}

void cal() {
    Row=0; Col=0;
    loop(i,100) loop(j,100) if(arr[i][j]) { Row=MAX(Row,i+1); Col=MAX(Col,j+1); }
}

void R() {
    loop(i,Row) {
        vector<pair<int,int>> vc;   // (수,등장횟수)
        loop(j,Col) {
            if (arr[i][j]==0) continue;
            // 1. 숫자별 등장횟수 저장
            // 1-1. vc에 숫자가 있다면 ++
            // 1-2. vc에 숫자가 없다면 push_back
            bool isHere=false;
            loop(k,vc.size()) if (vc[k].first==arr[i][j]) {isHere=true; vc[k].second++; break;}
            if (!isHere) vc.push_back(make_pair(arr[i][j],1));
        }
        
        // 정렬 (등장횟수 오름차순 -> 수 오름차순 , 0무시)
        sort(vc.begin(), vc.end(), comp);
        
        // 먼저 해당 라인 0으로 초기화
        loop(j,Col) arr[i][j]=0;
        // (수,등장횟수) arr에 저장
        int idx=0;
        loop(k,vc.size()) {
            arr[i][idx++]=vc[k].first;
            if (idx==100) break;
            arr[i][idx++]=vc[k].second;
            if (idx==100) break;
        }
    }
}

void C() {
    loop(j,Col) {
        vector<pair<int,int>> vc;   // (수,등장횟수)
        loop(i,Row) {
            if (arr[i][j]==0) continue;
            // 1. 숫자별 등장횟수 저장
            // 1-1. vc에 숫자가 있다면 ++
            // 1-2. vc에 숫자가 없다면 push_back
            bool isHere=false;
            loop(k,vc.size()) if (vc[k].first==arr[i][j]) {isHere=true; vc[k].second++; break;}
            if (!isHere) vc.push_back(make_pair(arr[i][j],1));
        }
        
        // 정렬 (등장횟수 오름차순 -> 수 오름차순 , 0무시)
        sort(vc.begin(), vc.end(), comp);
        
        // 먼저 해당 라인 0으로 초기화
        loop(i,Row) arr[i][j]=0;
        // (수,등장횟수) arr에 저장
        int idx=0;
        loop(k,vc.size()) {
            arr[idx++][j]=vc[k].first;
            if (idx==100) break;
            arr[idx++][j]=vc[k].second;
            if (idx==100) break;
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c >>k; Row=3; Col=3;
    loop(i,3) loop(j,3) cin >> arr[i][j];
    if (arr[r-1][c-1]==k) { cout << 0; return 0;}
    int ans=0;
    do { ans++;
        // 1. 행(Row)과 열(Col)의 수를 구한다.
        cal();
        
        // 2. 행과 열의 수 비교를 통해 연산을 결정한다.
        if (Row>=Col) R();
        else C();
        
        // 3. 연산 후 조건을 검사한다.
        // 4. 조건에 달성하면 ans 출력 후 종료
        if(arr[r-1][c-1]==k) { cout << ans; return 0; }
        
        // 5. 조건에 달성하지 못함
            // 5-1. ans!=100이면 1.으로 이동
    } while(ans!=100);
            // 5-2. ans=100이면 -1 출력 후 종료
    cout << -1;
    return 0;
}
