//
//  main.cpp
//  12906. 새로운 하노이 탑
//
//  Created by carrot on 10/10/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <set>
#define loop(a,b) for(int a=0; a<b; a++)
using namespace std;
//bool visited[3][3];
set<string> visited;
struct Info {
    int status[3][3];
    stack<char> detail[3];
};

string makeValue(Info inf) {
    string str="";
    loop(i,3) {
        while(!inf.detail[i].empty()) {
            str+=inf.detail[i].top();
            inf.detail[i].pop();
        }
        str+='/';
    }
    return str;
}

void setVisited(Info inf) {
    string str=makeValue(inf);
    visited.insert(str);
}

bool isVisited(Info inf) {
    string str=makeValue(inf);
    if(visited.count(str)) return true;
    return false;
}

bool isFinished(Info inf) {
    loop(i,3) {
        loop(j,3) {
            if (i==j) continue;
            if (inf.status[i][j]!=0) return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n; char c; Info init = {{0,0,0,0,0,0,0,0,0},};
    loop(i,3) {
        scanf("%d",&n);
        loop(j,n) {
            scanf(" %c", &c);
            init.detail[i].push(c);
            init.status[i][(int)(c-'A')]++;
        }
    }
    
    if(isFinished(init)) {printf("0"); return 0;}
    
    int ans=0;
    queue<Info> q;
    q.push(init);
    setVisited(init);
    while(!q.empty()) {
        int size=(int)q.size();
        loop(t,size) {
            Info inf=q.front(); q.pop();
            loop(i,3) {
                if (!inf.detail[i].empty()) {   // 해당 탑에 원판이 있으면
                    char pan = inf.detail[i].top(); inf.detail[i].pop();    // 넘길 원판
                    inf.status[i][(int)(pan-'A')]--;
                    loop(j,3) {                 // 다른 탑에 넘기자
                        if (i==j) continue;
                        inf.detail[j].push(pan);
                        inf.status[j][(int)(pan-'A')]++;
                        if(isFinished(inf)) {printf("%d",ans+1); return 0;} // 원판을 넘겼을때 조건에 만족하는지 확인
                        if(!isVisited(inf)) {
                            setVisited(inf);
                            q.push(inf);                    // 원판을 넘겼을때 기존에 있었던 케이스가 아니면 push
                        }
                        
                        inf.detail[j].pop();
                        inf.status[j][(int)(pan-'A')]--;
                    }
                    inf.status[i][(int)(pan-'A')]++;
                    inf.detail[i].push(pan);
                }
            }
        }
        ans++;
    }
    
    printf("%d",ans);
    return 0;
}
