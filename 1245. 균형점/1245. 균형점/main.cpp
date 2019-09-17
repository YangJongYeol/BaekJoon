//
//  main.cpp
//  1245. 균형점
//
//  Created by carrot on 28/07/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
using namespace std;
double x[10];
double m[10];

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false); cin.tie(0);
    int k;
    scanf("%d", &k);
    for (int tc=1; tc<=k; tc++) {
        double ans = 0;
        int t;
        scanf("%d", &t);
        for (int i=0; i<t; i++) {
            scanf("%lf", &x[i]);
        }
        for (int i=0; i<t; i++) {
            scanf("%lf", &m[i]);
        }
        
        printf("#%d ", tc);
        for (int i=0; i<t-1; i++) {
            double lf, rf, p_ans=0, left=x[i], right=x[i+1];
            while (1) {
                ans = (left+right)/2;
                if (p_ans>ans && (p_ans-ans)<0.000000000001) break;
                if (p_ans<ans && (ans-p_ans)<0.000000000001) break;
                
                lf=0; rf=0;
                for (int j=0; j<t; j++) {
                    if (x[j] < ans) {
                        lf += (m[j]/((ans-x[j])*(ans-x[j])));
                    } else {
                        rf += (m[j]/((x[j]-ans)*(x[j]-ans)));
                    }
                }
                
                if (lf == rf) break;
                if (lf > rf) {
                    left = ans;
                } else {
                    right = ans;
                }
                p_ans = ans;
            }
            
            printf("%.10lf ", ans);
        }
        
        printf("\n");
    }
    
    return 0;
}
