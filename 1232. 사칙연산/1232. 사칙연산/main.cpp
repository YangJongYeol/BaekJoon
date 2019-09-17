//
//  main.cpp
//  1232. 사칙연산
//
//  Created by carrot on 07/07/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int index, symbol, left, right;
    bool flag;
};
vector<Node> nodes;

void cal(int index) {
    if (nodes[index].flag) {
        if (nodes[nodes[index].left].flag)
            cal(nodes[index].left);
        if (nodes[nodes[index].right].flag)
            cal(nodes[index].right);
        
        int tmp = nodes[nodes[index].left].symbol;
        switch ((char)nodes[index].symbol) {
            case '+':
                tmp += nodes[nodes[index].right].symbol;
                break;
            case '-':
                tmp -= nodes[nodes[index].right].symbol;
                break;
            case '*':
                tmp *= nodes[nodes[index].right].symbol;
                break;
            case '/':
                tmp /= nodes[nodes[index].right].symbol;
                break;
        }
        
        nodes[index].symbol = tmp;
        nodes[index].flag = false;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    
    for (int tc = 1; tc <= 10; tc++) {
        int count;
        //cin >> count;
        scanf("%d",&count);
        
        nodes.push_back({});
        for (int i=0; i<count; i++) {
            Node n;
            //cin >> n.index;
            scanf("%d",&n.index);
            
            string tmp;
            cin >> tmp;
            if (tmp[0] == '+' || tmp[0] == '-' || tmp[0] == '*' || tmp[0] == '/') {
                n.symbol = tmp[0];
                // cin >> n.left;
                scanf("%d", &n.left);
                //cin >> n.right;
                scanf("%d", &n.right);
                n.flag = true;
            } else {
                n.symbol = atoi(tmp.c_str());
                n.left = -1;
                n.right = -1;
                n.flag = false;
            }
            
            nodes.push_back(n);
        }
        
        cal(1);
        //cout << "#" << tc << " " << nodes[1].symbol << endl;
        printf("#%d %d\n",tc,nodes[1].symbol);
        nodes.clear();
    }
    
    return 0;
}
