//
//  main.cpp
//  4811. 알약
//
//  Created by carrot on 31/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
long dp[31][31], N;
struct Info {
    long wnum,hnum;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    while (1) {
        scanf("%ld", &N);
        if (N==0) break;
        
        dp[N-1][1] = 1;
        queue<Info> q;
        q.push({N-1,1});
        while (1) {
            Info inf = q.front();
            q.pop();
            
            if (inf.wnum!=0) {
                if (!dp[inf.wnum-1][inf.hnum+1])
                    q.push({inf.wnum-1,inf.hnum+1});
                dp[inf.wnum-1][inf.hnum+1] += dp[inf.wnum][inf.hnum];
                //printf("(%d, %d): %d", inf.wnum-1, inf.hnum+1, dp[inf.wnum-1][inf.hnum+1]);
            }
            if (inf.hnum!=0) {
                if (!dp[inf.wnum][inf.hnum-1])
                    q.push({inf.wnum,inf.hnum-1});
                dp[inf.wnum][inf.hnum-1] += dp[inf.wnum][inf.hnum];
                //printf("(%d, %d): %d", inf.wnum, inf.hnum-1, dp[inf.wnum][inf.hnum-1]);
            }
            
            if (inf.wnum==0 && inf.hnum==0) break;
        }
        
        printf("%ld\n", dp[0][0]);
        for (int i=0; i<31; i++) for (int j=0; j<31; j++) dp[i][j]=0;
    }
    return 0;
}
