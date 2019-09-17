//
//  main.cpp
//  kakao2019_1
//
//  Created by carrot on 07/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool comp(int idx, string s, string ss) {
    for (int i=0; i<ss.length(); i++)
        if (ss[i]!=s[i+idx]) return false;
    
    return true;
}

string make_ss(int idx, int count, string s) {
    string ss = "";
    for (int i=idx; i<idx+count; i++)
        ss += s[i];
    return ss;
}

int solution(string s) {
    int answer = (int)s.length();
    
    string tmp; int count;
    for (int length=3; length<s.length(); length++) {
        tmp = ""; count=0;
        for (int i=0; i<=s.length()-length; i++) {
            // ss 뽑기
            
            string ss = make_ss(i,length,s);
            // s와 ss비교하기
            while (comp(i,s,ss)) {
                count +=1;
                i += length;
            }
            i -= 1;
            
            if (count!=1) tmp = tmp+to_string(count)+ ss;
            else tmp += ss;
            count = 0;
                // true면 count+1
                // false
                    // count!=1 이면 숫자+ss
                    // count==1 이면 ss
            
            //i += length;
            if (i==s.length()-1) {
                if (tmp.length() < answer)
                    answer = (int)tmp.length();
                break;
            } else if (i+length>s.length()-1) {
                if (tmp.length()+s.length()-i-1 < answer)
                    answer = (int)tmp.length()+(int)s.length()-i-1;
                break;
            }
        }
    }
    
    return answer;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    string a = "abcabcdede";
    printf("%d", solution(a));
    
    return 0;
}
