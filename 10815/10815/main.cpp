//
//  main.cpp
//  10815
//
//  Created by 양종열 on 2018. 1. 24..
//  Copyright © 2018년 양종열. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int n,m,temp;
    
    cin>>n;
    vector<int> cards;
    for (int i=0; i<n; i++) {
        cin>>temp;
        cards.push_back(temp);
    }
    
    cin>>m;
    vector<int> numbers;
    for (int i=0; i<m; i++) {
        cin>>temp;
        numbers.push_back(temp);
    }
    
    sort(cards.begin(), cards.end());
    sort(numbers.begin(), numbers.end());
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if(cards[i]==numbers[j])
                cout<<"1 ";
        }
    }
    
    return 0;
}
