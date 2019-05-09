//
//  cco15p4.cpp
//  Competitive Programming
//
//  Created by Amey Dhamgunde on 2019-02-15.
//  Copyright © 2019 Amey Dhamgunde. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

char grid[2005][2005], temp;
pair<int, int> affects[2005][2005];
vector<pair<int, int>> cars;
int n, m, a;

void removeAll(pair<int, int> selected) {
    queue<pair<int, int>> test;
    test.push(selected);
    
    while (!test.empty()) {
        cout << "(" << test.front().first << "," << test.front().second << ")\n";
        grid[test.front().first][test.front().second] = '.';
        test.push(affects[test.front().first][test.front().second]);
        cars.erase(remove(cars.begin(), cars.end(), selected));
        test.pop();
    }
}

int main () {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> temp;
            grid[i][j] = temp;
            if (temp == 'E' || temp == 'W' || temp == 'N' || temp == 'S') {
                cars.push_back({i, j});
            }
        }
    }
    
    while (!cars.empty()) {
        
        for (auto u : cars) {
            cout << u.first << " " << u.second << "\n";
            
            bool testing = true;
            if (grid[u.first][u.second] == 'E') {
                for (int i = u.second+1; i < m && testing; i++) {
                    if (grid[u.first][i] != '.') {
                        testing = false;
                        affects[u.first][i] = {u.first, u.second};
                    }
                }
                if (testing) {
                    grid[u.first][u.second] = '.';
                    cout << "(" << u.first << "," << u.second << ")\n";
                    cars.erase(remove(cars.begin(), cars.end(), u));
                }
            } else if (grid[u.first][u.second] == 'W') {
                for (int i = u.second-1; i >= 0 && testing; i--) {
                    if (grid[u.first][i] != '.') {
                        testing = false;
                        affects[u.first][i] = {u.first, u.second};
                    }
                }
                if (testing) {
                    grid[u.first][u.second] = '.';
                    cars.erase(remove(cars.begin(), cars.end(), u));
                    cout << "(" << u.first << "," << u.second << ")\n";
                }
            } else if (grid[u.first][u.second] == 'S') {
                for (int i = u.first+1; i < n && testing; i++) {
                    if (grid[i][u.second] != '.') {
                        testing = false;
                        affects[i][u.second] = {u.first, u.second};
                    }
                }
                if (testing) {
                    grid[u.first][u.second] = '.';
                    cars.erase(remove(cars.begin(), cars.end(), u));
                    cout << "(" << u.first << "," << u.second << ")\n";
                }
            } else if (grid[u.first][u.second] == 'N') {
                for (int i = u.first-1; i >= 0 && testing; i--) {
                    if (grid[i][u.second] != '.') {
                        testing = false;
                        affects[i][u.second] = {u.first, u.second};
                        
                    }
                }
                if (testing) {
                    grid[u.first][u.second] = '.';
                    cars.erase(remove(cars.begin(), cars.end(), u));
                    cout << "(" << u.first << "," << u.second << ")\n";
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << affects[i][j].first << "/" << affects[i][j].second << " ";
                }
                cout << "\n";
            }
            cout << "\n";
            
        }
    }
    
}
