//
//  main.cpp
//  1770. 블록 부품 맞추기
//
//  Created by carrot on 28/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

int makeBlock(int module[][4][4]) {
    int MAX = 30000;
    int amt = 0;
    int m[129][700];
    int idx[129];
    for (int i=0; i<129; i++) idx[i]=0;
    for (int i=0; i<MAX; i++) {
        int a=0;
        for (int j=0; j<4; j++)
            for (int k=0; k<4; k++)
                a+=module[i][j][k];
        
        m[a][idx[a]++] = i;
    }
    
    for (int one=0; one<=64; one++) {
        int theother = 128-one;
        for (int i=0; i<idx[one]; i++) {
            for (int j=0; j<idx[theother]; j++) {
                if (idx[theother]==-1) continue;
                bool flag = false;
                for (int k=0; k<4; k++) {
                    for (int l=0; l<4; l++) {
                        if (module[m[one][i]][k][l]+module[m[theother][j]][k][l]==8) continue;
                        flag = true; break;
                    }
                    if (flag) break;
                }
                
                if (!flag) { amt+= 128; continue; }
                flag = false;
                
                for (int k=0; k<4; k++) {
                    for (int l=0; l<4; l++) {
                        if (module[m[one][i]][k][l]+module[m[theother][j]][l][3-k]==8) continue;
                        flag = true; break;
                    }
                    if (flag) break;
                }
                
                if (!flag) { amt+= 128; continue; }
                flag = false;
                
                for (int k=0; k<4; k++) {
                    for (int l=0; l<4; l++) {
                        if (module[m[one][i]][k][l]+module[m[theother][j]][3-k][3-l]==8) continue;
                        flag = true; break;
                    }
                    if (flag) break;
                }
                
                if (!flag) { amt+= 128; continue; }
                flag = false;
                
                for (int k=0; k<4; k++) {
                    for (int l=0; l<4; l++) {
                        if (module[m[one][i]][k][l]+module[m[theother][j]][3-l][k]==8) continue;
                        flag = true; break;
                    }
                    if (flag) break;
                }
                
                if (!flag) { amt+= 128; continue; }
                flag = false;
            }
        }
    }
    
    return amt;
}
