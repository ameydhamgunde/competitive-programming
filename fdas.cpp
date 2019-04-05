//
//  fdas.cpp
//  Competitive Programming
//
//  Created by Amey Dhamgunde on 2019-01-26.
//  Copyright © 2019 Amey Dhamgunde. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <iterator>
#include <algorithm>
#include <queue>
#define pii pair<int, int>

using namespace std;

int N, C, dp[1002][10002], mod = 1000000007;

int main () {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> C;
    dp[0][0] = 1;
    for (int i = 1 ; i <= N; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= C; j++) {
            if (j >= i) {
                dp[i][j] = (dp[i-1][j]-dp[i-1][j-i])%mod;
            } 
        }
    }
    
}
