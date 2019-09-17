//
//  main.cpp
//  2108
//
//  Created by 양종열 on 2018. 2. 4..
//  Copyright © 2018년 양종열. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool comp(const pair<int, int> &p1,const pair<int, int> &p2){
    
    if(p1.second == p2.second){
        return p1.first < p2.first;
        
    }
    return p1.second > p2.second;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false);
    
    int n;
    cin>>n;
    
    double average = 0;    // 산술평균
    
    vector<int> numbers;
    
    for (int i=0; i<n; i++) {
        double temp;
        cin>>temp;
        
        average += temp;
        numbers.push_back(temp);
    }
    
    sort(numbers.begin(), numbers.end());

    vector<pair<int,int>> st;
    vector<int>::size_type i;
    
    for(i=0; i<numbers.size(); i++){
        if(st.empty()){
            st.push_back(pair<int,int>(numbers[i],1));
            continue;
        }
        
        if(st.back().first == numbers[i]){
            pair<int, int> tmp = st.back();
            tmp.second++;
            st.pop_back();
            st.push_back(tmp);
            
        }else{
            st.push_back(pair<int,int>(numbers[i],1));
        }
    }
    
    sort(st.begin(), st.end(), comp);
    
    cout <<  (int)floor( (average / n) + 0.5) << endl;
    cout << numbers[n/2] << endl;
    if(st[0].second == st[1].second){
        cout << st[1].first << endl;
    }else{
        cout << st[0].first << endl;
    }
    cout << numbers.back() - numbers.front() << endl;
    
    return 0;
}
