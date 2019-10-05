//
//  main.cpp
//  17144. 미세먼지 안녕!
//
//  Created by carrot on 06/10/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <cstring>
#define loop(a,b) for(int a=0; a<b; a++)
using namespace std;
int R,C,T,machine,map[50][50][2],dir_r[]={0,0,1,-1},dir_c[]={1,-1,0,0};

void show() {
    printf("\n");
    loop(i,R) {
        loop(j,C) printf("%d ", map[i][j][0]);
        printf("\n");
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d %d %d", &R, &C, &T);
    loop(i,R) loop(j,C) {
        scanf("%d",&map[i][j][0]);
        if (map[i][j][0]==-1) machine=i;
    }
    
    while(T--) {
        loop(i,R) loop(j,C) {
            if (map[i][j][0]>0) {
                int cnt=0;
                loop(k,4) {
                    int nr=i+dir_r[k], nc=j+dir_c[k];
                    if (0>nr||nr>=R||0>nc||nc>=C) continue;
                    if (map[nr][nc][0]==-1) continue;

                    cnt++;
                    map[nr][nc][1] += map[i][j][0]/5;
                }

                map[i][j][0] -= (map[i][j][0]/5)*cnt;
            }
        }

        loop(i,R) loop(j,C) {
            map[i][j][0]+=map[i][j][1];
            map[i][j][1]=0;
        }
        
        int r=machine-1, c=1, dir=0, before=map[r][c][0];   // up cycle
        map[r][c][0]=0;
        while(1) {
            if (dir==0) { c+=1; }   // right
            else if (dir==1) { r-=1; }  // up
            else if (dir==2) { c-=1; } // left
            else { r+=1; } // down
            
            if (r==machine-1 && c==C-1) dir=1;
            if (r==0 && c==C-1) dir=2;
            if (r==0 && c==0) dir=3;
            
            if (r==machine-1 && c==0) break;
            int tmp=map[r][c][0];
            map[r][c][0]=before;
            before=tmp;
        }
        
        r=machine; c=1; dir=0; before=map[r][c][0];
        map[r][c][0]=0;
        while(1) {
            if (dir==0) { c+=1; }   // right
            else if (dir==1) { r-=1; }  // up
            else if (dir==2) { c-=1; } // left
            else { r+=1; } // down
            
            if (r==machine && c==C-1) dir=4;
            if (r==R-1 && c==C-1) dir=2;
            if (r==R-1 && c==0) dir=1;
            
            if (r==machine && c==0) break;
            int tmp=map[r][c][0];
            map[r][c][0]=before;
            before=tmp;
        }
        
//        show();
    }
    
    int amt=0;
    loop(i,R) loop(j,C) if (map[i][j][0]>0) amt+=map[i][j][0];
    printf("%d", amt);
    return 0;
}
