//
//  main.cpp
//  1233. 사칙연산 유효성 검사
//
//  Created by carrot on 08/07/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <stdio.h>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    for (int tc=1; tc<=10; tc++) {
        int n=0; bool flag = false;
        scanf("%d",&n);
        
        if (n%2==0) {
            flag = true;
        }
        
        for (int i=1; i<=n; i++) {
            int index; char symbol; int left=-1, right=-1;
        
            scanf("%d %c", &index, &symbol);
            if (n >= 2*i) scanf("%d", &left);
            if (n > 2*i) scanf("%d", &right);
            
            if (!flag && left == -1 && (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')) flag = true;
            if (!flag && right != -1 && (symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/')) flag = true;
        }
        
        if (flag) printf("#%d %d\n",tc,0);
        else printf("#%d %d\n",tc,1);
        
    }
    
    return 0;
}
