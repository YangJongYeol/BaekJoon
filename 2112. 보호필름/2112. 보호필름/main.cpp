//
//  main.cpp
//  2112. 보호필름
//
//  Created by carrot on 25/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <queue>
#define loop(a,b,c) for(int a=b; a<c; a++)
using namespace std;
int T, D, W, K, film[13][20], tmp[13][20];

bool check() {
    loop(j,0,W) {
        bool flag=film[0][j], isPass=false;
        int cnt=0;
        loop(i,0,D) {
            if (flag==film[i][j]) { cnt++; if (cnt==K) {isPass=true; break;} }
            else {cnt=1; flag=film[i][j]; }
        }
        if (!isPass) return false;
    }
    return true;
}

bool inject(int comb, int ab) {
    int idx=0;
    loop(i,0,D) {
        if (comb&(1<<i)) {
            if (ab&(1<<idx)) {  // A투입
                loop(j,0,W) film[i][j]=0;
            } else { // B투입
                loop(j,0,W) film[i][j]=1;
            }
            idx++;
        }
    }
    return check();
}

bool selec(pair<int,int> p) {
    // A,B 구분해야함
    queue<int> q;
    loop(i,0,p.second) q.push(1<<i);
    
    if(inject(p.first,0)) return true;
    while(!q.empty()) {
        int comb = q.front(); q.pop();
        if (inject(p.first, comb)) return true;
        loop(i,0,p.second) {
            if (comb&(1<<i)) break;
            q.push(comb|(1<<i));
        }
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int test_case=1; test_case<=T; test_case++) {
        cin >> D >> W >> K;
        loop(i,0,D) loop(j,0,W) { cin >> film[i][j]; tmp[i][j]=film[i][j]; }
        cout << "#" << test_case << " ";
        
        // 약품을 투입하지 않아도 되면 0
        if(check()) { cout << 0 << "\n"; continue; }
        
        // 투입횟수는 최소 2회
        queue<pair<int,int> > q;
        loop(i,0,D) q.push(make_pair(1<<i,1));
        while(!q.empty()) {
            pair<int,int> p = q.front(); q.pop();
            
            if (selec(p)) { cout << p.second << "\n"; break; }
            loop(i,0,D) loop(j,0,W) { film[i][j]=tmp[i][j]; }
                
            loop(i,0,D) {
                if (p.first&(1<<i)) break;
                q.push(make_pair(p.first|(1<<i),p.second+1));
            }
        }
    }
    return 0;
}
