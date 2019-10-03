//
//  main.cpp
//  16928. 뱀과 사다리 게임
//
//  Created by carrot on 29/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <queue>
#include <map>
using namespace std;
int N, M, ans;
map<int,int> ladder, snake;
bool visited[101];

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d %d", &N, &M); ans=0;
    int a, b;
    for (int i=0; i<N; i++) { scanf("%d %d", &a, &b); ladder.insert(make_pair(a,b)); }
    for (int i=0; i<M; i++) { scanf("%d %d", &a, &b); snake.insert(make_pair(a,b)); }
    
    queue<pair<int,int>> q;
    q.push(make_pair(1,0)); visited[1] = true;
    while(!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        for (int i=1; i<=6; i++) {
            int next = p.first+i;
            if (ladder.count(next))
                next = ladder.at(next);
            else if (snake.count(next))
                next = snake.at(next);
            if (visited[next]) continue;
            
            if (next==100) {
                printf("%d", p.second+1);
                return 0;
            }
            
            visited[next] = true;
            q.push(make_pair(next,p.second+1));
        }
    }
    
    return 0;
}
