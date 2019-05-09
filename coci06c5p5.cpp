//
//  coci06c5p5.cpp
//  Competitive Programming
//
//  Created by Amey Dhamgunde on 2019-02-01.
//  Copyright © 2019 Amey Dhamgunde. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <iterator>
#include <algorithm>
#include <queue>
#define maxn 205

using namespace std;

int dp[maxn][maxn], n;
int v[maxn];

int recursion (int i,int j) {
    if(dp[i][j] != -1) return dp[i][j];
    if(i == j) return dp[i][j] = v[i];
    return dp[i][j] = max(v[i] - recursion(i+1,j), v[j] - recursion(i,j-1) );
}

int main () {
    memset(dp,-1,sizeof(dp));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] %= 2;
        v[i+n] = v[i];
    }
    int total = 0;
    for(int i = 1; i <= n; i++){
        int result = v[i] - recursion(i+1,i + n - 1);
        if (result > 0) total++;
    }
    cout << total;
    return 0;
}
