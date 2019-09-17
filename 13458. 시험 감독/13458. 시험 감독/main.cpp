//
//  main.cpp
//  13458. 시험 감독
//
//  Created by carrot on 05/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int N,B,C;
long ans;

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d", &N);
    vector<int> vc;
    for (int i=0; i<N; i++) {
        scanf("%d", &B);
        vc.push_back(B);
    }
    scanf("%d %d", &B, &C);
    
    for (int i=0; i<N; i++) {
        ans++;
        vc[i]-=B;
        if (vc[i]>0)
            ans = ans+vc[i]/C+(vc[i]%C==0?0:1);
    }
        
    printf("%ld", ans);
    return 0;
}
