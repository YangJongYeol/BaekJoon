//
//  main.cpp
//  1265. 달란트2
//
//  Created by carrot on 02/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int T;
    scanf("%d", &T);
    
    for (int t=1; t<=T; t++) {
        long long a, b, c, d, ans=1;
        scanf("%lld %lld", &a, &b);
        
        c = a/b;
        d = a%b;
        
        for (int i=0; i<b; i++) {
            if (d!=0) {
                ans *= (c+1);
                d--;
            } else {
                ans *= c;
            }
        }
        
        printf("#%d %lld\n", t, ans);
    }
    
    return 0;
}
