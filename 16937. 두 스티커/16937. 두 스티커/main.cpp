#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#define loop(a,b,c) for(int a=b; a<c; a++)
using namespace std;
int N,M,D,enemy,ans,map[15][15];
struct Archer {int pos[2], target[3];};

int getDist(int ar, int ac, int br, int bc) {
    return (abs(ar-br)+abs(ac-bc));
}

void game_start(int comb) {
    int e=enemy;
    vector<Archer> archer;
    int tmp[15][15];
    loop(i,0,N) loop(j,0,M) tmp[i][j]=map[i][j];
    loop(i,0,M) if(comb&(1<<i)) archer.push_back({{N,i},{-1,-1,11}});
    
    int amt=0;
    do {
        // atack
        loop(k,0,archer.size()) {
            bool isAttack=false;
            for (int i=N-1; i>=N-D; i--) {
                loop(j,0,M) {
                    if (tmp[i][j]==1 || tmp[i][j]==-1) {
                        int dist = getDist(i,j,archer[k].pos[0],archer[k].pos[1]);
                        if (dist<=D) {
                            if (dist < archer[k].target[2]) { archer[k].target[0]=i; archer[k].target[1]=j; archer[k].target[2]=dist; }
                            else if (dist == archer[k].target[2]) {
                                if (archer[k].target[1] > j) { archer[k].target[0]=i; archer[k].target[1]=j; archer[k].target[2]=dist; }
                            }
                        }
                    }
                }
                if (isAttack) break;
            }
        }
        loop(k,0,archer.size()) {
            tmp[archer[k].target[0]][archer[k].target[1]] = -1;
            archer[k].target[0]=-1; archer[k].target[1]=-1; archer[k].target[2]=11;
        }
        
        // enemy_move
        loop(j,0,M) {
            if (tmp[N-1][j]==1) e--;
            if (tmp[N-1][j]==-1) {e--; amt++;}
            tmp[N-1][j]=0;
        }
        for (int i=N-2; i>=0; i--) loop(j,0,M) {
            if(tmp[i][j]==-1) {tmp[i][j]=0; e--; amt++;}
            tmp[i+1][j]=tmp[i][j];
        }
        loop(j,0,M) tmp[0][j]=0;
    } while(e!=0);
    
    if (amt>ans) ans=amt;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> D;
    loop(i,0,N) loop(j,0,M) { cin >> map[i][j]; if (map[i][j]==1) enemy++; }
    
    // set archer position
    queue<pair<int,int>> q;
    loop(i,0,M) q.push(make_pair(1<<i,1));
    
    while(!q.empty()) {
        pair<int,int> p = q.front(); q.pop();
        if (p.second==3) { game_start(p.first); }
        loop(i,0,M) {
            if (p.first&(1<<i)) break;
            q.push(make_pair(p.first|(1<<i),p.second+1));
        }
    }
    
    cout << ans;
    return 0;
}
