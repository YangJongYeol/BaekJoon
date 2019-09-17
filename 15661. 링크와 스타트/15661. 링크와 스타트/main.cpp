//
//  main.cpp
//  15661. 링크와 스타트
//
//  Created by carrot on 20/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
int N, S[20][20];
int team[2][20];
int m = 10000000;

void setTeam(int t) {
    int sTeam = 0, lTeam = 0;
    for (int i=0; i<N; i++) {
        if (t&(1<<i)) {team[0][sTeam++]=i;}
        else {team[1][lTeam++]=i;}
    }
    
    int sP=0, lP=0;
    for (int i=0; i<sTeam-1; i++)
        for (int j=i+1; j<sTeam; j++)
            sP = sP+S[team[0][i]][team[0][j]]+S[team[0][j]][team[0][i]];
    for (int i=0; i<lTeam-1; i++)
        for (int j=i+1; j<lTeam; j++)
            lP = lP+S[team[1][i]][team[1][j]]+S[team[1][j]][team[1][i]];
    
    int tmp = abs(sP-lP);
    if (m>tmp) m = tmp;
    if (tmp==0) {m=0; return;}
    for (int i=0; i<N; i++) {
        if (t&(1<<i)) break;
        setTeam(t|(1<<i));
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d", &N);
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            scanf("%d", &S[i][j]);
    
    for (int i=0; i<N; i++) {
        int t = 1<<i;
        setTeam(t);
    }
        
    printf("%d", m);
    
    return 0;
}
