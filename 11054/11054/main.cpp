//
//  main.cpp
//  11054
//
//  Created by 양종열 on 2018. 7. 5..
//  Copyright © 2018년 양종열. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
int dp_up[1001];
int dp_down[1001];
int arr[1001];

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    
    for (int i=1; i<=N; i++) {
        cin >> arr[i];
        dp_up[i] = 1;
        dp_down[i] = 1;
    }
    
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=i; j++) {
            if (arr[i] > arr[j]) {  //  ++
                dp_up[i] = max(dp_up[j]+1, dp_up[i]);
            }
        }
    }
    
    for (int i=N; i>=1; i--) {
        for (int j=N; j>=i; j--) {
            if (arr[i] > arr[j]) {
                dp_down[i] = max(dp_down[j]+1, dp_down[i]);
            }
        }
    }
    
    int max = 0;
    for (int i=1; i<=N; i++) {
        if (max < dp_up[i]+dp_down[i]-1) {
            max = dp_up[i]+dp_down[i]-1;
        }
    }
    
    cout << max;
    return 0;
}
