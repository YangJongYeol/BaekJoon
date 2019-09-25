#pragma warning(disable: 4996)
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;
int N, M, map[100][100], dir_r[] = { 0,0,1,-1 }, dir_c[] = { 1,-1,0,0 }, ans, idx, graph[7][7], island[7];
bool visited[100][100];

int find(int a) {
	if (island[a] == a) return a;
	else {
		int p = find(island[a]);
		island[a] = p;
		return p;
	}
}

void union_set(int a, int b) {
	int na = find(a);
	int nb = find(b);
	if (na != nb) {
		ans += graph[a][b];
		island[nb] = na;
	}
}

int main() {
	scanf("%d %d", &N, &M); ans = 0;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) scanf("%d", &map[i][j]);
	for (int i = 1; i < 7; i++) for (int j = 1; j < 7; j++) graph[i][j] = 100;
	for (int i = 1; i < 7; i++) island[i] = i;

	// 1. island idexing
	idx = 1; vector<pair<int, int>> vc;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
		if (map[i][j] && !visited[i][j]) {
			queue < pair<int, int>> q;
			q.push(make_pair(i, j));
			visited[i][j] = true;
			map[i][j] = idx;
			vc.push_back(make_pair(i, j));
			while (!q.empty()) {
				pair<int, int> p = q.front(); q.pop();
				for (int j = 0; j < 4; j++) {
					int r = p.first + dir_r[j]; int c = p.second + dir_c[j];
					if (0 <= r && r < N && 0 <= c && c < M) {
						if (map[r][c] == 0 || visited[r][c]) continue;
						map[r][c] = idx; visited[r][c] = true;
						q.push(make_pair(r, c));
					}
				}
			}
			idx++;
		}
	}

	// 2. connect
	for (int i = 0; i < vc.size(); i++) {
		memset(visited, 0, sizeof(visited));
		int n = vc[i].first, m = vc[i].second;
		queue<pair<int, int>> q;
		q.push(make_pair(n, m)); visited[n][m] = true; int idx = map[n][m];
		while (!q.empty()) {
			pair<int, int> p = q.front(); q.pop();
			int r = p.first; int c = p.second;
			for (int i = 0; i < 4; i++) {
				int nr = r + dir_r[i]; int nc = c + dir_c[i];
				if (0 > nr || nr >= N || 0 > nc || nc >= M) continue;
				if (map[nr][nc] == idx && !visited[nr][nc]) {
					q.push(make_pair(nr, nc));
					visited[nr][nc] = true;
				}
			}

			for (int i = 0; i < 4; i++) {
				int cnt = 1;
				int nr = r + dir_r[i]; int nc = c + dir_c[i];
				if (0 > nr || nr >= N || 0 > nc || nc >= M) continue;
				while (!map[nr][nc]) {
					cnt++;
					nr += dir_r[i]; nc += dir_c[i];
					if (0 > nr || nr >= N || 0 > nc || nc >= M) {
						nr -= dir_r[i]; nc -= dir_c[i];
						break;
					}
				}
				cnt--;
				if (map[nr][nc] != 0) {
					int tmp = map[nr][nc];
					if (graph[idx][tmp] > cnt && cnt!=1) {
						graph[idx][tmp] = cnt; 
						graph[tmp][idx] = cnt;
					}
				}
			}

		}
	}

	vector<int> v;
	for (int i = 1; i <= vc.size(); i++) {
		for (int j = 1; j < i; j++) {
			v.push_back(graph[i][j]);
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 1 || v[i] == 100) continue;
		for (int j = 1; j <= vc.size(); j++) {
			for (int k = 1; k < j; k++) {
				if (graph[j][k] == v[i])
					union_set(j, k);
			}
		}
	}

	bool flag = false;
	int f = find(1);
	for (int i=1; i<=vc.size(); i++)
		if (island[find(i)] != f) {
			flag = true;
			break;
		}

	printf("%d", (flag?-1:ans));
	return 0;
}
