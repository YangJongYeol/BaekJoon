//
//  main.cpp
//  16926. 배열 돌리기1
//
//  Created by carrot on 29/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <vector>
#define MIN(A,B) (A<B?A:B)
using namespace std;
int N, M, R, map[301][301];
vector<int> vc[151];

void show(int copy_amt) {
    for (int i=0; i<copy_amt; i++) {
        for (int j=0; j<vc[i].size(); j++)
            printf("%d ", vc[i][j]);
        printf("\n");
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d %d %d", &N, &M, &R);
    for (int i=0; i<N; i++) for (int j=0; j<M; j++) scanf("%d", &map[i][j]);
    int amt = MIN(N,M)/2; int copy_amt = amt;
    while(amt--) {
        for (int i=amt; i<M-amt-1; i++)
            vc[amt].push_back(map[amt][i]); // 상
        for (int i=amt; i<N-amt-1; i++)
            vc[amt].push_back(map[i][M-amt-1]); // 좌
        for (int i=M-amt-1; i>=amt+1; i--)
            vc[amt].push_back(map[N-amt-1][i]); // 하
        for (int i=N-amt-1; i>=amt+1; i--)
            vc[amt].push_back(map[i][amt]); // 우
    }
    
    for (int i=0; i<copy_amt; i++) {
        int start = R%(int)vc[i].size();
        for (int j=i; j<M-i-1; j++) { map[i][j] = vc[i][start++]; if(start==(int)vc[i].size()) start=0; }
        for (int j=i; j<N-i-1; j++) { map[j][M-i-1] = vc[i][start++]; if(start==(int)vc[i].size()) start=0; }
        for (int j=M-i-1; j>=i+1; j--) { map[N-i-1][j] = vc[i][start++]; if(start==(int)vc[i].size()) start=0; }
        for (int j=N-i-1; j>=i+1; j--) { map[j][i] = vc[i][start++]; if(start==(int)vc[i].size()) start=0; }
    }
            
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++)
            printf("%d ", map[i][j]);
        printf("\n");
    }
    return 0;
}
