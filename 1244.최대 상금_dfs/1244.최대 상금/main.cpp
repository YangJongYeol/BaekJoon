//
//  main.cpp
//  1244.최대 상금
//
//  Created by carrot on 06/05/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string num;
int n;
int result;

void dfs(int cur, int cnt) {
    if(cnt == n) {
        result = max(result, stoi(num));
        return;
    }
    
    for (int i=cur; i<num.length(); i++) {
        for (int j=i+1; j<num.length(); j++) {
            if(num[i]<=num[j]) {
                swap(num[i], num[j]);
                dfs(i,cnt+1);
                swap(num[i], num[j]);
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    
    for (int i=1; i<=t; i++) {
        cin >> num >> n;
        result = 0;
        dfs(0,0);
        
        cout << "#" << i << " " << result << endl;
    }
    
    return 0;
}
