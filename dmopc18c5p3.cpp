//
//  dmopc18c5p3.cpp
//  Competitive Programming
//
//  Created by Amey Dhamgunde on 2019-02-17.
//  Copyright © 2019 Amey Dhamgunde. All rights reserved.
//

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll n, m, c[200005];

int main () {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    
    ll sum = 0, count = 0, maxc = 0;
    
    for (int i = 0; i < n; i++) {
        if ((sum + c[i]) < m) {
            sum += c[i];
            count++;
        } else if (sum != 0) {
            sum = sum - c[i-count] + c[i];
        }
        
        maxc = max(count, maxc);
    }
    
    cout << maxc;
}
