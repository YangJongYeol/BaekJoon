//
//  main.cpp
//  1240. 단순 2진 암호코드
//
//  Created by carrot on 12/05/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
string binary_code[10] = {
    "0001101",  //0
    "0011001",  //1
    "0010011",  //2
    "0111101",  //3
    "0100011",  //4
    "0110001",  //5
    "0101111",  //6
    "0111011",  //7
    "0110111",  //8
    "0001011"
};

// 0111101 0110111 0111011 0101111 0011001 0111011 0010011 0001101

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int tc;
    cin >> tc;
    
    for (int i=0; i<tc; i++) {
        bool flag = false;
        int N, M;
        cin >> N >> M;
        
        string code[N];
        string barcode[8];
        int num[8];
        for (int j=0; j<N; j++) {
            cin >> code[j];
            
            if (flag) { continue; }
            
            if (code[j].find("1") != -1) {    // code가 있는 라인을 찾음
                
                //0000 0111011 0110001 0111011 0110001 0110001 0001101 0010011 0111011 0000000000
                // 75755027
                // 맨 마지막 1의 자리를 찾자.
                for (int k=M-1; k>=0; k--) {
                    if (code[j][k]=='1') { // 맨 마지막 1의 자리를 찾음
                        for (int l=7; l>=0; l--) {   // 해당 위치부터 8자리 끊어서 저장.
                            barcode[l] = code[j].substr(k-6,7);
                            k = k-7;
                        }
                        break;
                    }
                }
                
                // 이진 코드를 변환하자.
                for (int k=0; k<8; k++) {
                    for (int l=0; l<10; l++) {
                        if (barcode[k].compare(binary_code[l]) == 0) {
                            num[k] = l;
                            break;
                        }
                    }
                }
                
                // 정상인지 체크하자.
                int checkSum = (num[0]+num[2]+num[4]+num[6])*3 + (num[1]+num[3]+num[5]) + num[7];
                int sum = 0;
                if (checkSum % 10 == 0) {
                    for (int k=0; k<8; k++) {
                        sum += num[k];
                    }
                }
                
                cout << "#" << i+1 << " " << sum << "\n";
                
                flag = true;
            }
        }
    }
    
    return 0;
}
