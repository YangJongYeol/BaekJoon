//
//  main.cpp
//  12996. Acka
//
//  Created by carrot on 06/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#define mod 1000000007
using namespace std;
long long arr[51][51][51][51]; int S, one,two,three;

void song(int idx) {
    for (int i=0; i<=(idx-1); i++)
        for (int j=0; j<=(idx-1); j++)
            for (int k=0; k<=(idx-1); k++)
                if (arr[idx-1][i][j][k]!=0) {
                    if (one!=i) {arr[idx][i+1][j][k]+=arr[idx-1][i][j][k]; arr[idx][i+1][j][k] %= mod;}
                    if (two!=j) {arr[idx][i][j+1][k]+=arr[idx-1][i][j][k]; arr[idx][i][j+1][k] %= mod;}
                    if (three!=k) {arr[idx][i][j][k+1]+=arr[idx-1][i][j][k];  arr[idx][i][j][k+1] %= mod;}
                    if (one!=i && two!=j) {arr[idx][i+1][j+1][k]+=arr[idx-1][i][j][k];  arr[idx][i+1][j+1][k] %= mod;}
                    if (one!=i && three!=k) {arr[idx][i+1][j][k+1]+=arr[idx-1][i][j][k];  arr[idx][i+1][j][k+1] %= mod;}
                    if (two!=j && three!=k) {arr[idx][i][j+1][k+1]+=arr[idx-1][i][j][k];  arr[idx][i][j+1][k+1] %= mod;}
                    if (one!=i && two!=j && three!=k) {arr[idx][i+1][j+1][k+1]+=arr[idx-1][i][j][k];  arr[idx][i+1][j+1][k+1] %= mod;}
                }
    
    if (idx!=S)
        song(idx+1);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d %d %d %d", &S, &one, &two, &three);
    
    arr[1][1][0][0] = 1;
    arr[1][0][1][0] = 1;
    arr[1][0][0][1] = 1;
    arr[1][1][1][0] = 1;
    arr[1][1][0][1] = 1;
    arr[1][0][1][1] = 1;
    arr[1][1][1][1] = 1;
    song(2);
    
    long long amt = arr[S][one][two][three];
    
    printf("%lld", amt%1000000007);
    return 0;
}
