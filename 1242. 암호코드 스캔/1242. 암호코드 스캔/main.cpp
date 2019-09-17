//////
//////  main.cpp
//////  1242. 암호코드 스캔
//////
//////  Created by carrot on 14/07/2019.
//////  Copyright © 2019 carrot. All rights reserved.
//////
//
//#include <iostream>
//using namespace std;
//
//int code[5][5][5];
//char str[2001][501];
//
//int convert(char ch) {
//    if (ch >= 'A') return ((int)ch-'A'+10);
//    else return ((int)ch-'0');
//}
//
//int gcd(int a, int b) {
//    int c;
//    while (b!=0) {
//        c = a%b;
//        a = b;
//        b = c;
//    }
//
//    return a;
//}
//
//int main(int argc, const char * argv[]) {
//    code[2][1][1] = 0;
//    code[2][2][1] = 1;
//    code[1][2][2] = 2;
//    code[4][1][1] = 3;
//    code[1][3][2] = 4;
//    code[2][3][1] = 5;
//    code[1][1][4] = 6;
//    code[3][1][2] = 7;
//    code[2][1][3] = 8;
//    code[1][1][2] = 9;
//
//    // insert code here...
//    ios::sync_with_stdio(false); cin.tie(0);
//    int t;
//    cin >> t;
//
//    for (int tc=1; tc<=t; tc++) {
//        int ans = 0;
//        int col, wid;
//        cin >> col >> wid;
//
//        for (int i=0; i<col; i++) {
//            cin >> str[i];
//        }   // input
//
//        for (int i=0; i<col; i++) {
//            // if(stoi(str[i])==0) continue;            // check if code
//            for (int j=wid-1; j>=0; j--) {
//                if (str[i][j]=='0') continue;          // check if hex
//                if (str[i-1][j]=='0') {                // check if hex is first appearence
//                    int decode[8];
//                    int tmp = convert(str[i][j]);
//                    int cnt = 0;
//                    for (int idx = 0; idx <= 8; idx++) {    // We will make 8 digit code
//                        int ratio[4] = {0};
//                        for (int k=0; k<4; k++) {           // Each code has 4 ratio
////                            while ((tmp&1)==(k&1)) {        // 0&1 = 0, 1&1 = 1, 10(2)&1 = 0, 11(3)&1 = 1, 100(4)&1 = 0
////                                ratio[k]++;
////                                cnt++;
////                                tmp >>= 1;
////                                if (cnt == 4) {
////                                    cnt = 0;
////                                    j--;
////                                    tmp = convert(str[i][j]);    // if ratio doesn't complete 4 ratio, cal one more hex
////                                }
////                            }
////                        }
////
////                        int g = gcd(ratio[1], gcd(ratio[2], ratio[3]));
////                        decode[idx] = code[ratio[1]/g][ratio[2]/g][ratio[3]/g];
////                    }
////
////                    int sum = (decode[1]+decode[3]+decode[5]+decode[7])*3 +(decode[0]+decode[2]+decode[4]+decode[6]);
////                    if (sum%10==0) {
////                        for (int a=0; a<8; a++) { ans+=decode[a]; }
////                    }
////                }
////            }
////        }
////
////
////        printf("#%d %d", tc, ans);
////    }
////
////    return 0;
////}
#include <iostream>

using namespace std;

int T, R, C;
int ans;
char tmp;
char arr[2001][501];
char pw[8];
int code[5][5][5];

void init()
{
    code[2][1][1] = 0;
    code[2][2][1] = 1;
    code[1][2][2] = 2;
    code[4][1][1] = 3;
    code[1][3][2] = 4;
    code[2][3][1] = 5;
    code[1][1][4] = 6;
    code[3][1][2] = 7;
    code[2][1][3] = 8;
    code[1][1][2] = 9;
}

int convert(char c)
{
    if (c >= 'A')
        return c - 'A' + 10;
    else
        return c - '0';
}

int findMin(int a, int b, int c)
{
    int ret;
    ret = a < b ? a : b;
    ret = ret < c ? ret : c;
    return ret;
}

