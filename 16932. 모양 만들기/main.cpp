#include <iostream>
#include <vector>
#include <set>
#define loop(a,b) for(int a=0; a<b; a++)
using namespace std;
int N, M, ans, map[1000][1000], dir_r[]={-1,0,1,0}, dir_c[]={0,1,0,-1};
bool visited[1000][1000];
vector<pair<int,int> > vc, group;

int dfs(int r, int c, int idx) {
    int amt=0; map[r][c]=idx;
    visited[r][c]=true;
    loop(i,r) {
        int nr=r+dir_r[i], nc=c+dir_c[i];
        if (0>nr||nr>=N||0>nc||nc>=M) continue;
        if (visited[nr][nc]) continue;

        dfs(nr,nc);
        amt++;
    }

    return amt;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    loop(i,N) loop(j,M) {
        cin >> map[i][j];
        vc.push_back(make_pair(i,j));
    }

    loop(i,vc.size()) {
        if (visited[vc[i].first][vc[j].second])
            group.push_back(make_pair(idx,dfs(vc[i].first, vc[i].second, idx++)));
    }

    loop(i,N) {
        loop(j,M) cout << map[i][j] << " ";
        cout << "\n";
    }

    cout << ans;
    return 0;
}