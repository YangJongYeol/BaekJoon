//
//  main.cpp
//  2019_line4
//
//  Created by carrot on 22/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int N, seat[20000], ans;

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d", &N); ans=0;
    for (int i=0; i<N; i++) scanf("%d", &seat[i]);
    
    queue<pair<int, int>> q;    // 현 위치, 방향
    for (int i=0; i<N; i++) {
        if (seat[i]) continue;
        
        int left = i; int right = i;
        int dist = 0;
        while (1) {
            dist++;
            if (left>0) {
                if (seat[left-1]) break;
                else left--;
            }
            
            if (right<N-1) {
                if (seat[right+1]) break;
                else right++;
            }
        }
        
        if (ans<dist) ans=dist;
    }
    
    printf("%d", ans);
    return 0;
}
