//
//  main.cpp
//  1229.암호문2
//
//  Created by carrot on 23/05/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    for (int tc=1; tc<=10; tc++) {
        int N;
        cin >> N;

        string tmp;
        vector<string> vc;
        for (int i=0; i<N; i++) {
            cin >> tmp;
            vc.push_back(tmp);
        }
        
        int M;
        cin >> M;
        
        char ch;
        int x, y;
        string s;
        for (int i=0; i<M; i++) {
            cin >> ch;
            
            if (ch == 'I') {
                cin >> x >> y;
                
                for (int j=0; j<y; j++) {
                    cin >> s;
                    vc.insert(vc.begin()+x+j, s);
                }
            } else if (ch == 'D') {
                cin >> x >> y;
                vc.erase(vc.begin()+x, vc.begin()+x+y);
            } else if (ch == 'A') {
                cin >> y;
                for (int j=0; j<y; j++) {
                    cin >> s;
                    vc.push_back(s);
                }
            }
        }
        
        cout << "#" << tc << " ";
        for (int i=0; i<10; i++) {
            cout << vc[i] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
