//
//  main.cpp
//  1976. 여행 가자
//
//  Created by carrot on 19/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
using namespace std;
int N,M,cities[201],is_connected;

int find(int x) {
    if (cities[x]==x) return x;
    else {
        int p = find(cities[x]);
        cities[x]=p;
        return p;
    }
}

void union_set(int x, int y) {
    x=find(x); y=find(y);
    cities[y]=x;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d",&N); scanf("%d",&M);
    for (int i=1; i<=N; i++) cities[i]=i;
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) {
        scanf("%d",&is_connected);
        if (is_connected) union_set(i,j);
    }
    
    int root, tmp;
    scanf("%d", &tmp); root=find(tmp);
    for (int i=0; i<M-1; i++) {
        scanf("%d", &tmp);
        if (find(tmp)!=root) {
            printf("NO"); return 0;
        }
    }
    
    printf("YES");
    return 0;
}
