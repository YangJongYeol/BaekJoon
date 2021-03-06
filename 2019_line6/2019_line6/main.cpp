//
//  main.cpp
//  2019_line6
//
//  Created by carrot on 22/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
using namespace std;
int N, size[100], height;
string str, num[100];
char number[11][5][3] = {
{ {'#','#','#'}, {'#','*','#'}, {'#','*','#'}, {'#','*','#'}, {'#','#','#'} },
{ {'*','*','#'}, {'*','*','#'}, {'*','*','#'}, {'*','*','#'}, {'*','*','#'} },
{ {'#','#','#'}, {'*','*','#'}, {'#','#','#'}, {'#','*','*'}, {'#','#','#'} },
{ {'#','#','#'}, {'*','*','#'}, {'#','#','#'}, {'*','*','#'}, {'#','#','#'} },
{ {'#','*','#'}, {'#','*','#'}, {'#','#','#'}, {'*','*','#'}, {'*','*','#'} },
{ {'#','#','#'}, {'#','*','*'}, {'#','#','#'}, {'*','*','#'}, {'#','#','#'} },
{ {'#','*','*'}, {'#','*','*'}, {'#','#','#'}, {'#','*','#'}, {'#','#','#'} },
{ {'#','#','#'}, {'*','*','#'}, {'*','*','#'}, {'*','*','#'}, {'*','*','#'} },
{ {'#','#','#'}, {'#','*','#'}, {'#','#','#'}, {'#','*','#'}, {'#','#','#'} },
{ {'#','#','#'}, {'#','*','#'}, {'#','#','#'}, {'*','*','#'}, {'*','*','#'} },
};
  ;

void print(string num){
    for (int i=0; i<5; i++) {
        for (int t=0; t<num.length(); t++) {
            int a = (int)(num[t]-'0');
            for (int j=0; j<3; j++)
                    cout << number[a][i][j];
            cout<<" ";
        }
        cout << "\n";
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> str;
    
    for (int i=0; i<N; i++) {
        cin >> size[i] >> num[i];
        if (size[i]*2-1>height) height = size[i]*2-1;
    }
    
    for (int i=0; i<N; i++) {
        print(num[i]);
    }
    
    return 0;
}
