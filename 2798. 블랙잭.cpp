#pragma warning(disable: 4996)
#include <iostream>
using namespace std;
int N, M, cards[100], ans;

void comb(int c, int num) {
	if (num == 3) {
		int amt = 0;
		for (int i = 0; i < N; i++)
			if (c & (1 << i)) amt += cards[i];

		if (amt <= M && amt > ans) 
			ans = amt;

		return;
	}

	bool flag = false;
	for (int i = 0; i < N; i++) {
		if (c & (1 << i)) flag = true;
		if (flag && !(c & (1 << i))) 
			comb(c | (1 << i), num + 1);
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &cards[i]);
	for (int i = 0; i < N; i++) comb(1 << i, 1);
	printf("%d", ans);
	return 0;
}