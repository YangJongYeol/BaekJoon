//
//  main.cpp
//  2019_line3
//
//  Created by carrot on 22/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int N, toilet[1001], times, idx, used;
pair<int,int> ts[1000];

bool comp(const pair<int,int> &a, const pair<int,int> &b) {
    return (a.first>b.first?false:true);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        pair<int, int> tmp; scanf("%d %d", &tmp.first, &tmp.second);
        ts[i]=tmp;
    }
    sort(ts,ts+N,comp);
    
    idx=0; used=0;
    for (times=0; times<=150; times++) {
        if (ts[idx].first==times) {
            bool flag = false;  // 화장실을 추가로 오픈할지 결정
            int open=-1;    // 쓸 수 있는 칸
            for (int j=1; j<=used; j++)
                if (toilet[j]<times) { open=j; flag=true; break; }
            
            if (!flag) {
                toilet[++used] = ts[idx].second-1;
            } else {
                toilet[open] = ts[idx].second-1;
            }
            idx++;
            times--;
        }
        
        if (idx==N)
            break;
    }
    
    printf("%d", used);
    return 0;
}
