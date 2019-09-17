//
//  main.cpp
//  1219.길찾기
//
//  Created by carrot on 01/06/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
int m1[100];
int m2[100];
bool visited[100];
int result;

void dfs(int x) {
    if (x == 99) {
        result = 1;
        return;
    }
    
    if (visited[x]==1) { return; }
    else { visited[x] = 1; }
    
    if (m1[x]!=0 && visited[m1[x]]!=1) {
        dfs(m1[x]);
    }
    
    if (m2[x]!=0 && visited[m2[x]]!=1) {
        dfs(m2[x]);
    }
    
    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    for (int i=1; i<=10; i++) {
        int num, num1, num2;
        cin >> i >> num;
        
        memset(m1, 0, sizeof(m1));
        memset(m2, 0, sizeof(m2));
        memset(visited, 0, sizeof(visited));
        result = 0;
        
        for (int j=0; j<num; j++) {
            cin >> num1 >> num2;
            if (m1[num1]!=0) { m2[num1] = num2; }
            else { m1[num1] = num2; }
        }
        
        dfs(0);
        
        cout << "#" << i << " " << result << "\n";
    }
    
    
    return 0;
}
