//
//  main.cpp
//  5656. 벽돌 깨기(1)
//
//  Created by carrot on 2019/10/16.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <queue>
#define loop(a,b) for(int a=0; a<b; a++)
#define MAX_H 15
#define MAX_W 12
using namespace std;
int T,N,W,H,ans,map[MAX_H][MAX_W],tmp[MAX_H][MAX_W],dir_h[]={-1,0,1,0},dir_w[]={0,1,0,-1};
struct Info { int h,w,dir,power; };

void dfs(int drop_w, int ball_num) {
    int h=0; while(!tmp[h][drop_w]) {if (h>=MAX_H) break; h++;}
    
    // explosion
    queue<Info> q;
    if(tmp[h][drop_w]!=1) {
        loop(i,4) {
            int nh=h+dir_h[i], nw=drop_w+dir_w[i];
            if (0>nh||nh>=H||0>nw||nw>=W) continue;
            q.push({nh,nw,i,tmp[h][drop_w]-1});
        }
    } tmp[h][drop_w]=0;
    
    while(!q.empty()) {
        Info inf = q.front(); q.pop();
        if (inf.power==0) continue;
        int nh=inf.h+dir_h[inf.dir], nw=inf.w+dir_w[inf.dir];
        if (0<=nh&&nh<H&&0<=nw&&nw<W) { q.push({nh,nw,inf.dir,inf.power-1}); }
        if (tmp[inf.h][inf.w]!=0) {
            loop(i,4) {
                nh=inf.h+dir_h[i]; nw=inf.w+dir_w[i];
                if (0>nh||nh>=H||0>nw||nw>=W) continue;
                q.push({nh,nw,i,tmp[inf.h][inf.w]-1});
            }
        }
        tmp[inf.h][inf.w]=0;
    }
    
//    cout << "\nbomb!\n"; loop(i,W) { loop(j,H) cout << tmp[i][j] << " "; cout <<"\n"; }
    
    //  fall
    bool flag;
    loop(i,W) do {
        flag=true;
        for (int j=H-1; j>=1; j--) if (tmp[j][i]==0 && tmp[j-1][i]!=0) { swap(tmp[j][i],tmp[j-1][i]); flag=false; }
    } while(!flag);
    int ttmp[15][12]; loop(i,H) loop(j,W) ttmp[i][j]=tmp[i][j];
    
//    cout << "\nfall!\n"; loop(i,W) { loop(j,H) cout << tmp[i][j] << " "; cout <<"\n"; }
    
    if (ball_num==N) {
        int amt=0;
        loop(i,H) loop(j,W) if(tmp[i][j]) amt++;
        if (amt<ans) {
//            cout << "\nresult!\n"; loop(i,W) { loop(j,H) cout << tmp[i][j] << " "; cout <<"\n"; }
            ans=amt;
        }
    } else {
        loop(t,W) {
            dfs(t,ball_num+1);
            loop(i,H) loop(j,W) tmp[i][j]=ttmp[i][j];
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int test_case=1; test_case<=T; test_case++) {
        cin >> N >> W >> H; ans=MAX_W*MAX_H+1;
        loop(i,H) loop(j,W) cin >> map[i][j];
        loop(t,W) {
            loop(i,H) loop(j,W) tmp[i][j]=map[i][j];
            dfs(t,1);
        }
        
        cout << "#" << test_case << " " << ans << "\n";
    }
    
    return 0;
}