bool isValid()
{
    int sum = (pw[1] + pw[3] + pw[5] + pw[7]) * 3
    + pw[0] + pw[2] + pw[4] + pw[6];

    if (sum % 10 == 0)
        return true;
    else return false;
}

void solve()
{
    ans = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = C - 1; j >= 0; j--)
        {
            if (arr[i][j] == '0')
                continue;

            if (arr[i - 1][j] == '0')
            {
                tmp = convert(arr[i][j]);
                int cnt = 0; // 4비트씩
                for (int idx = 0; idx < 8; idx++)
                {
                    int chk[4] = { 0 };
                    for (int k = 0; k <= 3; k++)
                    {
                        while ((tmp & 1) == (k & 1))
                        {
                            chk[k]++;
                            cnt++;
                            tmp >>= 1;
                            if (cnt == 4)
                            {
                                cnt = 0;
                                j--;
                                tmp = convert(arr[i][j]);
                            }
                        }
                    }
                    int _min = findMin(chk[1], chk[2], chk[3]);
                    pw[idx] = code[chk[3] / _min][chk[2] / _min][chk[1] / _min];
                }
                if (isValid())
                    for (int p = 0; p < 8; p++)
                        ans += pw[p];
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        cin >> R >> C;
        for (int i = 0; i < R; i++)
            cin >> arr[i];

        solve();
        cout << "#" << tc << " " << ans << "\n";
    }
    return 0;
}


#include <iostream>
using namespace std;

int code[5][5][5];
char str[2001][501];

int convert(char ch) {
    if (ch >= 'A') return ((int)ch-'A'+10);
    else return ((int)ch-'0');
}

int gcd(int a, int b) {
    int c;
    while (b!=0) {
        c = a%b;
        a = b;
        b = c;
    }
    
    return a;
}

int main(int argc, const char * argv[]) {
    code[2][1][1] = 0;
    code[2][2][1] = 1;
    code[1][2][2] = 2;
    code[4][1][1] = 3;
    code[1][3][2] = 4;
    code[2][3][1] = 5;
    code[1][1][4] = 6;
    code[3][1][2] = 7;
    code[2][1][3] = 8;
    code[1][1][2] = 9;
    
    // insert code here...
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    
    for (int tc=1; tc<=t; tc++) {
        int ans = 0;
        int col, wid;
        cin >> col >> wid;
        
        for (int i=0; i<col; i++) {
            cin >> str[i];
        }   // input
        
        for (int i=0; i<col; i++) {
            for (int j=wid-1; j>=0; j--) {
                if (str[i][j]=='0') continue;          // check if hex
                if (str[i-1][j]=='0') {                // check if hex is first appearence
                    int decode[8];
                    int tmp = convert(str[i][j]);
                    int cnt = 0;
                    for (int idx = 0; idx <= 8; idx++) {    // We will make 8 digit code
                        int ratio[4] = {0};
                        for (int k=0; k<4; k++) {           // Each code has 4 ratio
                            while ((tmp&1)==(k&1)) {        // 0&1 = 0, 1&1 = 1, 10(2)&1 = 0, 11(3)&1 = 1, 100(4)&1 = 0
                                ratio[k]++;
                                cnt++;
                                tmp >>= 1;
                                if (cnt == 4) {
                                    cnt = 0;
                                    j--;
                                    tmp = convert(str[i][j]);    // if ratio doesn't complete 4 ratio, cal one more hex
                                }
                            }
                        }
                        
                        int g = gcd(ratio[1], gcd(ratio[2], ratio[3]));
                        decode[idx] = code[ratio[1]/g][ratio[2]/g][ratio[3]/g];
                    }
                    
                    int sum = (decode[1]+decode[3]+decode[5]+decode[7])*3 +(decode[0]+decode[2]+decode[4]+decode[6]);
                    if (sum%10==0) {
                        for (int a=0; a<8; a++) { ans+=decode[a]; }
                    }
                }
            }
        }
        
        
        printf("#%d %d", tc, ans);
    }
    
    return 0;
}
