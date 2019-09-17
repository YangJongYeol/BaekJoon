//
//  main.cpp
//  7272.안경이없어!
//
//  Created by carrot on 04/05/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

//  CEFGHI JKLMNS TUVWXY Z
//  ADOPQR
//  B

#include<iostream>
using namespace std;
int alphabet[26];
string type1 = "CEFGHIJKLMNSTUVWXYZ";
string type2 = "ADOPQR";

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int test_case;
    int T;

    cin>>T;
    
    for (int i=0; i<type1.length(); i++) { alphabet[type1[i]-'A'] = 1; }
    for (int i=0; i<type2.length(); i++) { alphabet[type2[i]-'A'] = 2; }
    alphabet['B'-'A'] = 3;
    
    bool flag;
    string str1, str2;

    for(test_case = 1; test_case <= T; ++test_case) {
        flag = true;
        
        cin >> str1 >> str2;
        if (str1.length() != str2.length()) {
            cout << "#" << test_case << " " << "DIFF" << endl;
        } else {
            for (int i=0; i<str1.length(); i++) {
                if(alphabet[str1[i]-'A'] != alphabet[str2[i]-'A']) {flag = false; break;}
            }
            
            if (flag) {
                cout << "#" << test_case << " " << "SAME" << endl;
            } else {
                cout << "#" << test_case << " " << "DIFF" << endl;
            }
        }
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}


//#include <iostream>
//#include <string>
//using namespace std;
//
//int tc, T, conf[26];
//string A, B;
//
//int main() {
//    string tmp1 = "CEFGHIJKLMNSTUVWXYZ", tmp2 = "ADOPQR";
//    for (int i = 0; i < tmp1.size(); i++) conf[tmp1[i] - 'A'] = 1;
//    for (int i = 0; i < tmp2.size(); i++) conf[tmp2[i] - 'A'] = 2;
//    conf['B' - 'A'] = 3;
//    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    cin >> T;
//    for (tc = 1; tc <= T; tc++) {
//        cin >> A >> B;
//        cout << "#" << tc << " ";
//        if (A.size() != B.size()) cout << "DIFF\n";
//        else {
//            int flag = 1;
//            for (int i = 0; i < A.size(); i++) {
//                if (conf[A[i] - 'A'] != conf[B[i] - 'A']) { flag = 0; break; }
//            }
//            if (flag) cout << "SAME\n";
//            else cout << "DIFF\n";
//        }
//    }
//    return 0;
//}
