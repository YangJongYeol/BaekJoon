//
//  main.cpp
//  2019_line5
//
//  Created by carrot on 22/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int R,C, moon_r, moon_c;
long long ans, amt;

long long factorial(long long a) {
    long long k = 1;
    for (long long i=1; i<=a; i++) k*=i;
    
    return k;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d %d", &R, &C); ans=0; amt=0;
    scanf("%d %d", &moon_r, &moon_c);
    
    if (0<=moon_r && moon_r<R && 0<=moon_c && moon_c<C) {}
    else { printf("fail"); return 0; }
    
    ans = moon_r+moon_c;
    amt = factorial(ans)/(factorial(moon_r)*factorial(moon_c));
    
    printf("%lld\n%lld",ans,amt);
    return 0;
}
