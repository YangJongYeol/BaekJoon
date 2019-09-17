//
//  main.cpp
//  2105. 디저트 카페
//
//  Created by carrot on 18/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
using namespace std;
int T, N, map[20][20], ans;
int dir_r[]={1,1,-1,-1};
int dir_c[]={-1,1,1,-1};
bool desert[101];
int dot[4][2];

bool check() {
    for (int i=1; i<=100; i++) desert[i] = false;
    for (int i=0; i<dot[1][0]-dot[0][0]; i++) {
        if (!desert[map[dot[0][0]+i][dot[0][1]-i]]) {
            desert[map[dot[0][0]+i][dot[0][1]-i]]=true;
        } else return false;
    }
    for (int i=0; i<dot[2][0]-dot[1][0]; i++) {
        if (!desert[map[dot[1][0]+i][dot[1][1]+i]]) {
            desert[map[dot[1][0]+i][dot[1][1]+i]]=true;
        } else return false;
    }
    for (int i=0; i<dot[2][0]-dot[3][0]; i++) {
        if (!desert[map[dot[2][0]-i][dot[2][1]+i]]) {
            desert[map[dot[2][0]-i][dot[2][1]+i]]=true;
        } else return false;
    }
    for (int i=0; i<dot[3][0]-dot[0][0]; i++) {
        if (!desert[map[dot[3][0]-i][dot[3][1]-i]]) {
            desert[map[dot[3][0]-i][dot[3][1]-i]]=true;
        } else return false;
    }
    return true;
}

void tour() {
    for (int i=0; i<N-2; i++) {
        for (int j=1; j<N-1; j++) {
            for (int k=1; k<=j; k++) {
                int l=1;
                while((i+k+l<N) && (j+l<N)) {
                    dot[0][0] = i; dot[0][1] = j;
                    dot[1][0] = i+k; dot[1][1] = j-k;
                    dot[2][0] = i+k+l; dot[2][1] = j-k+l;
                    dot[3][0] = i+l; dot[3][1] = j+l;
                    if (check()) {
                        int tmp = k*2+l*2;
                        if (tmp>ans) ans = tmp;
                        //break;
                    }
                    l++;
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        ans = -1;
        scanf("%d", &N);
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                scanf("%d", &map[i][j]);
        
        tour();
        printf("#%d %d\n",t,ans);
    }
    
    return 0;
}
