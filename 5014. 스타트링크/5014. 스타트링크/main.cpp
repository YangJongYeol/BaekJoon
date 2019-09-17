//
//  main.cpp
//  5014. 스타트링크
//
//  Created by carrot on 04/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int F,S,G,U,D;  // S에서 G로 가야함 건물 높이는 F층 / 위로 U, 아래로 D
int ans,floor,size;
bool visited[1000001];

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
    if (S==G) {printf("0"); return 0;}
    
    queue<int> q;
    q.push(S); visited[S]=true;
    
    while (!q.empty()) {
        ans++; size = (int)q.size();
        for (int i=0; i<size; i++) {
            floor = q.front(); q.pop();
            
            if (floor+U==G || floor-D==G) {printf("%d",ans); return 0;}
            
            if ((floor+U)<=F && !visited[floor+U]) {
                visited[floor+U] = true; q.push(floor+U);
            }
            
            if ((floor-D)>=1 && !visited[floor-D]) {
                visited[floor-D] = true; q.push(floor-D);
            }
        }
    }
    
    printf("use the stairs");
    return 0;
}
