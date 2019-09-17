//
//  main.cpp
//  2112. 보호필름
//
//  Created by carrot on 25/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
int T,D,W,K,map[13], ans;

bool check() {
    for (int i=0; i<W; i++) {
        bool flag = false;
        for (int j=0; j<=D-K; j++) {
            int c=0;
            for (int k=j; k<j+K; k++) {
                if (map[k]&(1<<i)) c++;
            }
            if (c==K || c==0) {flag = true; break;}
        }
        
        if (!flag) return false;
    }
    
    return true;
}

bool injection(int a, int count, int c) {
    if (count==c) return check();
    
    bool flag = false;
    for (int i=0; i<D; i++) {
        if (a&(1<<i)) {
            int tmp = map[i];
            map[i] = (1<<D)-1;
            int tmp2 = a|(1&&i);
            injection(tmp2,count+1,c);
            
            map[i] = tmp;
            map[i] = 0;
            injection(tmp2, count+1,c);
            
            map[i] = tmp;
            
            flag = true;
        }
    }
    
    if (!flag) return check();
    return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d", &T); ans=0;
    for (int t=1; t<=T; t++) {
        scanf("%d %d %d", &D, &W, &K);
        
        for (int i=0; i<D; i++) {
            int row=0, tmp=0;
            for (int j=0; j<W; j++) {
                scanf("%d", &tmp);
                row = row|(tmp<<j);
            }
            map[i]=row;
        }
        
        if (check()) {printf("#%d %d",t,0); break;}
        
        stack<int> st;
        for (int i=0; i<D; i++) {
            st.push(1<<i);
        }
        
        while(!st.empty()) {
            int cur = st.top();
            st.pop();
            
            int count = 0; bool flag = false;
            for (int i=0; i<D; i++) {
                if (cur&(1<<i)) {count++; continue; }
                else {
                    st.push(cur|(1<<i));
                    if (count>=2)
                        if (injection(cur|1<<i,1,count)) {
                            flag = true; break;
                        }
                }
            }
            
            if (flag) { ans=count+1; break; }
        }
        
        printf("#%d %d",t,ans);
    }
    return 0;
}
