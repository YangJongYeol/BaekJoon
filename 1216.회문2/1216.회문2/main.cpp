#include <iostream>
#include <cstring>
using namespace std;
char map[100][100];

int search(int length) {
    bool flag1 = false;
    bool flag2 = false;
    
    for (int i=0; i<100; i++) {
        for (int j=0; j<=100-length; j++) {
            for (int k=0; k<length/2; k++) {
                if (map[i][j+k]!=map[i][j+length-1-k]) {
                    flag1 = true;
                    break;
                }
            }
            
            for (int k=0; k<length/2; k++) {
                if (map[j+k][i]!=map[j+length-1-k][i]) {
                    flag2 = true;
                    break;
                }
            }
            
            if (!flag1) { return length; }
            else { flag1 = false; }
            
            if (!flag2) { return length; }
            else { flag2 = false; }
        }
    }
    
    return search(length-1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int tc = 0;
    while (tc != 10) {
        cin >> tc;
        memset(map, 0, sizeof(map));
        
        for (int i=0; i<100; i++) {
            cin >> map[i];
        }
        
        cout << "#" << tc << " " << search(100) << endl;
    }
    
    return 0;
}
