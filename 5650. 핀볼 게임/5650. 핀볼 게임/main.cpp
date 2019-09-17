#include <stdio.h>
int N, map[102][102], C;
int block[6][4] = {    // from 0:up, 1:right, 2:down, 3:left
    {-1, -1, -1, -1},
    {2, 3, 1, 0},
    {1, 3, 0, 2},
    {3, 2, 0, 1},
    {2, 0, 3, 1},
    {2, 3, 0, 1}
};
int wh[5][2][2];
int dir_r[4] = {-1, 0, 1, 0};
int dir_c[4] = {0, 1, 0, -1};

void dfs(int r, int c, int d, int a) {
    int nr = r;
    int nc = c;
    while(true) {
        do {
            nr = nr+dir_r[d];
            nc = nc+dir_c[d];
        } while(map[nr][nc]==0);
        
        if (map[nr][nc]==-1) {
            if (a>C) C=a;
            return;
        } else if (map[nr][nc]<6) {
            int nd = block[map[nr][nc]][d];
            //dfs(nr, nc, nd, a+1);
            a++; d=nd;
        } else {
            int tmp = map[nr][nc]-6;
            int wr=-1, wc=-1;
            if (wh[tmp][0][0] == nr && wh[tmp][0][1] == nc) {
                wr = wh[tmp][1][0];
                wc = wh[tmp][1][1];
            } else if (wh[tmp][1][0] == nr && wh[tmp][1][1] == nc) {
                wr = wh[tmp][0][0];
                wc = wh[tmp][0][1];
            } else return;
            
            //dfs(wr, wc, d, a);
            nr=wr; nc=wc;
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int T;
    scanf("%d", &T);
    
    
    for (int t=1; t<=T; t++) {
        scanf("%d", &N);
        
        for (int i=0; i<5; i++) {
            for (int j=0; j<2; j++) {
                wh[i][j][0] = -1;
                wh[i][j][1] = -1;
            }
        }
        
        for (int i = 0; i <= N + 1; i++)    // wall = 5
            map[i][0] = map[i][N + 1] = 5;
        for (int i = 1; i <= N; i++)
            map[0][i] = map[N + 1][i] = 5;
        
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
                scanf("%d", &map[i][j]);
                if (map[i][j]>=6) {
                    if (wh[map[i][j]-6][0][0]==-1) {
                        wh[map[i][j]-6][0][0]=i; wh[map[i][j]-6][0][1]=j;
                    } else {
                        wh[map[i][j]-6][1][0]=i; wh[map[i][j]-6][1][1]=j;
                    }
                }
            }
        }
        C = 0;
        
        for (int i=1; i<=N; i++)
            for (int j=1; j<=N; j++)
                if (map[i][j]==0) {
                    for (int k=0; k<4; k++) {
                        map[i][j] = -1;
                        dfs(i,j,k,0);
                        map[i][j] = 0;
                    }
                }
        
        printf("#%d %d\n", t, C);
    }
    
    return 0;
}

