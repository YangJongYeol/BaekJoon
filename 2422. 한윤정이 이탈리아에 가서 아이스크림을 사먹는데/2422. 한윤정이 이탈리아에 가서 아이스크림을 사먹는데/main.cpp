//
//  main.cpp
//  2422. 한윤정이 이탈리아에 가서 아이스크림을 사먹는데
//
//  Created by carrot on 07/10/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <set>
#define loop(a,b,c) for(int a=b; a<c; a++)
using namespace std;
int N,M,ans;
set<pair<int,int>> no;

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d %d",&N,&M);
    
    int a,b;
    loop(i,0,M) {
        scanf("%d %d",&a,&b);
        if (a<b)
            no.insert(make_pair(a,b));
        else
            no.insert(make_pair(b,a));
    }
    
    
    loop(i,1,N+1) loop(j,i+1,N+1) {
        if (no.count(make_pair(i,j))) continue;
        loop(k,j+1,N+1) {
            if (no.count(make_pair(i,k)) || no.count(make_pair(j,k))) continue;
            else ans++;
        }
    }
    printf("%d", ans);
    return 0;
}
