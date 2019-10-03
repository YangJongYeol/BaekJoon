//
//  main.cpp
//  2383. 점심 식사시간
//
//  Created by carrot on 26/08/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include <bitset>
#define loop(a,b) for (int a=0; a<b; a++)
#define MIN() min(arr[0],min(arr[1],arr[2]))
#define MAX() max(arr[0],max(arr[1],arr[2]))
using namespace std;
int T, N, pnum, snum, ans, map[10][10];
pair<int,int> stair[2];
pair<int,int> person[10];

int calDist(int a, int b) {
    return abs(person[a].first-stair[b].first) + abs(person[a].second-stair[b].second);
}

void check(int comb) {
    vector<int> vc[2];
    int times[2]={0,0};
    loop (i,pnum) {
        if (comb&(1<<i)) vc[0].push_back(calDist(i,0));
        else vc[1].push_back(calDist(i,1));
    }
    
    sort(vc[0].begin(), vc[0].end());
    sort(vc[1].begin(), vc[1].end());
    
    loop(t,2) {
        int tDown=map[stair[t].first][stair[t].second];
        if (vc[t].empty()) times[t]=0;
        else if ((int)vc[t].size()<=3) times[t]=vc[t][vc[t].size()-1]+tDown+1;
        else {
            int arr[3]; loop(i,3) arr[i]=vc[t][i]+tDown+1;
            for (int i=3; i<vc[t].size(); i++) {
                int tmp = MIN();
                loop(j,3) if(arr[j]==tmp) {
                    if (arr[j]>vc[t][i]) {
                        arr[j]=arr[j]+tDown;
                        break;
                    } else {
                        arr[j]=vc[t][i]+tDown+1;
                        break;
                    }
                }
            }
            
            times[t]=MAX();
        }
    }
    
    int result = max(times[0],times[1]);
    if (result<ans)
        ans=result;
}

void make_set() {
    queue<int> q;
    loop(i,pnum) q.push(1<<i);
    
    check(0);
    while(!q.empty()) {
        int comb=q.front(); q.pop();
        loop(i,pnum) {
            if (comb&(1<<i)) { check(comb); break; }
            q.push(comb|(1<<i));
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d" , &T);
    for (int t=1; t<=T; t++) {
        snum=0; pnum=0; ans=100000000; scanf("%d", &N);
        loop(i,N) loop(j,N) {
            scanf("%d", &map[i][j]);
            if (map[i][j]==1) person[pnum++]=make_pair(i,j);
            if (map[i][j]>1) stair[snum++]=make_pair(i,j);
        }
        
        make_set();
        printf("#%d %d\n", t, ans);
    }
    
    return 0;
}


//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//int T,N,map[10][10],times,stairs[2][2],sindex,pnum;
//struct Info {
//    int r, c, amt;
//};
//Info inf[10];
//
//bool comp (const Info& A, const Info& B) {
//    return (A.amt<B.amt? true:false);
//}
//
//void cal(int s) {
//    vector<Info> vcA, vcB;
//    for (int i=0; i<pnum; i++) {
//        if (s&(1<<i)) {
//            inf[i].amt = abs(inf[i].r-stairs[0][0]) + abs(inf[i].c-stairs[0][1]);
//            vcA.push_back(inf[i]);
//        } else {
//            inf[i].amt = abs(inf[i].r-stairs[1][0]) + abs(inf[i].c-stairs[1][1]);
//            vcB.push_back(inf[i]);
//        }
//    }
//
//    sort(vcA.begin(), vcA.end(), comp);
//    sort(vcB.begin(), vcB.end(), comp);
//    int cA = 0, cB = 0;
//    if (!vcA.empty()) {
//        cA = vcA[(vcA.size()-1)%3].amt+map[stairs[0][0]][stairs[0][1]]+1;
//        if (vcA.size()>3) {
//            for (int i=(vcA.size()-1)%3+3; i<vcA.size(); i+=3) {
//                cA = cA+(vcA[i].amt-vcA[i-3].amt)+map[stairs[0][0]][stairs[0][1]];
//            }
//        }
//    }
//
//    if (!vcB.empty()) {
//        cB = vcB[(vcB.size()-1)%3].amt+map[stairs[1][0]][stairs[1][1]]+1;
//        if (vcB.size()>3) {
//            for (int i=(vcB.size()-1)%3+3; i<vcB.size(); i+=3) {
//                cB = cB + (vcB[i].amt-vcB[i-3].amt)+map[stairs[1][0]][stairs[1][1]];
//            }
//        }
//    }
//    if (cA<cB && times>cB)
//        times = cB;
//    if (cB<=cA && times>cA)
//        times = cA;
//}
//
//void select(int s, int c, int num) {
//    if (c==num)
//        cal(s);
//
//    for (int i=0; i<pnum; i++) {
//        if (s&(1<<i)) break;
//        select(s|(1<<i),c+1,num);
//    }
//}
//
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    scanf("%d" , &T);
//    for (int t=1; t<=T; t++) {
//        scanf("%d", &N); times=1000000000; sindex=0; pnum=0;
//        for (int i=0; i<N; i++)
//            for (int j=0; j<N; j++) {
//                scanf("%d", &map[i][j]);
//                if (map[i][j]>1) {
//                    stairs[sindex][0] = i;
//                    stairs[sindex++][1] = j;
//                }
//                if (map[i][j]==1) inf[pnum++]={i,j,0};
//            }
//
//        select(0,0,0);
//        for (int i=0; i<=pnum; i++) {
//            for (int j=0; j<pnum; j++) {
//                select(1<<j, 1, i);
//            }
//        }
//
//        printf("#%d %d\n", t, times);
//    }
//
//    return 0;
//}
