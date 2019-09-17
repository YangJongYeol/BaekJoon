//
//  main.cpp
//  1208.Flatten
//
//  Created by carrot on 08/05/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
using namespace std;
int num[100];
int dump;
int ans;
void dfs(int cnt, int diff) {
    int max = 0;
    int maxIndex = -1;
    int min = 100;
    int minIndex = -1;
    
    if (cnt == dump+1) {
        ans = diff;
        return;
    }
    
    for (int i=0; i<100; i++) { // find max, min
        if (num[i] > max) {
            max = num[i];
            maxIndex = i;
        }
        
        if (num[i] < min) {
            min = num[i];
            minIndex = i;
        }
    }
    
    if (max == min) {
        ans = 0;
        return;
    } else {
        num[maxIndex]-=1;
        num[minIndex]+=1;
        dfs(cnt+1, max-min);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    for (int tc=1; tc<=10; tc++) {
        ans = 0;
        cin >> dump;
        for (int i=0; i<100; i++) {
            cin >> num[i];
        }
        
        dfs(0,100);
        
        cout << "#" << tc << " " << ans << "\n";
    }
    return 0;
}
