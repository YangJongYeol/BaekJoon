//
//  main.cpp
//  1463-1로 만들기
//
//  Created by 양종열 on 2018. 5. 11..
//  Copyright © 2018년 양종열. All rights reserved.
//

#include<iostream>
#include<cmath>
using namespace std;
int n;
int d[1000001];

int main() {
    cin>>n;
    
    d[1] = 0;
    for (int i = 2; i<=n; i++) {
        d[i] = d[i-1]+1;
        if(i%2 == 0)
            d[i] = min(d[i], d[i/2]+1);
        if(i%3 == 0)
            d[i] = min(d[i], d[i/3]+1);
    }
    
    cout<<d[n];
    return 0;
}
