//
//  main.cpp
//  kakao2018_3
//
//  Created by carrot on 02/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    double arr[N+2], rate[N+1];
    for (int i=0; i<N+2; i++) arr[i]=0;
    for (int i=0; i<stages.size(); i++)
        arr[stages[i]]++;
    
    double size = (double)stages.size();
    rate[0] = 0; rate[1] = arr[1]/size;
    for (int i=2; i<N+1; i++) {
        size -= arr[i-1];
        if (size<=0) { rate[i] = 0; size = 0; }
        else rate[i] =arr[i]/size;
    }
    
    for (int i=1; i<N+1; i++)
        arr[i] = rate[i];
    
    sort(rate, rate+N+1);
    
    double pre=-1;
    for (int i=N; i>0; i--) {
        if (pre==rate[i]) continue;
        pre = rate[i];
        for (int j=1; j<=N; j++)
            if (rate[i]==arr[j])
                answer.push_back(j);
    }
        
    return answer;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> vc = solution(5, {2, 1, 2, 6, 2, 4, 3, 3});
    
    for (int i=0; i<vc.size(); i++)
        cout << vc[i] << " ";
    return 0;
}
