//
//  main.cpp
//  1629
//
//  Created by 양종열 on 2018. 1. 24..
//  Copyright © 2018년 양종열. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;



int main(int argc, const char * argv[]) {
    // insert code here...
    long long a, b, c, temp=1LL;
    cin>>a>>b>>c;
    
    while (b>0) {
        if(b%2==1){
            temp*=a;
            temp%=c;
        }
        a*=(a%c);
        a%=c;
        b/=2;
    }
    
    cout<<temp%c;
    return 0;
}
