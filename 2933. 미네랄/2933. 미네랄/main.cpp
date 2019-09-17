//
//  main.cpp
//  2933. 미네랄
//
//  Created by carrot on 04/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int R,C,N,row,r,c,dir_r[]={0,0,1,-1}, dir_c[]={1,-1,0,0}, t_amt;
vector<pair<int, int>> vc;
char map[100][100];
bool visited[100][100];
bool side;

void show() {
    for (int i=R-1; i>=0; i--) {
        printf("\n");
        for (int j=0; j<C; j++) printf("%c", map[i][j]);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d %d", &R, &C);
    for (int i=R-1; i>=0; i--)
        for (int j=0; j<C; j++) {
            scanf(" %1c", &map[i][j]);
            if (map[i][j]=='x') t_amt++;
        }
    
    scanf("%d", &N);
    for (int n=0; n<N; n++) {
        side = !side;
        scanf("%d", &row); row -= 1;
        
        // --------------------------------------- throw & remove
        r=row; bool flag = false;
        if (side) {
            c=0;
            while(map[r][c]!='x') {
                if (c==C-1) {flag = true; break;}
                c++;
            }
        } else {
            c=C-1;
            while(map[r][c]!='x') {
                if (c==0) {flag = true; break;}
                c--;
            }
        }
        map[r][c] = '.';
        
        if (flag) continue;
        t_amt--;
        
        // --------------------------------------- check cluster is sparated
        while(1) {
            for (int r=0; r<R; r++) for (int c=0; c<C; c++) visited[r][c]=false;
            
            
            for (int i=0; i<C; i++)
                if (map[0][i]=='x' && !visited[0][i]) {
                    queue<pair<int, int>> q;
                    q.push(make_pair(0, i));
                    visited[0][i] = true;
                    while(!q.empty()) {
                        pair<int, int> p = q.front(); q.pop();
                        for (int j=0; j<4; j++) {
                            int nr = p.first + dir_r[j]; int nc = p.second + dir_c[j];
                            
                            if (0<=nr && nr<R && 0<=nc && nc<C) {
                                if (visited[nr][nc]) continue;
                                if (map[nr][nc]=='x') {
                                    visited[nr][nc] = true;
                                    q.push(make_pair(nr, nc));
                                }
                            }
                        }
                    }
                }
            
            int amt=0;
            for (int i=0; i<R; i++)
                for (int j=0; j<C; j++)
                    if (visited[i][j]) amt++;
            
            if (amt==t_amt) break;
            
            for (int i=0; i<R; i++) for (int j=0; j<C; j++) if (!visited[i][j] && map[i][j]=='x') vc.push_back(make_pair(i, j));
            
            int m_amt = R;
            for (int i=0; i<vc.size(); i++) {
                int r = vc[i].first; int c = vc[i].second; amt = 0;
                while(1) {
                    r--;
                    if (r==-1 || (map[r][c]=='x' && visited[r][c])) break;
                    if (map[r][c] == '.' || (map[r][c]=='x' && !visited[r][c])) amt++;
                }
                if (amt < m_amt) m_amt=amt;
            }
            
            for (int i=0; i<vc.size(); i++) {
                int r = vc[i].first; int c = vc[i].second;
                map[r][c] = '.'; map[r-m_amt][c] = 'x';
            }
            vc.clear();
            //show();
        }
                
    }
    
    for (int i=R-1; i>=0; i--) {
        for (int j=0; j<C; j++) printf("%c", map[i][j]);
        printf("\n");
    }
    return 0;
}



//        int c_idx = 0;
//        for (int i=R-1; i>=0; i--)
//            for (int j=0; j<C; j++) {
//                if (map[i][j]=='x' && !visited[i][j]) {
//                    c_idx++;
//                    queue<pair<int,int>> q;
//                    q.push(make_pair(i,j));
//                    while(!q.empty()) {
//                        pair<int,int> p = q.front(); q.pop();
//                        map[p.first][p.second] = c_idx+'0';
//                        for (int k=0; k<4; k++) {
//                            int nr = p.first + dir_r[k]; int nc = p.second + dir_c[k];
//
//                            if (0<=nr && nr<R && 0<=nc && nc<C) {
//                                if (visited[nr][nc]) continue;
//                                if (map[nr][nc]=='x') q.push(make_pair(nr, nc));
//                            }
//                        }
//                    }
//                }
//            }

// --------------------------------------- if so, cal fall amt
//        if (c_idx != 0) {
//            vector<pair<int, int>> vc[c_idx];
//            for (int i=R-1; i>=0; i--)
//                for (int j=0; j<C; j++)
//                    if (map[i][j]!='x' && map[i][j]!='.')
//                        vc[map[i][j]-'0'].push_back(make_pair(i, j));
//
//            int m_amt = R, m_idx = 0;
//            for (int i=0; i<c_idx; i++) {
//                for (int j=0; j<vc[i].size(); j++) {
//                    int r = vc[i][j].first; int c = vc[i][j].second; int amt = 0;
//                    while(1) {
//                        r--;
//                        if (r==-1 || map[r][c]=='x') break;
//                        if (map[r][c] == '.' || map[r][r]==map[vc[i][j].first][vc[i][j].second]) amt++;
//                    }
//                    if (amt < m_amt) {m_amt=amt; m_idx=i;}
//                }
//            }
