//
//  main.cpp
//  kakao2019_7
//
//  Created by carrot on 07/09/2019.
//  Copyright © 2019 carrot. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    int mSize = (int)board.size();
    
    struct pos {
        int a[2], b[2], status;
    };
    
    queue<pos> q;
    q.push({{0,0},{0,1},0});
    while (++answer) {
        int size = (int)q.size();
        for (int i=0; i<size; i++) {
            pos p = q.front(); q.pop();
            if ((p.a[0]==mSize-1 && p.a[1]==mSize-1) || (p.b[0]==mSize-1 && p.b[1]==mSize-1)) {
                return answer-1;
            }
            if (p.status==0) {
                // move
                if (p.a[1]>0 && p.b[1]>0 && !board[p.a[0]][p.a[1]-1] && !board[p.b[0]][p.b[1]-1]) q.push({{p.a[0],p.a[1]-1},{p.b[0],p.b[1]-1},0});
                if (p.a[0]>0 && p.b[0]>0 && !board[p.a[0]-1][p.a[1]] && !board[p.b[0]-1][p.b[1]]) q.push({{p.a[0]-1,p.a[1]},{p.b[0]-1,p.b[1]},0});
                if (p.b[1]<mSize-1 && p.a[1]<mSize-1 && !board[p.a[0]][p.a[1]+1] && !board[p.b[0]][p.b[1]+1]) q.push({{p.a[0],p.a[1]+1},{p.b[0],p.b[1]+1},0});
                if (p.b[0]<mSize-1 && p.a[0]<mSize-1 && !board[p.a[0]+1][p.a[1]] && !board[p.b[0]+1][p.b[1]]) q.push({{p.a[0]+1,p.a[1]},{p.b[0]+1,p.b[1]},0});
                
                if (p.a[0]>0 && p.b[0]>0 && !board[p.a[0]-1][p.a[1]] && !board[p.b[0]-1][p.b[1]])
                    q.push({{p.b[0]-1,p.b[1]},{p.b[0],p.b[1]},1});
                if (p.b[0]>0 && p.a[0]>0 && !board[p.a[0]-1][p.a[1]] && !board[p.b[0]-1][p.b[1]])
                    q.push({{p.a[0],p.a[1]},{p.a[0]-1,p.a[1]},1});
                
                if (p.a[0]<mSize-1 && p.b[0]<mSize-1 && !board[p.a[0]+1][p.a[1]] && !board[p.b[0]+1][p.b[1]])
                    q.push({{p.b[0]+1,p.b[1]},{p.b[0],p.b[1]},1});
                if (p.b[0]<mSize-1 && p.a[0]<mSize-1 && !board[p.a[0]+1][p.a[1]] && !board[p.b[0]+1][p.b[1]])
                    q.push({{p.a[0],p.a[1]},{p.a[0]+1,p.a[1]},1});
            } else {
                if (p.a[1]<mSize-1 && p.b[1]<mSize-1 && !board[p.a[0]][p.a[1]+1] && !board[p.b[0]][p.b[1]+1])
                    q.push({{p.a[0],p.a[1]+1}, {p.b[0],p.b[1]+1},1});
                if (p.b[0]<mSize-1 && p.a[0]<mSize-1 && !board[p.a[0]+1][p.a[1]] && !board[p.b[0]+1][p.b[1]])
                    q.push({{p.a[0]+1,p.a[1]}, {p.b[0]+1,p.b[1]},1});
                
                if (p.a[1]>0 && p.b[1]>0 && !board[p.a[0]][p.a[1]-1] && !board[p.b[0]][p.b[1]-1])
                    q.push({{p.a[0],p.a[1]-1},{p.b[0],p.b[1]-1},1});
                if (p.a[0]>0 && p.b[0]>0 && !board[p.a[0]-1][p.a[1]] && !board[p.b[0]-1][p.b[1]])
                    q.push({{p.a[0]-1,p.a[1]},{p.b[0]-1,p.b[1]},1});
                
                if (p.b[1]<mSize-1 && p.a[1]<mSize-1 && !board[p.a[0]][p.a[1]+1] && !board[p.b[0]][p.b[1]+1])
                    q.push({{p.b[0],p.b[1]+1},{p.b[0],p.b[1]},0});
                if (p.a[1]<mSize-1 && p.b[1]<mSize-1 && !board[p.a[0]][p.a[1]+1] && !board[p.b[0]][p.b[1]+1])
                    q.push({{p.a[0],p.a[1]},{p.a[0],p.a[1]+1},0});
                
                if (p.b[0]>0 && p.a[0]>0 && !board[p.a[0]-1][p.a[1]] && !board[p.b[0]-1][p.b[0]])
                    q.push({{p.b[0]-1,p.b[1]},{p.b[0], p.b[1]},0});
                if (p.a[0]>0 && p.b[0]>0 && !board[p.a[0]-1][p.a[1]] && !board[p.b[0]-1][p.b[0]])
                    q.push({{p.a[0],p.a[1]},{p.a[0]-1, p.b[1]},0});
            }
        }
    }
    
    return answer-1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << solution({{0, 0, 0, 1, 1}, {0, 0, 0, 1, 0}, {0, 1, 0, 1, 1}, {1, 1, 0, 0, 1}, {0, 0, 0, 0, 0}});
    return 0;
}
