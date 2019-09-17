//
//  main.cpp
//  kakao2019_4
//
//  Created by carrot on 07/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const string a, const string b) {
    if (a.length() < b.length()) return true;
    else if (a.length()==b.length()) {
        if (a<b) return true;
        else return false;
    }
    return false;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    vector<pair<int,int>> index;
    
    sort(words.begin(), words.end(), comp);
//    sort(queries.begin(), queries.end(), comp);
    
    for (int i=0; i<words.size(); i++) {
        int len = (int)words[i].length();
        bool flag = false;
        for (int j=0; j<index.size(); j++) {
            if (index[j].first==len) {flag=true; break;}
        }
        if (!flag)
            index.push_back(make_pair(len,i));
    }
    
    for (int i=0; i<queries.size(); i++) {
        int count = 0; bool idx = (queries[i][0]=='?'?true:false);
        int len = 0; int j=0;
        for (int k=0; k<index.size(); k++)
            if (index[k].first==len) j=len;
        for (; j<words.size(); j++) {
            bool flag = true;
            if (queries[i].length()>words[j].length()) continue;
            if (queries[i].length()<words[j].length()) break;
            if (!idx) {
                for (int k=0; k<words[j].length(); k++) {
                    if (queries[i][k]=='?') { flag = true; break; }
                    if (queries[i][k]==words[j][k]) continue;
                    if (queries[i][k]!=words[j][k]) { flag = false; break; }
                }
            } else {
                for (int k=(int)words[j].length()-1; k>=0; k--) {
                    if (queries[i][k]=='?') { flag = true; break; }
                    if (queries[i][k]==words[j][k]) continue;
                    if (queries[i][k]!=words[j][k]) { flag = false; break; }
                }
            }
            
            if (flag) count++;
        }
        
        answer.push_back(count);
    }
        
    
    return answer;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    solution({"frodo", "front", "frost", "frozen", "frame", "kakao"}, {"fro??", "????o", "fr???", "fro???", "pro?"});
    return 0;
}
