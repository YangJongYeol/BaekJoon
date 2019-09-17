//
//  main.cpp
//  1259. 금속막대
//
//  Created by carrot on 02/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int T;
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        int n;
        int max=0;
        vector<pair<int, int>> vc;
        vector<int> tmp;
        scanf("%d", &n);
        
        int m,f;
        for (int i=0; i<n; i++) {
            scanf("%d %d", &m, &f);
            vc.push_back(make_pair(m,f));
            
            if (m>max) max=m;
            if (f>max) max=f;
        }
        
        max++;
        int c[max];
        memset(c, 0, sizeof(c));
        for (int i=0; i<n; i++) {
            c[vc[i].first]+=1;
            c[vc[i].second]+=100;
        }
        
        int s=0;
        for (int i=0; i<max+1; i++) {
            if(c[i]==1) s=i;
        }
        
        printf("#%d ", t);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if(vc[j].first==s) {
                    printf("%d %d ", vc[j].first, vc[j].second);
                    s = vc[j].second;
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
