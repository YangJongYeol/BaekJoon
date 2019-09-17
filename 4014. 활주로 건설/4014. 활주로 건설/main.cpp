//
//  main.cpp
//  4014. 활주로 건설
//
//  Created by carrot on 22/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
int T,N,X,ans;
int map[20][20];
int tmp[20];

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        scanf("%d %d", &N, &X); ans = 0;
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                scanf("%d", &map[i][j]);
        
        for (int i=0; i<N; i++) {
            int count = 0; bool flag = true;
            for (int j=0; j<N-1; j++) {
                if (map[i][j]==map[i][j+1]) { count++; continue; }
                if (map[i][j]-map[i][j+1]==-1 && count+1>=X) { count=0; continue; }
                if (map[i][j]-map[i][j+1]==1) {
                    if (j+X>=N) {flag=false; break;}
                    int amt = 0;
                    for (int k=j+1; k<j+1+X; k++)
                        if (map[i][j+1]==map[i][k]) amt++;
                    if (amt>=X) { count=-1; j=j+X-1; continue; }
                }
                flag = false;
                break;
            }
            if (flag) ans++;
            
            count = 0; flag = true;
            for (int j=0; j<N-1; j++) {
                if (map[j][i]==map[j+1][i]) { count++; continue; }
                if (map[j][i]-map[j+1][i]==-1 && count+1>=X) {count=0; continue; }
                if (map[j][i]-map[j+1][i]==1) {
                    if (j+X>=N) {flag=false; break;}
                    int amt = 0;
                    for (int k=j+1; k<j+1+X; k++)
                        if (map[j+1][i]==map[k][i]) amt++;
                    if (amt>=X) { count=-1; j=j+X-1; continue; }
                }
                flag = false;
                break;
            }
            if (flag) ans++;
        }
        
        printf("#%d %d\n",t,ans);
    }
    return 0;
}
