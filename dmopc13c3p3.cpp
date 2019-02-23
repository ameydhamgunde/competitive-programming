//
//  dmopc13c3p3.cpp
//  Competitive Programming
//
//  Created by Amey Dhamgunde on 2018-12-30.
//  Copyright © 2018 Amey Dhamgunde. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <iterator>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> grid;
vector<vector<bool>> reachable;

void bfs(int n, int h) {
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    reachable[0][0] = true;
    
    while (!q.empty() && !reachable[n-1][n-1]) { 
        pair<int, int> f = q.front();
        q.pop();
        
        if (f.first >= 0 && f.first < n && f.second >= 0 && f.second+1 < n && !reachable[f.first][f.second+1] && abs(grid[f.first][f.second+1]-grid[f.first][f.second]) <= h) { // right
            reachable[f.first][f.second+1] = true;
            q.push(make_pair(f.first, f.second+1));
        }
        
        if (f.first >= 0 && f.first+1 < n && f.second >= 0 && f.second < n && !reachable[f.first+1][f.second] && abs(grid[f.first+1][f.second]-grid[f.first][f.second]) <= h) { // down
            reachable[f.first+1][f.second] = true;
            q.push(make_pair(f.first+1, f.second));
        }
        
        if (f.first-1 >= 0 && f.first < n && f.second >= 0 && f.second < n && !reachable[f.first-1][f.second] && abs(grid[f.first-1][f.second]-grid[f.first][f.second]) <= h) { // up
            reachable[f.first-1][f.second] = true;
            q.push(make_pair(f.first-1, f.second));
        }
        
        if (f.first >= 0 && f.first < n && f.second-1 >= 0 && f.second < n && !reachable[f.first][f.second-1] && abs(grid[f.first][f.second-1]-grid[f.first][f.second]) <= h) { // left
            reachable[f.first][f.second-1] = true;
            q.push(make_pair(f.first, f.second-1));
        }
    }
}

int main() {
    //cout << ":"; //remove upon submission
    int n, h, temp;
    cin >> n >> h;
    reachable.assign(n, vector<bool> (n, false));
    grid.resize(n);
    for (int i = 0; i < n; i++) {
        grid[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> temp;
            grid[i][j] = temp; // (y, x)
        }
    }
    
    bfs(n, h);
    
    if (reachable[n-1][n-1]) {
        cout << "yes";
    } else {
        cout << "no";
    }
    
}
