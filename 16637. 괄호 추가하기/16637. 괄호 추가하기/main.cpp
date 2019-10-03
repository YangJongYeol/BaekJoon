//
//  main.cpp
//  16637. 괄호 추가하기
//
//  Created by carrot on 30/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <cmath>
#define EOD pow(2,32)
using namespace std;
long long num[10], ans; char sym[10]; int N;

long long cal(long long from, long long to, char symbol) {
    long long amt=0;
    switch (symbol) {
        case '+':
            amt = from+to;
            break;
        case '-':
            amt = from-to;
            break;
        case '*':
            amt = from*to;
            break;
    }
    
    return amt;
}

void check(int size) {
    long long amt = num[0];
    for (int i=1; i<size; i++) {
        amt = cal(amt,num[i],sym[i-1]);
    }
    
    if (ans<amt) ans=amt;
}

void dfs(int idx, int size) {
    long long tmp_num[10];
    char tmp_sym[10];
    for (int i=0; i<size; i++) {tmp_num[i]=num[i]; tmp_sym[i]=sym[i];}
    for (int i=idx; i<size-1; i++) {
        num[i]=cal(num[i],num[i+1],sym[i]);
        for (int j=i+1; j<size-1; j++) { num[j]=num[j+1]; }
        for (int j=i; j<size-2; j++) { sym[j]=sym[j+1]; }
        check(size-1);
        if (size>=2)
            dfs(i+1,size-1);
        for (int j=0; j<size; j++) {num[j]=tmp_num[j]; sym[j]=tmp_sym[j];}
    }
}

int main() {
    scanf("%d",&N); ans=EOD*(-1);
    for (int i=0; i<N; i++) {
        if (i%2==0) scanf(" %1lld", &num[i/2]);
        else scanf(" %1c", &sym[i/2]);
    }

    int size = size=N/2+1;
    check(size);
    dfs(0,size);
    
    printf("%lld", ans);
    return 0;
}
