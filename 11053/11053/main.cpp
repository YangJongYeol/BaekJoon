//
//  main.cpp
//  11053
//
//  Created by 양종열 on 2018. 1. 31..
//  Copyright © 2018년 양종열. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false);
    
    int n, temp, count=1;
//    vector<int> trains;
    cin>>n;
    
//    for (int i=0; i<n; i++) {
//        cin>>temp;
//        if (trains.size()==0) {
//            trains.push_back(temp);
//            count++;
//        } else if(trains.back()<temp) {
//            trains.push_back(temp);
//            count++;
//        } else {
//            auto it = lower_bound(trains.begin(), trains.end(), temp);
//            *it = temp;
//        }
//    }

    int arr[n], dp[n];
    
    for (int i = 0 ; i < n; i++) {
        arr[i] = 0;
        dp[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    
    for (int i = 0; i < n; i++) {
        if (dp[i] == 0)dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }
    
    for (int i=0; i<n; i++) {
        cout<<dp[i]<<" ";
    }
    
    for (int i=0; i<n; i++) {
        if (dp[i]>dp[i-1]) {
            count++;
        }
    }
    
    stack<int>result;
    
    cout<<endl<<count<<endl;
    cout<<arr[0]<<" ";
    for (int i=n; i>0; i--) {
        if (dp[i]>dp[i-1]) {
            result.push(arr[i]);
        }
    }
    
    for (int i=0; i<n; i++) {
        cout<<result.top()<<" ";
        result.pop();
    }
   
    //cout<<endl<<dp[n];
    
    return 0;
}
