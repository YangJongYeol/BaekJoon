//
//  main.cpp
//  7227. 사랑의 카운슬러
//
//  Created by carrot on 05/05/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc, N;
    long long sum_x, sum_y;
    long long min;
    vector<pair<int,int>> vc;
    int tmp[2];
    
    cin >> tc;
    for (int t=0; t<tc; t++) {
        cin >> N;
        sum_x = 0; sum_y = 0;
        min = 800000000000;
        
        vector<bool> vc_tmp(N);
        
        for (int i=0; i<N; i++) {
            cin >> tmp[0] >> tmp[1];
            vc.push_back(make_pair(tmp[0], tmp[1]));
        }
        
        fill(vc_tmp.end()-N/2, vc_tmp.end(), true);
        
        int idx;
        do {
            idx = 0;
            sum_x = 0; sum_y = 0;
            for (int i=0; i<N; i++) {
                if (vc_tmp[i]) { sum_x -= vc[i].first; sum_y -= vc[i].second; }
                else { sum_x += vc[i].first; sum_y += vc[i].second; }
            }
            
            long long sum = (sum_x*sum_x) + (sum_y*sum_y);
            if (min > sum) { min = sum; }
            
            if (min == 0) { break; }
        } while (next_permutation(vc_tmp.begin(), vc_tmp.end()));
        
        
        cout << "#" << t+1 << " " << min << endl;
        
        vc.clear();
    }
    
    
    return 0;
}
