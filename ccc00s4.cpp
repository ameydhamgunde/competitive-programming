//
//  ccc00s4.cpp
//  Competitive Programming
//
//  Created by Amey Dhamgunde on 2019-02-19.
//  Copyright © 2019 Amey Dhamgunde. All rights reserved.
//

#include <bits/stdc++.h>
#define inf 0x3f3f3f3f

using namespace std;

int dist, c, temp, dp[6000], counter = 0;
vector<int> clubs;

int main () {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> dist >> c;
    
    for (int i = 0; i < c; i++) {
        cin >> temp;
        clubs.push_back(temp);
    }
    
    memset(dp, 0x3f, sizeof dp);
    
    queue<int> q;
    
    dp[0] = 0;
    q.push(0);
    
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        
        for (auto u : clubs) {
            if (temp + u > dist) continue;
            if (dp[temp + u] > dp[temp] + 1) {
                dp[temp + u] = dp[temp] + 1;
                q.push(temp + u);
            }
        }
    }
    if (dp[dist] == inf) {
        cout << "Roberta acknowledges defeat.";
    } else {
        printf("Roberta wins in %d strokes.", dp[dist]);
    }
}
