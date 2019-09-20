//
//  main.cpp
//  16235. 나무 재테크
//
//  Created by carrot on 20/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N,M,K,map[101][101], energy[101][101];
vector<int> vc[101][101];

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d %d %d", &N, &M, &K);
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) {
        scanf("%d",&energy[i][j]);
        map[i][j]=5;
    }
    for (int i=0; i<M; i++) {
        int r,c,age;
        scanf("%d %d %d", &r, &c, &age);
        vc[r][c].push_back(age);
    }
    
    for (int i=0; i<K; i++) {
        // spring
            // 어린 나무부터 양분을 먹는다.
        for (int r=1; r<=N; r++) {
            for (int c=1; c<=N; c++) {
                sort(vc[r][c].begin(), vc[r][c].end());
                for (int s=0; s<vc[r][c].size(); s++) {
                    // 자신의 나이만큼의 양분이 있으면 그만큼 먹고 나이 +1
                    if (map[r][c]>=vc[r][c][s]) {
                        map[r][c]-=vc[r][c][s]; vc[r][c][s]++;
                    } else //             없으면 죽는다.
                        vc[r][c][s] *= -1;
                }
            }
        }
        
        // summer
        for (int r=1; r<=N; r++) {
            for (int c=1; c<=N; c++) {
                for (int s=0; s<vc[r][c].size(); s++) {
                    // 죽은 나무들의 나이/2 만큼 양분으로 변한다.
                    if (vc[r][c][s] < 0) {
                        map[r][c] = map[r][c]-vc[r][c][s]/2;
                        vc[r][c].erase(vc[r][c].begin()+s);
                        s--;
                    }
                }
            }
        }
        
        // autumn
        for (int r=1; r<=N; r++) {
            for (int c=1; c<=N; c++) {
                for (int s=0; s<vc[r][c].size(); s++) {
                    // 인접한 8개 칸에 번식 (나무의 나이가 5의 배수 && 번식된 나무 나이는 1)
                    if (vc[r][c][s]%5==0)
                        for (int k=-1; k<=1; k++)
                            for (int l=-1; l<=1; l++) {
                                if (k==0 && l==0) continue;
                                int nr = r+k; int nc = c+l;
                                if (1<=nr && nr<=N && 1<=nc && nc<=N)
                                    vc[nr][nc].push_back(1);
                            }
                }
            }
        }
        
        // winter
            // 처음에 줬던 양분을 추가해준다.
        for (int j=1; j<=N; j++) for (int k=1; k<=N; k++)
            map[j][k] += energy[j][k];

//      for debuging
//        printf("\n");
//        for (int j=0; j<vc.size(); j++)
//            printf("%d %d %d\n", vc[j].r,vc[j].c,vc[j].age);
//        for (int j=1; j<=N; j++) {
//            for (int k=1; k<=N; k++)
//                printf("%d ", map[j][k]);
//            printf("\n");
//        }
    }
    int size=0;
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
            size += vc[i][j].size();
    
    printf("%d", size);
    return 0;
}
