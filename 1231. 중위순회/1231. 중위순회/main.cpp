//
//  main.cpp
//  1231. 중위순회
//
//  Created by carrot on 04/07/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    char word; int index, left, right;
};
vector<Node> vc;

void printInOrder(Node head) {
    if (head.left != -1) { printInOrder(vc[head.left]); }
    printf("%c",head.word);
    if (head.right != -1) { printInOrder(vc[head.right]); }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    for (int tc = 1; tc <= 10; tc++) {
        int n;
        cin >> n;
        
        vc.push_back({});
        for (int i=1; i<=n; i++) {
            int index, left=-1, right=-1; char word;
            cin >> index;
            cin >> word;
            
            if (n >= 2*i) cin >> left;
            if (n > 2*i) cin >> right;
            
            vc.push_back({word,index,left,right});
        }
        
        printf("#%d ",tc);
        printInOrder(vc[1]);
        printf("\n");
        
        vc.clear();
    }
    
    return 0;
}
