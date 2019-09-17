//
//  main.cpp
//  15653. 구슬 탈출4
//
//  Created by carrot on 15/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int N, M, ans;
char map[10][10];
int dir_r[4] = {0,0,1,-1};
int dir_c[4] = {1,-1,0,0};
bool check[10][10][10][10];
struct Info {
    int rr, rc, br, bc, num, dir;
};


int main(int argc, const char * argv[]) {
    // insert code here...
    ans = -1;
    scanf("%d %d", &N, &M);
    Info info = {0,0,0,0,0,-1};
    
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++) {
            scanf(" %c", &map[i][j]);
            if (map[i][j]=='R') {
                info.rr = i;
                info.rc = j;
            }
            if (map[i][j]=='B') {
                info.br = i;
                info.bc = j;
            }
        }
    
    queue<Info> q;
    q.push(info);
    
    while(!q.empty()) {
        info = q.front();
        q.pop();
        
        for (int i=0; i<4; i++) {
            int nrr=info.rr, nrc=info.rc, nbr=info.br, nbc=info.bc, num=info.num, dir=info.dir;
            if (dir==0 || dir==1)
                if (i==0 || i==1) continue;
            if (dir==2 || dir==3)
                if (i==2 || i==3) continue;
            
            int flag = 0;
            while(1) {
                nrr+=dir_r[i]; nrc+=dir_c[i]; nbr+=dir_r[i]; nbc+=dir_c[i];
                if (map[nrr][nrc]=='O') {
                    flag = 2;
                }
                    
                
                if (map[nbr][nbc]=='O') {
                    flag = 1;
                    break;
                }
                
                if (map[nrr][nrc]=='#' && map[nbr][nbc]=='#') {
                    nrr-=dir_r[i]; nrc-=dir_c[i];
                    nbr-=dir_r[i]; nbc-=dir_c[i];
                    break;
                }
                if (map[nrr][nrc]=='#') {
                    nrr-=dir_r[i]; nrc-=dir_c[i];
                    if (nrr==nbr&&nrc==nbc) {
                        nbr-=dir_r[i]; nbc-=dir_c[i];
                        break;
                    }
                }
                if (map[nbr][nbc]=='#') {
                    nbr-=dir_r[i]; nbc-=dir_c[i];
                    if (nrr==nbr&&nrc==nbc) {
                        nrr-=dir_r[i]; nrc-=dir_c[i];
                        break;
                    }
                }
            }
            
            if (flag == 0) {
                if (nrr==info.rr && nrc==info.rc && nbr==info.br && nbc==info.bc) continue;
                if (check[nrr][nrc][nbr][nbc]) continue;
                check[nrr][nrc][nbr][nbc] = true;
                q.push({nrr,nrc,nbr,nbc,num+1,i});
            } else if (flag == 2) {
                ans = num+1;
                break;
            }
        }
        
        if (ans!=-1) break;
    }
    
    printf("%d", ans);
    return 0;
}
