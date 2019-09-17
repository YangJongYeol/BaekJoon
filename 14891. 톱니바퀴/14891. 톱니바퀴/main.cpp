//
//  main.cpp
//  14891. 톱니바퀴
//
//  Created by carrot on 29/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int N, T, dv, mNum, cnt;
int ch[250000];
int t[250000][2];
queue<int> q;
stack<int> st;

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d", &N); T=N*N-N/2; dv=(2*N-1); mNum=0; cnt=0;
    for (int i=1; i<=T; i++)
        scanf("%d %d", &t[i][0], &t[i][1]);

    q.push(1); ch[1]=1;
    while (!q.empty()) {
        int tmp = q.front(); q.pop();
        if (mNum < tmp) mNum = tmp;
        if (tmp==T) break;
        if (tmp%dv!=N && tmp%dv!=0 && t[tmp][1]==t[tmp+1][0] && !ch[tmp+1]) {
            q.push(tmp+1); ch[tmp+1]=tmp;
        }
        if (tmp%dv!=1 && tmp+N-1<=T && t[tmp][0]==t[tmp+N-1][1] && !ch[tmp+N-1]) {
            q.push(tmp+N-1); ch[tmp+N-1]=tmp;
        }
        if (tmp%dv!=N && tmp+N<=T && t[tmp][1]==t[tmp+N][0] && !ch[tmp+N]) {
            q.push(tmp+N); ch[tmp+N]=tmp;
        }
        if (tmp%dv!=1 && tmp%dv!=(N+1) && (tmp-1)>=1 && t[tmp][0]==t[tmp-1][1] && !ch[tmp-1]) {
            q.push(tmp-1); ch[tmp-1]=tmp;
        }
        if (tmp%dv!=1 && (tmp-N)>=1 && t[tmp][0]==t[tmp-N][1] && !ch[tmp-N]) {
            q.push(tmp-N); ch[tmp-N]=tmp;
        }
        if (tmp%dv!=N && (tmp-N+1)>=1 && t[tmp][1]==t[tmp-N+1][0] && !ch[tmp-N+1]) {
            q.push(tmp-N+1); ch[tmp-N+1]=tmp;
        }
    }
    
    st.push(mNum);
    while (!st.empty()) {
        int tmp = st.top();
        if (tmp==1) break;
        st.push(ch[tmp]);
    }
    
    printf("%d\n", (int)st.size());
    while (!st.empty()) {
        printf("%d ", st.top());
        st.pop();
    }
    
    return 0;
}
