//
//  main.cpp
//  17140. 이차원 배열과 연산
//
//  Created by carrot on 05/10/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#define loop(a,b) for (int a=1; a<=b; a++)
using namespace std;
int r,c,k,m[101][101];
int R,C;

bool comp(const pair<int,int>& a, const pair<int,int>& b) {
    if (a.second < b.second) return true;
    else if (a.second == b.second) {
        if (a.first < b.first) return true;
        else return false;
    } else
        return false;
}

void show() {
    printf("\n");
    loop(i,R) {
        loop(j,C) printf("%d ", m[i][j]);
        printf("\n");
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d %d %d", &r, &c, &k); R=3; C=3;
    loop(i,3) loop(j,3) scanf("%d",&m[i][j]);
    
    int times=0;
    while(m[r][c]!=k) {
        if (times++==100) break;
        if (R>=C) {
            int inc=0;
            loop(i,R){
                map<int,int> map;
                loop(j,C) {
                    if(!m[i][j]) continue;
                    if (map.count(m[i][j])) map.at(m[i][j])++;
                    else map[m[i][j]]=1;
                }
                
                vector<pair<int,int>> vc;
                for (auto ite=map.begin(); ite!=map.end(); ite++)
                    vc.push_back(*ite);
                
                sort(vc.begin(), vc.end(), comp);
                
                loop (j,R) m[i][j]=0;
                for (int j=1; j<=vc.size()*2; j+=2) {
                    m[i][j]=vc[j/2].first;
                    m[i][j+1]=vc[j/2].second;
                    if (j==101) break;
                }
                if ((int)vc.size()*2>inc) inc=(int)vc.size()*2;
            }
            C=(inc>100?100:inc);
//            show();
        } else {
            int inr=0;
            loop(i,C){
                map<int,int> map;
                loop(j,R) {
                    if (!m[j][i]) continue;
                    if (map.count(m[j][i])) map.at(m[j][i])++;
                    else map[m[j][i]]=1;
                }
                
                vector<pair<int,int>> vc;
                for (auto ite=map.begin(); ite!=map.end(); ite++)
                    vc.push_back(*ite);
                
                sort(vc.begin(), vc.end(), comp);
                
                loop(j,R) m[j][i]=0;
                for (int j=1; j<=vc.size()*2; j+=2) {
                    m[j][i]=vc[j/2].first;
                    m[j+1][i]=vc[j/2].second;
                    if (j==101) break;
                }
                if ((int)vc.size()*2>inr) inr=(int)vc.size()*2;
            }
            R=(inr>100?100:inr);
//            show();
        }
    }
    
    printf("%d", (times==101?-1:times));
    return 0;
}
