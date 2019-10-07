//
//  main.cpp
//  14889. 스타트와 링크
//
//  Created by carrot on 06/10/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <bitset>
#define loop(a,b) for(int a=0; a<b; a++)
#define MAX 1000000
using namespace std;
int N, num, ans, ab[20][20];

void cal(int comb) {
//    cout << bitset<4>(comb) << endl;
    int amt[2]={0,0};
    vector<int> vc[2];
    loop(i,N) {
        if (comb&(1<<i)) vc[0].push_back(i);
        else vc[1].push_back(i);
    }
    
    loop(t,2) loop(i,num) loop(j,num) {
        amt[t]+=ab[vc[t][i]][vc[t][j]];
    }
    
    int result=abs(amt[0]-amt[1]);
    if (result<ans) ans=result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d", &N); ans=MAX;
    loop(i,N) loop(j,N) scanf("%d",&ab[i][j]);
    
    num=N/2;
    queue<pair<int,int>> q;
    loop(i,N) q.push(make_pair(1<<i,1));
    while(!q.empty()) {
        pair<int,int> comb=q.front(); q.pop();
        if (comb.second==num) { cal(comb.first); continue; }
        loop(i,N) {
            if (comb.first&(1<<i)) break;
            q.push(make_pair(comb.first|(1<<i),comb.second+1));
        }
    }
    
    printf("%d",ans);
    return 0;
}
