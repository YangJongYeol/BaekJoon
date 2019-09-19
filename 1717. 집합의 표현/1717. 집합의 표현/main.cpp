//
//  main.cpp
//  1717. 집합의 표현
//
//  Created by carrot on 19/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
using namespace std;
int n,m, type,a,b;
int set[1000001];

int find (int x) {
    if (set[x]==x) return x;
    else {
        int p = find(set[x]);
        set[x]=p;   // 조상이 가리키는걸 나도 가리키자
        return p;
    }
}

void union_set (int x, int y) {
    x=find(x);
    y=find(y);
    set[y]=x;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++) set[i]=i;
    for (int i=0; i<m; i++) {
        scanf ("%d %d %d", &type, &a, &b);
        if (!type) union_set(a, b);
        else printf("%s\n", (find(a)==find(b)?"YES":"NO"));
    }
    
    return 0;
}
