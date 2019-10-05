//
//  main.cpp
//  17143. 낚시왕
//
//  Created by carrot on 05/10/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

/*
   {r,c}
   d => 1:up 2:down 3:right 4:left
   s : speed, z : size
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define loop(a,b,c) for(int a=b; a<c; a++)
using namespace std;
int R,C,M, m[1001][1001], dir_r[]={0,-1,1,0,0}, dir_c[]={0,0,0,1,-1};
struct shark { int r,c,s,d,z; };

bool comp(const shark& a, const shark& b) {
    return (a.z>b.z?true:false);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d %d %d", &R, &C, &M);
    vector<shark> vc;
    
    loop(i,0,M) {
        int r,c,s,d,z;
        scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
        vc.push_back({r,c,s,d,z});
    }
    
    // 초기 낚시왕의 위치 0,0
    int pos=0, amt=0;
    while(++pos!=C+1) {
        if (vc.empty()) break;
        // pos에서 가장 가까운 상어 찾아서 amt에 더하기
        int target=-1, min=R+1;
        loop (i,0,vc.size())
            if (vc[i].c==pos && min>vc[i].r) {
                target=i; min=vc[i].r;
            }
        if (target!=-1) {
            amt += vc[target].z;
            vc.erase(vc.begin()+target);
        }
        
        // 크기별로 정렬 후
        sort(vc.begin(), vc.end(), comp);
        
        // 상어 이동
        loop(i,0,vc.size()) {
            shark s = vc[i];
            int nr=s.r, nc=s.c, dist;
            // 속도*1 만큼 이동할때 범위 확인
            if (s.d==1 || s.d==2) {
                dist = s.s%((R-1)*2);
            } else {
                dist = s.s%((C-1)*2);
            }
            
            while(dist>0) {
                nr+=dir_r[s.d]; nc+=dir_c[s.d];
                if (0>=nr||nr>R||0>=nc||nc>C) {
                    nr-=dir_r[s.d]; nc-=dir_c[s.d];
                    if (s.d==1) s.d=2;
                    else if (s.d==2) s.d=1;
                    else if (s.d==3) s.d=4;
                    else s.d=3;
                } else dist--;
            }
            
            // map에 이미 상어가 있으면 잡아먹힘
            if (m[nr][nc]) {
                vc.erase(vc.begin()+i);
                i--;
            } else {
                vc[i].r=nr; vc[i].c=nc;
                vc[i].d=s.d;
                m[nr][nc]=s.z;
            }
        }
        loop(i,0,vc.size()) m[vc[i].r][vc[i].c]=0;
    }
    
    printf("%d", amt);
    return 0;
}

/*
int nr=s.r,nc=s.c,t=s.s;
while(t>0) {
    nr+=dir_r[s.d]; nc+=dir_c[s.d];
    if (0>=nr||nr>R||0>=nc||nc>C) {
        nr-=dir_r[s.d]; nc-=dir_c[s.d];
        if (s.d==1) s.d=2;
        else if (s.d==2) s.d=1;
        else if (s.d==3) s.d=4;
        else s.d=3;
    } else t--;
}
 */
