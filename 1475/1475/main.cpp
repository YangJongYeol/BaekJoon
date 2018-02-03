//
//  main.cpp
//  1475
//
//  Created by 양종열 on 2018. 2. 4..
//  Copyright © 2018년 양종열. All rights reserved.
//

#include<iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    string n;
    cin >> n;
    
    int arr[10] = {0};
    
    for (int i=0; i<n.length(); i++) {
        int temp = n[i]-48;
        arr[temp]++;
    }
    
    int num =0;
    for(int i=0; i< 10; i++){
        if(i!=9 && i!=6) num = max(num, arr[i]);
    }
    
    cout << max(num, (arr[6] + arr[9] + 1) /2);
    return 0;
}
