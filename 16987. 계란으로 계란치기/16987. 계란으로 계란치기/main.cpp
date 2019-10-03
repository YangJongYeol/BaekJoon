//
//  main.cpp
//  16987. 계란으로 계란치기
//
//  Created by carrot on 28/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

/*
 각 계란에는 내구도와 무게가 정해져있다.
 계란으로 계란을 치게 되면 각 계란의 내구도는 상대 계란의 무게만큼 깎이게 된다.
 내구도가 0 이하가 되는 순간 계란은 깨지게 된다
 
 가장 왼쪽의 계란을 든다.
 손에 들고 있는 계란으로 깨지지 않은 다른 계란 중에서 하나를 친다.
    단, 손에 든 계란이 깨졌거나 깨지지 않은 다른 계란이 없으면 치지 않고 넘어간다. 이후 손에 든 계란을 원래 자리에 내려놓고 3번 과정을 진행한다.
 가장 최근에 든 계란의 한 칸 오른쪽 계란을 손에 들고 2번 과정을 다시 진행한다.
    단, 가장 최근에 든 계란이 가장 오른쪽에 위치한 계란일 경우 계란을 치는 과정을 종료한다.
 */

#include <iostream>
using namespace std;
int N, egg[9][2], ans;
bool is_hit[9];

void func(int idx, int amt) {
    if (idx==N+1) {
        if (ans<amt)
            ans=amt;
        return;
    }

    if (egg[idx][0]<=0) {
        func(idx+1, amt);
        return ;
    }
    
    bool flag = true;
    for (int i=1; i<=N; i++) {
        int num = 0;
        if (idx==i) continue;
        if (is_hit[i]) continue;
        if (egg[i][0]<=0) continue;
        flag = false;
        int w1 = egg[idx][0], w2 = egg[i][0];
        egg[idx][0] -= egg[i][1]; egg[i][0] -= egg[idx][1];
        is_hit[idx] = true; is_hit[i] = true;
        if (egg[idx][0]<=0) num++; if (egg[i][0]<=0) num++;
        if (egg[idx][0]<=0) func(idx+1,amt+num);
        else func(idx,amt+num);
        is_hit[i] = false; is_hit[idx] = false;
        egg[idx][0] = w1; egg[i][0] = w2;
    }
    
    if (flag)
        func(idx+1, amt);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d", &N); ans=0;
    for (int i=1; i<=N; i++) scanf("%d %d", &egg[i][0], &egg[i][1]);
    is_hit[1]=true;
    func(1, 0);
    
    printf("%d", ans);
    return 0;
}
