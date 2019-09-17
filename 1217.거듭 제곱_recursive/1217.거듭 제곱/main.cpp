//
//  main.cpp
//  1217.거듭 제곱
//
//  Created by carrot on 12/05/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
using namespace std;

int recursive_pow(int cur, int a, int b) {
    if (b == 0) { return cur; }
    else { return recursive_pow(cur*a,a,b-1); }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    for (int i=0; i<10; i++) {
        int tc;
        cin >> tc;
        
        int a, b;
        cin >> a >> b;
        
        cout << "#" << tc << " " << recursive_pow(a,a,b-1) << "\n";
    }
    return 0;
}
