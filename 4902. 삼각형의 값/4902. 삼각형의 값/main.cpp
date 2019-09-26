//
//  main.cpp
//  4902. 삼각형의 값
//
//  Created by carrot on 24/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
int N, n[400*400]; long long ans;

void cal_down(int s) {
    int amt = n[s], l=sqrt(s), cnt=1, start=s;
    for (int i=l+1; i<N; i++) {
        start=start+2*i-1; cnt++;
        for (int j=start; j<start+2*cnt-1; j++)
            amt += n[j];
        if (amt>ans)
            ans=amt;
    }
}

void cal_up(int s) {
    int amt = n[s], l=sqrt(s), cnt=1, start=s;
    bool flag = false;
    for (int i=l-1; i>=2; i--) {
        start=start-(2*i+1); cnt++;
        for (int j=start; j>start-(2*cnt-1); j--) {
            if (j<i*i || j>=(i+1)*(i+1)) { flag=true; break; }
            amt += n[j];
        }
        if (flag) return;
        if (!flag && amt>ans)
            ans=amt;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int t=1;
    while (1) {
        bool minus = false;
        scanf("%d", &N); if (N==0) break;
        int amt = 0; ans = 0;
        for (int i=0; i<N*N; i++) {
            scanf("%d", &n[i]);
            if (n[i]>ans) ans = n[i];   // one
            if (n[i]<0) minus = true;
            amt += n[i];
        }
        if (amt > ans) ans = amt;   // total
        if (minus)
            for (int i=0; i<N; i++) {
                bool flag = false;
                for (int j=i*i; j<(i+1)*(i+1); j++) {
                    if (!flag) cal_down(j);
                    else cal_up(j);
                    flag=!flag;
                }
            }
        printf("%d. %lld\n",t++,ans);
    }
    return 0;
}
