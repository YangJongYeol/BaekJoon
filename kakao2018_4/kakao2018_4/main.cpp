//
//  main.cpp
//  kakao2018_4
//
//  Created by carrot on 02/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 100000000

using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;//, smallest = 0, remains = 0, atleast = 0;
    long long amt = 0;
    
//    vector<int> forsort;
    
    for (int i=0; i<food_times.size(); i++) {
//        forsort.push_back(food_times[i]);
        amt += food_times[i];
    }
    if (amt <= k) return -1;
    
//    sort(forsort.begin(), forsort.end());
    k++;
//    while (1) {
////        remains = 0; smallest = 0;
////        for (answer=0; answer<food_times.size(); answer++) {
////            if(food_times[answer]>atleast) {
////                remains++;
////                if (smallest>food_times[answer] && food_times[answer]>atleast) smallest=food_times[answer];
////            }
////        }
//        int tmp = smallest+1;
//        for (int i=tmp; i<forsort.size(); i++) {
//            if (forsort[tmp]==forsort[smallest]) smallest++;
//        }
//
//        remains = (int)forsort.size()-smallest;
//        if (forsort[smallest]==forsort[0])
//            amt = forsort[smallest]*remains;
//        else
//            amt = (forsort[smallest]-forsort[atleast])*remains;
//        if (k-amt>0) {
////            for (answer=0; answer<food_times.size(); answer++) {
////                if(food_times[answer]!=0)
////                    food_times[answer] -= smallest;
////            }
//            atleast = smallest;
//            smallest++;
//            k -= amt;
//        } else {
            while(1) {
                if (answer==food_times.size()) answer=0;
                
//                if (forsort[smallest]==forsort[0]) {
//                    if (food_times[answer]>0) {
//                        food_times[answer]--;
//                        k--;
//                    }
//                } else {
                    if (food_times[answer]>0) {
                        food_times[answer]--;
                        k--;
                    }
//                }
                
                answer++;
                if (k==0) return answer;
            }
//        }
//    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    printf("%d\n", solution({5,2,3,4}, 1));
    printf("%d\n", solution({5,2,3,4}, 2));
    printf("%d\n", solution({5,2,3,4}, 3));
    printf("%d\n", solution({5,2,3,4}, 4));
    printf("%d\n", solution({5,2,3,4}, 5));
    printf("%d\n", solution({5,2,3,4}, 6));
    printf("%d\n", solution({5,2,3,4}, 7));
    printf("%d\n", solution({5,2,3,4}, 8));
    printf("%d\n", solution({5,2,3,4}, 9));
    printf("%d\n", solution({5,2,3,4}, 10));
    printf("%d\n", solution({5,2,3,4}, 11));
    printf("%d\n", solution({5,2,3,4}, 12));
    printf("%d\n", solution({5,2,3,4}, 13));
    printf("%d\n", solution({5,2,3,4}, 14));
    printf("%d\n", solution({5,2,3,4}, 15));
    return 0;
}

//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int solution(vector<int> food_times, long long k) {
//    int answer = 0;
//    int amt = 0;
//
//    vector<int> fs;
//    for (int i=0; i<food_times.size(); i++) {
//        fs.push_back(food_times[i]);
//        amt += food_times[i];
//    }
//
//    if (amt <= k) return -1;
//
//    sort(fs.begin(), fs.end());
//    int min = fs[0];
//    int min_idx = 0;
//    int cycle_time = (int)food_times.size();
//
//    int min_num = 1;
//    while (1) {
//        k -= cycle_time*min;
//        if (k<=0) {
//            if (k==0) { answer=1; break; }
//            k += cycle_time*min;
//            for (int i=0; i<min; i++) {
//                for (int j=0; j<food_times.size(); j++) {
//                    if (food_times[j]<(fs[min_idx]-min+i+1)) continue;
//                    if ((--k) == -1) { answer = (j)+1; break;}
//                }
//            }
//            break;
//        }
//
//        min_idx++;
//        min = fs[min_idx]-fs[min_idx-1];
//        min_num = 1;
//        for (int i=min_idx+2; i<fs.size(); i++) {
//            if (fs[min_idx+1]==fs[i]) {min_num++; min_idx++;}
//            else break;
//        }
//
//        cycle_time -= min_num;
//    }
//
//    return answer;
//}
