//
//  main.cpp
//  4195. 친구 네트워크
//
//  Created by carrot on 19/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;
int T, F, friends[200001], idx;
char a[21],b[21];

int find(int x) {
    if (friends[x]==x) return x;
    else {
        int p = find(friends[x]);
        friends[x] = p;
        return p;
    }
}

void union_set(int x, int y) {
    x = find(x); y = find(y);
    friends[y] = x;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d",&T);
    for (int t=1; t<=T; t++) {
        map<string,int> m; idx=1;
        scanf("%d", &F); for (int i=1; i<=2*F; i++) friends[i]=i;
        for (int i=0; i<F; i++) {
            scanf("%s %s", a, b);
            if (!m.count(a)) m.insert(make_pair(a,idx++));
            if (!m.count(b)) m.insert(make_pair(b,idx++));
            int x = m.at(a); int y = m.at(b);
            union_set(x,y);
            
            int group = find(x); int size = 0;
            for (int j=0; j<=idx; j++) if (find(j)==group) size++;
            printf("%d\n",size);
        }
    }
    return 0;
}
