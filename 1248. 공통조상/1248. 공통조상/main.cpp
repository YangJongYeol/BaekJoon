//
//  main.cpp
//  1248. 공통조상
//
//  Created by carrot on 31/07/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
long long sub[10001];
long long p[10001];
long long b[10001];

void Cal(long long a) {
    if(a==0) return;
    else {
        sub[a]++;
        Cal(p[a]);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false); cin.tie(0);
    
    int T;
    scanf("%d", &T);
    
    for (int t=1; t<=T; t++) {
        int V, E, x, y;
        scanf("%d %d %d %d",&V, &E, &x, &y);
        memset(sub,0,sizeof(int)*V);
        memset(b,0,sizeof(long long)*V);
        
        int n,m;
        for (int i=0; i<E; i++) {
            scanf("%d %d", &n, &m);
            p[m] = n;
            
        }
        
        for (int i=1; i<=V; i++) {
            Cal(i);
        }
        
        vector<long long> vc;
        long long a=x;
        while(a!=0) {
            vc.push_back(p[a]);
            a=p[a];
        }
        
        long long b=y; bool flag = false;
        while(b!=0) {
            b=p[b];
            for (int i=0; i<vc.size(); i++) {
                if (vc[i]==b) {
                    flag = true;
                    break;
                }
            }
            
            if (flag) break;
        }
        
        printf("#%d %lld %lld\n", t, b, sub[b]);
    }
    
    return 0;
}
