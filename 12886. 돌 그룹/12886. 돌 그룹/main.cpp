//
//  main.cpp
//  12886. 돌 그룹
//
//  Created by carrot on 10/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[3];
    scanf("%d %d %d",&arr[0],&arr[1],&arr[2]);
    while(1) {
        sort(arr,arr+3);
        if (arr[0]==arr[1] && arr[1]==arr[2]) break;
        if (arr[2]/arr[0]==0) {
            printf("0");
            return 0;
        }
        arr[2]-=arr[0]; arr[0]*=2;
    }
    
    printf("1");
    return 0;
}
