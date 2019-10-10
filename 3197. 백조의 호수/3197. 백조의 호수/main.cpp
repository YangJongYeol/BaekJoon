//
//  main.cpp
//  3197. 백조의 호수
//
//  Created by carrot on 09/10/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <cmath>
#define loop(a,b) for(int a=0; a<b; a++)
using namespace std;
int R,C,t, dir_r[]={0,0,1,-1}, dir_c[]={1,-1,0,0};
int map[1500][1500];
bool visited[1500][1500];
struct Pos { int r, c; };
queue<Pos> swan;
queue<Pos> ice;

void melt() {
    // 물가 얼음을 저장해 놓는다.
    int size=(int)ice.size();
    loop(t,size) {
        int r=ice.front().r, c=ice.front().c;
        loop(i,4) {
            int nr=r+dir_r[i], nc=c+dir_c[i];
            if (0>nr||nr>=R||0>nc||nc>=C) continue;
            if(map[nr][nc]==-1) {   // 물가 얼음 주변에 얼음이 있는데
                bool flag=false;    // 그 얼음도 물가 얼음인지 확인
                loop(j,4) {
                    int tr=nr+dir_r[j], tc=nc+dir_c[j];
                    if (0>tr||tr>=R||0>tc||tc>=C) continue;
                    if (map[tr][tc]>=0) {flag=true; break;}
                }
                
                if (!flag)  // 이 얼음은 물가에 있는 얼음이 아니므로
                    ice.push({nr,nc});
            }
        }
        
        map[r][c]=0;
        ice.pop();
    }
    
//    printf("\n");
//    loop(i,R) {
//        loop(j,C) {
//            if (map[i][j]==0) printf(".");
//            else if (map[i][j]==-1) printf("X");
//            else printf(".");
//        }
//        printf("\n");
//    }
}

bool is_met() {
    // 이전 백조가 갈 수 있던 위치에서 0이 있는 곳으로만 이동
    queue<Pos> q;
    while(!swan.empty()) {
        int r=swan.front().r, c=swan.front().c, idx=map[r][c];
        swan.pop();
        loop(i,4) {
            int nr=r+dir_r[i], nc=c+dir_c[i];
            if (0>nr||nr>=R||0>nc||nc>=C) continue;
            
            if (map[nr][nc]==-1) {q.push({r,c}); continue;}
            if (map[nr][nc]==0) {
                map[nr][nc]=idx;
                swan.push({nr,nc});
                continue;
            }
            if (map[nr][nc]!=map[r][c])
                return true;
        }
        
//        printf("\n");
//        loop(i,R) {
//            loop(j,C) {
//                if (map[i][j]==0) printf(".");
//                else if (map[i][j]==-1) printf("X");
//                else if (map[i][j]==1) printf("1");
//                else printf("2");
//            }
//            printf("\n");
//        }
    }
    
    swap(q,swan);
    return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d %d",&R,&C); int idx=1;
    loop(i,R) loop(j,C) {
        char c;
        scanf(" %c", &c);
        if (c=='.') map[i][j]=0;
        if (c=='X') map[i][j]=-1;
        if (c=='L') { swan.push({i,j}); map[i][j]=idx++; }
    }
    
    loop(i,R) loop(j,C) {
        if(map[i][j]==-1) {
            loop(k,4) {
                int nr=i+dir_r[k], nc=j+dir_c[k];
                if (0>nr||nr>=R||0>nc||nc>=C) continue;
                if (map[nr][nc]>=0) {ice.push({i,j});}
            }
        }
    }
    
    while(++t) {
        melt();
        if (is_met()) break;
    }
    
    printf("%d",t);
    return 0;
}
