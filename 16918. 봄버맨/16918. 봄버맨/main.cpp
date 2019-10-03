//
//  main.cpp
//  16918. 봄버맨
//
//  Created by carrot on 29/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <set>
#define loop for(int i=0; i<R; i++) for(int j=0; j<C; j++)
using namespace std;
int dir_r[]={1,-1,0,0}, dir_c[]={0,0,1,-1};
int R,C,N,map[200][200];
set<pair<int,int>> bomb;

void show() {
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++)
            printf("%c",(bomb.count(make_pair(i,j))?'O':'.'));
//            printf("%d",map[i][j]);
        printf("\n");
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d %d %d", &R, &C, &N);
    char ch;
    loop { scanf(" %1c", &ch); map[i][j] = (ch=='O'?2:0); if (map[i][j]) bomb.insert(make_pair(i, j)); }
    for (int t=2; t<=N; t++) {
        loop if (map[i][j]) map[i][j]--;
        if (t%2==0) loop if (!map[i][j]) { map[i][j]=3; bomb.insert(make_pair(i,j)); }
        loop if (map[i][j]==0 && bomb.count(make_pair(i,j))) {
            for (int k=0; k<4; k++) {
                int r=i+dir_r[k]; int c=j+dir_c[k];
                if (0>r||r>=R||0>c||c>=C) continue;
                if (bomb.count(make_pair(r,c)) && !map[r][c]) continue;
                bomb.erase(make_pair(r,c)); map[r][c]=0;
            }
            bomb.erase(make_pair(i,j));
        }
    }
    
    show();
    return 0;
}
