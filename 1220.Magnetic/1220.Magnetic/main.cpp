//
//  main.cpp
//  1220.Magnetic
//
//  Created by carrot on 19/05/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false); cout.tie(0); cin.tie(0);
    
    for (int tc=1; tc<=10; tc++) {
        
        int length;
        cin >> length;
        
        int map[length][length];
        
        for (int i=0; i<length; i++) {
            for (int j=0; j<length; j++) {
                cin >> map[i][j];
            }
        }
        
        int flag;
        int count = 0;
        for (int i=0; i<length; i++) {
            flag = 0;
            for (int j=0; j<length; j++) {
                if (flag==0 && map[j][i]==1) {
                    flag = 1;
                } else if (flag==1 && map[j][i]==2) {
                    count ++;
                    flag = 0;
                }
            }
        }
        
        cout << "#" << tc << " " << count << "\n";
    }
    
    return 0;
}
