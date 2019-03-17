//
//  ccc18s4.cpp
//  Competitive Programming
//
//  Created by Amey Dhamgunde on 2019-02-01.
//  Copyright © 2019 Amey Dhamgunde. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <cmath>
#include <vector>
#include <iterator>
#include <algorithm>
#include <queue>
#include <unordered_map>
#define maxn 1000005

using namespace std;

long long dp[maxn], N;
unordered_map<long long, long long> t;

long long recursion (long long x){
    if (x < maxn && dp[x] != -1) {
        return dp[x];
    } else if (x >= maxn && t.count(x) == 1) {
        return t[x];
    }
    long long total = 0;
    long long i = 2; // min tree size
    while (i <= x) {
        long long branch = x/i;
        long long j = x/branch;
        total += (j - i + 1) * recursion(branch);
        i = j + 1;
    }
    
    if(x < maxn) {
        return dp[x] = total;
    } else {
        return t[x] = total;
    }
}

int main(){
    memset(dp,-1,sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    
    cin >> N;
    cout << recursion(N) << endl;

}
