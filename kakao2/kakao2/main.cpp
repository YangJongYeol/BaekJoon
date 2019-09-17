//
//  main.cpp
//  kakao2
//
//  Created by carrot on 02/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<int> make_cs(int col) {
    vector<int> vc;
    queue<int> q;
    q.push(0); int p;
    while (!q.empty()) {
        p = q.front();
        q.pop();
        
        for (int i=0; i<col; i++) {
            if (p&(1<<i)) break;
            vc.push_back(p|(1<<i));
            q.push(p|(1<<i));
        }
    }
    
    return vc;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int col = (int)relation[0].size();
    
    vector<int> checked_cs;
    vector<int> cs;
    cs = make_cs(col);
    
    for (int i=0; i<cs.size(); i++) {
        bool flag = false;
        for (int j=0; j<checked_cs.size(); j++) {
            if ((checked_cs[j]&cs[i])==checked_cs[j]) {flag=true; break;}
            //printf("%d %d\n", checked_cs[j]&cs[i], cs[i]);
        }
        if (flag) continue;
        
        set<string> s;
        string tmp="";
        
        flag = true;
        for (int j=0; j<relation.size(); j++) {
            tmp = "";
            for (int k=0; k<relation[j].size(); k++)
                if (cs[i]&(1<<k)) tmp+=relation[j][k];
            
            if (s.count(tmp)) { flag=false; break; }
            else s.insert(tmp);
        }
        
        if (flag) {answer++; checked_cs.push_back(cs[i]);}
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<string>> vc = {
        {"100", "ryan", "music", "2"},{"200","apeach","math","2"},
        {"300","tube","computer","3"},{"400","con","computer","4"},
        {"500","muzi","music","3"},{"600","apeach","music","2"}
    };
    
    printf("%d",solution(vc));
    
    return 0;
}
