#include<iostream>
#include<queue>
#include <vector>
#include <set>
#include <algorithm>
#define loop(a,b) for(int a=0; a<b; a++)
using namespace std;
int room_idx,max_size,max_union,n,m,map[50][50],dir_r[]={0,-1,0,1},dir_c[]={-1,0,1,0}, visited[50][50];
vector<int> room;
set<pair<int,int> > neighbor;

int main() {
    scanf("%d %d",&n,&m); room_idx=1; room.push_back(0);
    loop(i,m) loop(j,n) scanf("%d",&map[i][j]);

    // cal room num & size & store room info
    loop(i,m) loop(j,n) {
        if (visited[i][j]) continue;

        // bfs
        int amt=1;
        queue<pair<int,int> > q;
        q.push(make_pair(i,j)); visited[i][j]=room_idx;
        while(!q.empty()) {
            pair<int,int> p = q.front(); q.pop();
            int walls=map[p.first][p.second];
            loop(t,4) {
                int nr=p.first+dir_r[t], nc=p.second+dir_c[t];
                if (0>nr||nr>=m||0>nc||nc>=n) continue;
                if(walls&(1<<t)) {
                    if (visited[nr][nc] && visited[p.first][p.second]!=visited[nr][nc])
                        neighbor.insert(make_pair(visited[nr][nc],visited[p.first][p.second]));
                    continue;
                }
                if (visited[nr][nc]) continue;
                amt++; visited[nr][nc]=room_idx;
                q.push(make_pair(nr,nc));
            }
        }

        // store room info
        if (max_size<amt) max_size=amt;
        room.push_back(amt); room_idx++;
    }

    // cal max_union
    for(auto ite=neighbor.begin(); ite!=neighbor.end(); ite++) {
        pair<int,int> p=*ite;
        int amt=room[ite->first]+room[ite->second];
        if (max_union<amt) max_union=amt;
    }

    printf("%d\n%d\n%d",room_idx-1,max_size,max_union);
    return 0;
}