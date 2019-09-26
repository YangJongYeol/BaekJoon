//
//  main.cpp
//  2019_line1
//
//  Created by carrot on 22/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
using namespace std;
int a, b;
int message[10], consumer[10];

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d %d", &a, &b);
    for (int i=0; i<a; i++)
        scanf("%d",&message[i]);
    
    // consumer개수 별로 진행
    int time=0, idx=0;
    for (; time<1000; time++){
        // 컨슈머에서 처리하는 놈이 없으면
        bool flag = true;
        for (int i=0; i<b; i++) {
            if (--consumer[i]<=0) {
                if (idx!=a) {
                    flag = false;
                    consumer[i] = message[idx++];
                }
            } else {
                flag = false;
            }
        }
        
        if (flag) break;
            // 새로운 메세지를 넣는다.
            // 메세지가 없으면 pass
        
        // 메세지도 , 컨슈머도 없으면 끝
    }
    
    printf("%d", time);
    return 0;
}
