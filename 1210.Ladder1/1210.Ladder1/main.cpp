//
//  main.cpp
//  1210.Ladder1
//
//  Created by carrot on 27/05/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
int map[100][100];

// down : 0 , left : 1, right : 2
int dfs(int x, int y, int past) {
    if (x==99) {return map[x][y];}
    
    if ((y-1>=0) && (past!=2) && (map[x][y-1]==1)) {
        return dfs(x, y-1,1);
    } else if ((y+1<=99) && (past!=1) && (map[x][y+1]==1)) {
        return dfs(x, y+1,2);
    } else {
        return dfs(x+1, y,0);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    for (int tc = 1; tc<=10; tc++) {
        memset(map,0,sizeof(map));
        
        int tmp;
        cin >> tmp;
        
        for (int i=0; i<100; i++) {
            for (int j=0; j<100; j++) {
                cin >> map[i][j];
            }
        }
        
        for (int i=0; i<100; i++) {
            if (map[0][i]==1) {
                int result = dfs(0,i,0);
                if (result != 1) {
                    cout << "#" << tc << " " << i << "\n";
                    break;
                }
            }
        }
        
        
    }
    
    return 0;
}
