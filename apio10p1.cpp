//
//  apio10p1.cpp
//  Competitive Programming
//
//  Created by Amey Dhamgunde on 2019-01-22.
//  Copyright © 2019 Amey Dhamgunde. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <iterator>
#include <algorithm>
#include <queue>
#define ll long long

using namespace std;

ll n, a, b, c;
ll effectiveness[1000001];
ll dp[1000001];

ll func(ll x) {
    return a*x*x + b*x + c;
}

int main () {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> a >> b >> c;
    
    for (int i = 0; i <= n; i++) {
        dp[i] = -9223372036854775800;
    }
    
    dp[0] = 0;
    effectiveness[0] = 0;
    
    for (int i = 1; i <= n; i++) {
        cin >> effectiveness[i];
        effectiveness[i] += effectiveness[i-1];
        
        for (int j = max(0, i-300); j < i; j++) {
            dp[i] = max(dp[i], dp[j] + func(effectiveness[i] - effectiveness[j]));
        }
    }
    cout << dp[n];
}
