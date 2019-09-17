//
//  main.cpp
//  5658. 보물상자 비밀번호
//
//  Created by carrot on 17/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T, K, N;
long ans;
char ch[28];

int cal(int i) {
    if (ch[i]<'A') return ch[i]-'0';
    else return (ch[i]-'A')+10;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; test_case++) {
        ans = -1;
        vector<long> vc;
        scanf("%d %d", &N, &K);
        for (int i=0; i<N; i++) {
            scanf(" %c", &ch[i]);
        }

        for (int i=0; i<N/4; i++) {
            int index = 0;
            for (int j=0; j<4; j++) {
                long num=0, tmp=0;
                int l = index+N/4;
                for (;index<l;index++) {
                    if (i+index<N) tmp = cal(i+index);
                    else tmp = cal(i+index-N);
                    
                    for (int k=1; k<l-index; k++)
                        tmp *= 16;
                    
                    num += tmp;
                }
                
                vc.push_back(num);
            }
        }
        
        sort(vc.begin(), vc.end());
        long pre=vc[vc.size()-1]; int index=0;
        for (int i=(int)vc.size()-1; i>=0; i--) {
            if (pre!=vc[i-1])
                index++;
            
            if (index==K) {
                ans = pre;
                break;
            }
            
            pre = vc[i-1];
        }

        if (ans == -1) ans = vc[0];
        printf("#%d %ld", test_case, ans);
    }
    return 0;
}
