//
//  cco17p4.cpp
//  Competitive Programming
//
//  Created by Amey Dhamgunde on 2019-02-16.
//  Copyright © 2019 Amey Dhamgunde. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

int heights[1005];
bool dp[1005][5005];
unordered_set<int> possible;

int main () {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    
    dp[0][0] = true; // base case
    
    sort(heights, heights + n);
    reverse(heights, heights + n);
    
    for (int i = 1; i < n; i++){
        for (int j = 0; j < 5001; j++){
            if (dp[i-1][j]) {
                dp[i][j] = true;
            }
            
            for (auto u : possible) {
                if (j - (u - heights[i]) >= 0 && dp[i - 1][j - (u - heights[i])]){
                    dp[i][j] = true;
                }
            }
        }
        
        possible.insert(heights[i]);
    }
    
    for (int i = 0; i <= 5000; i++){
        if (dp[n - 1][i]) {
            cout << i << " ";
        }
    }
}
