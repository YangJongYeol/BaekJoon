// 5648. 원자 소멸 시뮬레이션.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#pragma warning(disable: 4996)
#include <iostream>
#include <queue>
#include <cstring>
#define loop(a,b) for(int a=0; a<b; a++)
using namespace std;
int T, N, ans, map[4001][4001], dir_x[] = { 0,0,-1,1 }, dir_y[] = { 1,-1,0,0 };
struct Atom { int x, y, dir, energy; };

int main() {
	scanf("%d", &T);
	loop(t, T) {
		memset(map, 0, sizeof(map));
		ans = 0; queue<Atom> q,garbage;
		scanf("%d", &N);
		loop(i, N) {
			int x, y, dir, en;
			scanf("%d %d %d %d", &x, &y, &dir, &en);
			x = (x + 1000) * 2; y = (y + 1000) * 2;
			q.push({ x,y,dir,en });
			map[y][x] = en;
		}

		while (!q.empty()) {
			int size = (int)q.size();
			while(!garbage.empty()) {
				map[garbage.front().y][garbage.front().x] = 0;
				garbage.pop();
			}

			loop(k, size) {
				Atom atom = q.front(); q.pop();

				map[atom.y][atom.x] = 0;
				atom.x += dir_x[atom.dir];
				atom.y += dir_y[atom.dir];
				if (0 > atom.x || atom.x > 4000 || 0 > atom.y || atom.y > 4000) continue;	// out of bound
				if (map[atom.y][atom.x] > 0) {
					ans += (map[atom.y][atom.x] + atom.energy);
					map[atom.y][atom.x] = -1;
					garbage.push(atom);
				}
				else if (map[atom.y][atom.x] < 0) {
					ans += atom.energy;
				}
				else {
					map[atom.y][atom.x] = atom.energy;
					q.push(atom);
				}
			}
		}

		printf("#%d %d\n", t + 1, ans);
	}
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
