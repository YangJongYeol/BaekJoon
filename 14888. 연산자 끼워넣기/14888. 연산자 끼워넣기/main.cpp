//
//  main.cpp
//  14888. 연산자 끼워넣기
//
//  Created by carrot on 06/10/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#define loop(a,b) for(int a=0; a<b; a++)
#define MAX 1000000000
#define MIN -1000000000
using namespace std;
int N, num[11], sym;
vector<int> vc;

int main(int argc, const char * argv[]) {
    // insert code here...
    scanf("%d",&N);
    loop(i,N) scanf("%d",&num[i]);
    loop(i,4) {
        scanf("%d",&sym);
        loop(j,sym) vc.push_back(i);
    }
    
    int highest=MIN, lowest=MAX, amt;
    do {
        amt=num[0];
        loop(i,vc.size()) {
            if (vc[i]==0)
                amt+=num[i+1];
            else if (vc[i]==1)
                amt-=num[i+1];
            else if (vc[i]==2)
                amt*=num[i+1];
            else
                amt/=num[i+1];
        }
        
        if (amt>highest) highest=amt;
        if (amt<lowest) lowest=amt;
    } while(next_permutation(vc.begin(), vc.end()));
    
    printf("%d\n%d",highest,lowest);
    return 0;
}
