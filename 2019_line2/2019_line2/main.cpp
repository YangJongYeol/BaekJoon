//
//  main.cpp
//  2019_line2
//
//  Created by carrot on 22/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
string line; int d,cnt; vector<char> vc; vector<string> arr;

void dfs(int c, string a, bool* visited) {
    if (c==cnt) {
        arr.push_back(a);
        return;
    }
    
    for (int i=0; i<cnt; i++) {
        if (visited[i]) continue;
        
        visited[i]=true;
        dfs(c+1,a+vc[i],visited);
        visited[i]=false;
    }
}

bool comp(const string &a, const string &b) {
    return (stoi(a)>stoi(b)? false:true);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    getline(std::cin,line);
    scanf("%d", &d);
    
    for (int i=0; i<line.length(); i+=2)
        vc.push_back(line[i]);
    
    cnt = (int)vc.size();
    bool visited[cnt]; for (int i=0; i<cnt; i++) visited[i] = false;
    for (int i=0; i<cnt; i++) {
        visited[i] = true;
        string str = "";
        str += vc[i];
        dfs(1,str,visited);
        visited[i] = false;
    }
    
    sort(arr.begin(), arr.end(), comp);
    printf("%s", arr[d-1].c_str());
    return 0;
}
