//
//  main.cpp
//  1209.Sum
//
//  Created by carrot on 11/05/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int rowSum[100];
int colSum[100];
int croSum[2];

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    for (int i=0; i<10; i++) {
        memset(rowSum, 0, sizeof(rowSum));
        memset(colSum, 0, sizeof(colSum));
        memset(croSum, 0, sizeof(croSum));
        
        int tc;
        cin >> tc;
        
        for (int j=0; j<100; j++) {
            for (int k=0; k<100; k++) {
                int input = 0;
                cin >> input;
                rowSum[j] += input;
                colSum[k] += input;
                
                if (j==k) { croSum[0] += input; }
                if (j+k==99) { croSum[1] += input; }
            }
        }
        
        int output = max(*max_element(rowSum,rowSum+100), max(*max_element(colSum,colSum+100), *max_element(croSum,croSum+2)));
        cout << "#" << tc << " " << output << "\n";
    }
    
    return 0;
}
