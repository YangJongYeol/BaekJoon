//
//  main.cpp
//  1949. 등산로 조성
//
//  Created by carrot on 2019/10/15.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#define loop(a,b,c) for(int a=b; a<c; a++)
#define MAX(A,B) (A)>(B)?(A):(B)
using namespace std;
int T,N,K,ans,top,map[8][8],dir_r[]={-1,0,1,0},dir_c[]={0,1,0,-1};

void dfs(int r, int c, int br, int bc, bool usage, int amt) {
    bool flag=false;
    loop(i,0,4) {
        int nr=r+dir_r[i], nc=c+dir_c[i];
        if (0>nr||nr>=N||0>nc||nc>=N) continue;
        if (map[nr][nc]<map[r][c]) { flag=true; dfs(nr,nc,r,c,usage,amt+1); }
        else {
            if (usage && (map[nr][nc]-K < map[r][c])) {
                if (nr==br && nc==bc) continue;
                flag=true;
                int tmp = map[nr][nc];
                map[nr][nc] = map[r][c]-1;
                dfs(nr,nc,r,c,false,amt+1);
                map[nr][nc] = tmp;
            }
        }
    }
    
    if (!flag)
        ans=MAX(ans,amt);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    loop(t,1,T+1) {
        cin >> N >> K; ans=0; top=0;
        loop(i,0,N) loop(j,0,N) {
            cin >> map[i][j];
            if (top<map[i][j]) top=map[i][j];
        }
        
        loop(i,0,N) loop(j,0,N) if (map[i][j]==top) dfs(i,j,-1,-1,true,1);
        cout << "#" << t << " " << ans << "\n";
    }
    return 0;
}
