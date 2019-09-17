//
//  main.cpp
//  1266. 소수 완제품 확률
//
//  Created by carrot on 08/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
using namespace std;
const int N=18;
double p[19][2];
double a, b;

double cal(int t, int f) {
    double c=1;
    for (int i=1; i<=t; i++) {
        c *= (N+1-i);
        c /= i;
        
        if (f==1) c *= a;
        else c *= b;
    }
    
    for (int i=t+1; i<=N; i++) {
        if (f==1) c *= (1-a);
        else c *= (1-b);
    }
    
    return c;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int T;
    scanf("%d", &T);
    
    for (int t=1; t<=T; t++) {
        scanf("%lf %lf", &a, &b);
        a /= 100; b /= 100;
        
        double aA=0, aB=0;
        for (int i=0; i<=18; i++) {
            if (i==2 || i==3 || i==5 || i==7 || i==11 || i==13 || i==17) continue;
            //p[i][0]=cal(i,1); p[i][1]=cal(i,2);
            aA+=cal(i,1); aB+=cal(i,2);
        }

        printf("#%d %lf\n", t, 1-aA*aB);
        
    }
    return 0;
}
