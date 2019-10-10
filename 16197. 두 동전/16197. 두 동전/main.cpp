//
//  main.cpp
//  16197. 두 동전
//
//  Created by carrot on 07/10/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <queue>
#define loop(a,b,c) for(int a=b; a<c; a++)
using namespace std;
int ans,N,M,dir_r[]={1,-1,0,0},dir_c[]={0,0,1,-1};
char map[20][20];
bool visited[20][20][20][20];
struct Info{int ar,ac,br,bc;};

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d %d",&N,&M);
    Info inf={-1,-1,-1,-1};
    loop(i,0,N) loop(j,0,M) {
        scanf(" %1c",&map[i][j]);
        if(map[i][j]=='o') {
            if (inf.ar==-1) {inf.ar=i; inf.ac=j;}
            else {inf.br=i; inf.bc=j;}
        }
    }
    
    queue<Info> q;
    q.push(inf);
    visited[inf.ar][inf.ac][inf.br][inf.bc]=true;
    while(!q.empty()&&ans<10) {
        int size = (int)q.size();
        loop(t,0,size) {
            Info inf = q.front(); q.pop();
            loop(i,0,4) {
                int flag=0;
                int nar=inf.ar+dir_r[i], nac=inf.ac+dir_c[i], nbr=inf.br+dir_r[i], nbc=inf.bc+dir_c[i];
                if (0>nar||nar>=N||0>nac||nac>=M) flag++;
                if (0>nbr||nbc>=N||0>nbc||nbc>=M) flag++;
                
                if (flag==1) {
                    printf("%d",ans+1); return 0;
                }
                
                if(map[nar][nac]=='#') {nar=inf.ar; nac=inf.ac;}
                if(map[nbr][nbc]=='#') {nbr=inf.br; nbc=inf.bc;}
                if(flag==2||visited[nar][nac][nbr][nbc]) continue;
                visited[nar][nac][nbr][nbc]=true;
                q.push({nar,nac,nbr,nbc});
            }
        }
        ans++;
    }
    
    printf("-1");
    return 0;
}
