//
//  main.cpp
//  2382. 미생물 격리
//
//  Created by carrot on 27/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int T, N, M, K, map[2][100][100][3];
int dir_r[] = {0,-1,1,0,0};
int dir_c[] = {0,0,0,-1,1};
struct Info{
    int r,c,amt,dir;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        for (int i=0; i<2; i++) for (int j=0; j<100; j++) for (int k=0; k<100; k++) for (int l=0; l<3; l++) map[i][j][k][l]=0;
        
        scanf("%d %d %d", &N, &M, &K);
        bool cur = 0;
        queue<Info> q;
        for (int i=0; i<K; i++) {
            Info tmp;
            scanf("%d %d %d %d", &tmp.r, &tmp.c, &tmp.amt, &tmp.dir);
            map[cur][tmp.r][tmp.c][0] = tmp.amt;
            map[cur][tmp.r][tmp.c][1] = tmp.dir;
            map[cur][tmp.r][tmp.c][2] = tmp.amt;
            q.push(tmp);
        }
        
        while (M--) {
            bool pre = cur;
            cur = !pre;
            int size = (int)q.size();
            for (int i=0; i<size; i++) {
                Info inf = q.front();
                q.pop();
                if (map[pre][inf.r][inf.c][0]!=inf.amt) continue;
                
                map[pre][inf.r][inf.c][0] = 0;
                map[pre][inf.r][inf.c][1] = 0;
                map[pre][inf.r][inf.c][2] = 0;
                
                inf.r+=dir_r[inf.dir];
                inf.c+=dir_c[inf.dir];
                if ((inf.r==0 || inf.r==(N-1)) || (inf.c==0 || inf.c==(N-1))) {
                    if (inf.dir==1) inf.dir=2;
                    else if (inf.dir==2) inf.dir=1;
                    else if (inf.dir==3) inf.dir=4;
                    else inf.dir=3;
                    
                    inf.amt /= 2;
                    if (inf.amt) {
                        q.push(inf);
                        map[cur][inf.r][inf.c][0] = inf.amt;
                        map[cur][inf.r][inf.c][1] = inf.dir;
                        map[cur][inf.r][inf.c][2] = inf.amt;
                    }
                    continue;
                }
                
                if (map[cur][inf.r][inf.c][0]!=0) {
                    if (map[cur][inf.r][inf.c][2]<inf.amt) {
                        map[cur][inf.r][inf.c][1] = inf.dir;
                        map[cur][inf.r][inf.c][2] = inf.amt;
                    } else inf.dir = map[cur][inf.r][inf.c][1];
                    
                    map[cur][inf.r][inf.c][0] += inf.amt;
                    inf.amt = map[cur][inf.r][inf.c][0];
                    q.push(inf);
                    continue;
                }
                
                q.push(inf);
                map[cur][inf.r][inf.c][0] = inf.amt;
                map[cur][inf.r][inf.c][1] = inf.dir;
                map[cur][inf.r][inf.c][2] = inf.amt;
            }
        }
        
        int ans = 0;
        Info inf;
        while (!q.empty()) {
            inf = q.front();
            q.pop();
            if (map[cur][inf.r][inf.c][0]!=inf.amt) continue;
            ans += inf.amt;
        }
        
        printf("#%d %d\n", t, ans);
    }
    
    return 0;
}
