//
//  main.cpp
//  3019. 테트리스
//
//  Created by carrot on 18/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
using namespace std;
int C,P,map[100],ans;
int main(int argc, const char * argv[]) {
    // insert code here...
    
    scanf("%d %d", &C, &P);
    for (int i=0; i<C; i++) scanf("%d", &map[i]);
    
    /*
     1 : 0 / 0000
     2 : 00 / 00
     3 : 001 / 10
     4 : 100 / 01
     5 : 000 / 01 / 101 / 10
     6 : 000 / 00 / 011 / 20
     7 : 000 / 02 / 110 / 00
     */
    
    if (P==1) {
        ans += C;
        for (int i=0; i<=C-4; i++) if (map[i]==map[i+1] && map[i+1]==map[i+2] && map[i+2]==map[i+3]) ans++;
    } else if (P==2) {
        for (int i=0; i<=C-2; i++) if (map[i]==map[i+1]) ans++;
    } else if (P==3) {
        for (int i=0; i<=C-3; i++) if (map[i]==map[i+1] && map[i+1]==(map[i+2]-1)) ans++;
        for (int i=0; i<=C-2; i++) if ((map[i]-1)==map[i+1]) ans++;
    } else if (P==4) {
        for (int i=0; i<=C-3; i++) if ((map[i]-1)==map[i+1] && map[i+1]==map[i+2]) ans++;
        for (int i=0; i<=C-2; i++) if (map[i]==(map[i+1]-1)) ans++;
    } else if (P==5) {
        for (int i=0; i<=C-3; i++) if (map[i]==map[i+1] && map[i+1]==map[i+2]) ans++;
        for (int i=0; i<=C-2; i++) if (map[i]==(map[i+1]-1)) ans++;
        for (int i=0; i<=C-3; i++) if ((map[i]-1)==map[i+1] && map[i+1]==(map[i+2]-1)) ans++;
        for (int i=0; i<=C-2; i++) if ((map[i]-1)==map[i+1]) ans++;
    } else if (P==6) {
        for (int i=0; i<=C-3; i++) if (map[i]==map[i+1] && map[i+1]==map[i+2]) ans++;
        for (int i=0; i<=C-2; i++) if (map[i]==map[i+1]) ans++;
        for (int i=0; i<=C-3; i++) if (map[i]==(map[i+1]-1) && (map[i+1]-1)==(map[i+2]-1)) ans++;
        for (int i=0; i<=C-2; i++) if ((map[i]-2)==map[i+1]) ans++;
    } else {
        for (int i=0; i<=C-3; i++) if (map[i]==map[i+1] && map[i+1]==map[i+2]) ans++;
        for (int i=0; i<=C-2; i++) if (map[i]==map[i+1]) ans++;
        for (int i=0; i<=C-3; i++) if ((map[i]-1)==(map[i+1]-1) && (map[i+1]-1)==map[i+2]) ans++;
        for (int i=0; i<=C-2; i++) if (map[i]==(map[i+1]-2)) ans++;
    }
    
    printf("%d", ans);
    return 0;
}
