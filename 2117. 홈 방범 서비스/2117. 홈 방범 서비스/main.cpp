//
//  main.cpp
//  2117. 홈 방범 서비스
//
//  Created by carrot on 25/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
int map[20][20], T, N, M, ans, homes,
    area[13] = {0,1,5,13,25,41,84,112,144,180,220,264};
bool checked[20][20];
struct pos { int x, y; };
int dir_x[] = {0,0,1,-1};
int dir_y[] = {1,-1,0,0};

int cal(int x, int y, int K) {
    int amt = 0;
    
    for (int i=x-K; i<=x+K; i++)
        for (int j=y-K; j<=y+K; j++)
            if (0<=i && i<N && 0<=j && j<N)
                if (((abs(x-i)+abs(y-j))<=K) && map[i][j])
                    amt++;
    
    return amt;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        scanf("%d %d", &N, &M); ans = 0; homes = 0;
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++) {
                scanf("%d", &map[i][j]);
                checked[i][j] = false;
                
                if (map[i][j]) homes++;
            }
        
        int K = N;
        if (homes*M > (K*K+(K+1)*(K+1))) ans = homes;
        else {
            queue<pos> q;
            q.push({N/2, N/2});
            checked[N/2][N/2] = true;
            int range = 0;
            while(--K) {
                pos p = q.front();
                q.pop();
                for (int i=p.x-range; i<=p.x+range; i++)
                    for (int j=p.y-range; j<=p.y+range; j++)
                        if (0<=i && i<N && 0<=j && j<N)
                            if ((abs(p.x-i)+abs(p.y-j))<=range) {
                                q.push({i,j});
                                int tmp = cal(i,j,K);
                                if (((tmp*M)>(K*K+(K+1)*(K+1))) && (tmp > ans))
                                    ans = tmp;
                            }
                
                if (area[K-1]<ans) break;
                range++;
            }
        }
        if (ans==0) ans=1;
        printf("#%d %d\n", t, ans);
    }
    return 0;
}
