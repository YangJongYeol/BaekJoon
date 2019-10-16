//
//  main.cpp
//  14890. 경사로
//
//  Created by carrot on 2019/10/15.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#define loop(a,b,c) for(int a=b; a<(int)c ; a++)
using namespace std;
int N, L, ans, map[100][100];
bool bridge[100][100];

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> L;
    loop(i,0,N) loop(j,0,N) cin >> map[i][j];
    
    loop(i,0,N) {
        bool isOk=true;
        loop(j,0,N-1) {
            if (map[i][j]==map[i][j+1]) continue;
            else if (map[i][j]+1==map[i][j+1]) {
                if (j-L+1 < 0) { isOk=false; break; }
                loop(k,j-L+1,j+1) {
                    if (map[i][j]!=map[i][k] || bridge[i][k]) {
                        isOk=false; break;
                    } else bridge[i][k]=true;
                }
                if (!isOk) break;
            } else if (map[i][j]==map[i][j+1]+1) {
                if (j+L > N) { isOk=false; break; }
                loop(k,j+1,j+L+1) {
                    if (map[i][j+1]!=map[i][k] || bridge[i][k]) {
                        isOk=false; break;
                    } else bridge[i][k]=true;
                }
                if (!isOk) break;
            } else { isOk=false; break; }
        }
        if (isOk)
            ans++;
    }
    
    loop(i,0,N) loop(j,0,N) bridge[i][j]=false;
    loop(j,0,N) {
        bool isOk=true;
        loop(i,0,N-1) {
            if (map[i][j]==map[i+1][j]) continue;
            else if (map[i][j]+1==map[i+1][j]) {
                if (i-L+1 < 0) { isOk=false; break; }
                loop(k,i-L+1,i+1) {
                    if (map[i][j]!=map[k][j] || bridge[k][j]) {
                        isOk=false; break;
                    } else bridge[k][j]=true;
                }
                if (!isOk) break;
            } else if (map[i][j]==map[i+1][j]+1) {
                if (i+L > N) { isOk=false; break; }
                loop(k,i+1,i+L+1) {
                    if (map[i+1][j]!=map[k][j] || bridge[k][j]) {
                        isOk=false; break;
                    } else bridge[k][j]=true;
                }
                if (!isOk) break;
            } else { isOk=false; break; }
        }
        if (isOk)
            ans++;
    }
    
    cout << ans;
    return 0;
}
