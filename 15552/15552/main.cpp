//
//  main.cpp
//  15552
//
//  Created by 양종열 on 2018. 7. 9..
//  Copyright © 2018년 양종열. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    int a, b;
    for (int i=0; i<N; i++) {
        cin >> a >> b;
        cout << a+b << "\n";
    }
    
    return 0;
}
