//
//  main.cpp
//  14225. 부분수열의 합
//
//  Created by carrot on 07/10/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <queue>
#define MAX 2000001
#define loop(a,b,c) for(int a=b; a<c; a++)
using namespace std;
int N,num[20],sum[MAX];

void cal(int comb) {
    int amt=0;
    loop(i,0,N) if(comb&(1<<i)) amt+=num[i];
    sum[amt]=1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d", &N);
    loop(i,0,N) scanf("%d",&num[i]);
    
    queue<int> q;
    loop(i,0,N) q.push(1<<i);
    while(!q.empty()) {
        int comb = q.front(); q.pop();
        loop(i,0,N) {
            if(comb&(1<<i)) { cal(comb); break; }
            q.push(comb|(1<<i));
        }
    }
    
    loop(i,1,MAX) if(!sum[i]) { printf("%d",i); break; }
    return 0;
}
