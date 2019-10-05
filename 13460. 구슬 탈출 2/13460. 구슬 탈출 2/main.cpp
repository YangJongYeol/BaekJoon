//
//  main.cpp
//  13460. 구슬 탈출 2
//
//  Created by carrot on 04/10/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <queue>
#define loop_up(a,b,c) for (int a=b; a<c; a++)
#define loop_down(a,b,c) for (int a=b; a>=c; a--)
using namespace std;
int N, M, ans, dir_r[]={-1,1,0,0}, dir_c[]={0,0,-1,1};
char map[10][10];
struct Info {
    int rr,rc,br,bc;
};

void show() {
    loop_up(i, 0, N) {
        loop_up(j,0,M) printf("%c", map[i][j]);
        printf("\n");
    }
}

void move(int i, int j, int dir) {
    int r=i, c=j;
     do {
        r+=dir_r[dir]; c+=dir_c[dir];
     } while(map[r][c]=='.');
    if (map[r][c]=='O') {
        map[i][j]='.';
    } else  {
        r-=dir_r[dir]; c-=dir_c[dir];
        if (r!=i || c!=j) {
            map[r][c]=map[i][j];
            map[i][j]='.';
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int rr=0,rc=0,br=0,bc=0;
    scanf("%d %d",&N, &M); ans=0;
    loop_up(i,0,N) loop_up(j,0,M) {
        scanf(" %c", &map[i][j]);
        if (map[i][j]=='R') {rr=i;rc=j;map[i][j]='.';}
        if (map[i][j]=='B') {br=i;bc=j;map[i][j]='.';}
    }
    
    queue<Info> q; q.push({rr,rc,br,bc});
    while(1) {
        int size = (int)q.size();
        if (size==0) {ans=11; break;}
        loop_up(t,0,size) {
            Info inf=q.front(); q.pop();
            loop_up(i, 0, 4) {
                map[inf.rr][inf.rc]='R'; map[inf.br][inf.bc]='B';
                if (i==0) {
                    if (inf.rr < inf.br) {
                        move(inf.rr,inf.rc,i);
                        move(inf.br,inf.bc,i);
                    } else {
                        move(inf.br,inf.bc,i);
                        move(inf.rr,inf.rc,i);
                    }
                } else if (i==1) {
                    if (inf.rr < inf.br) {
                        move(inf.br,inf.bc,i);
                        move(inf.rr,inf.rc,i);
                    } else {
                        move(inf.rr,inf.rc,i);
                        move(inf.br,inf.bc,i);
                    }
                } else if (i==2) {
                    if (inf.rc < inf.bc) {
                        move(inf.rr,inf.rc,i);
                        move(inf.br,inf.bc,i);
                    } else {
                        move(inf.br,inf.bc,i);
                        move(inf.rr,inf.rc,i);
                    }
                } else {
                    if (inf.rc < inf.bc) {
                        move(inf.br,inf.bc,i);
                        move(inf.rr,inf.rc,i);
                    } else {
                        move(inf.rr,inf.rc,i);
                        move(inf.br,inf.bc,i);
                    }
                }
                
                int nrr=0,nrc=0,nbr=0,nbc=0;
                bool isR=false, isB=false;
                loop_up(j,0,N) loop_up(k,0,M) {
                    if (map[j][k]=='R') { nrr=j; nrc=k; map[j][k]='.'; isR=true; }
                    if (map[j][k]=='B') { nbr=j; nbc=k; map[j][k]='.'; isB=true; }
                }
                if (isR && isB) {
                    if (nrr==inf.rr && nrc==inf.rc && nbr==inf.br && nbc==inf.bc) {}
                    else {
                        q.push({nrr,nrc,nbr,nbc});
                    }
                }
                if (!isR && isB) {
                    printf("%d",ans+1);
                    return 0;
                }
            }
        }
        
        if (++ans==10) break;
    }
    
    printf("-1");
    return 0;
}
