//
//  main.cpp
//  kakao2019_3
//
//  Created by carrot on 07/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int key_size = (int)key.size();
    int lock_size = (int)lock.size();
    int map_size = 2*key_size+lock_size-2;
    int map[map_size][map_size];
    memset(map, -1, sizeof(map));
    bool answer = false;
    
    for (int i=0; i<lock_size; i++)
        for (int j=0; j<lock_size; j++)
            map[i+key_size-1][j+key_size-1] = lock[i][j];
    
    for (int t=0; t<4; t++) {
//        for (int i=0; i<key_size; i++) {
//            for (int j=0; j<key_size; j++)
//                printf("%d", key[i][j]);
//            printf("\n");
//        }
//        printf("\n");
        // 1. key move
        for (int i=0; i<lock_size+key_size-1; i++) {
            for (int j=0; j<lock_size+key_size-1; j++) {
                // 2. check
                for (int k=key_size-1; k<key_size-1+lock_size; k++) {
                    for (int l=key_size-1; l<key_size-1+lock_size; l++) {
                        if (k>key_size-1+i || l>key_size-1+j) break;
                        if (i>k || j>l) continue;
                        map[k][l] += (key[k-i][l-j]==1?2:0);
                    }
                }
                
//                for (int k=key_size-1; k<key_size-1+lock_size; k++) {
//                    printf("\n");
//                    for (int l=key_size-1; l<key_size-1+lock_size; l++)
//                        printf("%d", map[k][l]);
//                }
//                printf("\n");
                
                bool flag = false;
                for (int k=0; k<lock_size; k++) {
                    for (int l=0; l<lock_size; l++) {
                        if (map[k+key_size-1][l+key_size-1]==2 || map[k+key_size-1][l+key_size-1]==1) {continue;}
                        else {flag = true; break; }
                    }
                    if (flag) break;
                }
                
                if (!flag) return true;
                for (int k=0; k<map_size; k++)
                    for (int l=0; l<map_size; l++) {
                        if (map[k][l]==2) map[k][l]=0;
                        if (map[k][l]==3) map[k][l]=1;
                    }
            }
        }
        
        // rotate
        int tmp[key_size][key_size];
        for (int i=0; i<key_size; i++)
            for (int j=0; j<key_size; j++)
                tmp[i][j] = key[j][key_size-1-i];
        
        for (int i=0; i<key_size; i++)
            for (int j=0; j<key_size; j++)
                key[i][j] = tmp[i][j];
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> a = {{0, 0, 0}, {1, 0, 0}, {0, 1, 1}};
    vector<vector<int>> b = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    cout<<solution(a, b)<<endl;
        
    return 0;
}
