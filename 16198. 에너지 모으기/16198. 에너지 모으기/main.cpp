//
//  main.cpp
//  16198. 에너지 모으기
//
//  Created by carrot on 08/10/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int ans, N, w[11];

void choose(int n, int amt) {
    if (n==2) {
        if (ans<amt) ans=amt;
        return;
    }
    
    for (int i=2; i<N; i++) {
        if (w[i]==-1) continue;
        int a,b;
        for (int j=i-1; j>=1; j--) if(w[j]!=-1) { a=j; break; }
        for (int j=i+1; j<=N; j++) if(w[j]!=-1) {b=j; break; }

        int tmp=w[i];
        w[i]=-1;
        choose(n-1,amt+(w[a]*w[b]));
        w[i]=tmp;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d",&N); ans=0;
    for (int i=1; i<=N; i++) scanf("%d", &w[i]);
    choose(N,0);
    
    printf("%d",ans);
    return 0;
}
