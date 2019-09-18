//
//  main.cpp
//  12886. 돌 그룹
//
//  Created by carrot on 10/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
using namespace std;
struct Info {
    int a,b,c;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[3];
    scanf("%d %d %d",&arr[0],&arr[1],&arr[2]);
    if (arr[0]==arr[1] && arr[1]==arr[2]) { printf("1"); return 0; }
    sort(arr,arr+3);
    set<string> s;
    queue<Info> q;
    q.push({arr[0],arr[1],arr[2]});
    s.insert(to_string(arr[0])+to_string(arr[1])+to_string(arr[2]));
    while (!q.empty()) {
        Info inf = q.front(); q.pop();
        if (s.count(to_string(inf.a)+to_string(inf.b)+to_string(inf.c))) continue;
        if (inf.b > inf.a) {
            int tmp[3] = {inf.a+inf.a,inf.b-inf.a,inf.c};
            if (tmp[0]==tmp[1] && tmp[1]==tmp[2]) { printf("1"); return 0; }
            sort(tmp,tmp+3);
            if (!s.count(to_string(tmp[0])+to_string(tmp[1])+to_string(tmp[2]))) {
                q.push({tmp[0],tmp[1],tmp[2]});
                s.insert(to_string(tmp[0])+to_string(tmp[1])+to_string(tmp[2]));
            }
        }
        if (inf.c > inf.a) {
            int tmp[3] = {inf.a+inf.a,inf.b,inf.c-inf.a};
            if (tmp[0]==tmp[1] && tmp[1]==tmp[2]) { printf("1"); return 0; }
            sort(tmp,tmp+3);
            if (!s.count(to_string(tmp[0])+to_string(tmp[1])+to_string(tmp[2]))) {
                q.push({tmp[0],tmp[1],tmp[2]});
                s.insert(to_string(tmp[0])+to_string(tmp[1])+to_string(tmp[2]));
            }
        }
        if (inf.c > inf.b) {
            int tmp[3] = {inf.a,inf.b+inf.b,inf.c-inf.b};
            if (tmp[0]==tmp[1] && tmp[1]==tmp[2]) { printf("1"); return 0; }
            sort(tmp,tmp+3);
            if (!s.count(to_string(tmp[0])+to_string(tmp[1])+to_string(tmp[2]))) {
                q.push({tmp[0],tmp[1],tmp[2]});
                s.insert(to_string(tmp[0])+to_string(tmp[1])+to_string(tmp[2]));
            }
        }
    }
    
    
    printf("0");
    return 0;
}

