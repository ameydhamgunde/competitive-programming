//
//  ccc07j5.cpp
//  Competitive Programming
//
//  Created by Amey Dhamgunde on 2019-01-18.
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

vector<int> motels = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};

long long traverse (int a, int b) {
    vector<long long> possible;
    possible.resize(motels.size(), 0);
    possible[0] = 1;
    for (int i = 0; i < motels.size()-1; i++) {
        for (int j = i+1; j < motels.size(); j++) {
            if (motels[j] >= motels[i]+a && motels[j] <= motels[i]+b) {
                possible[j] += possible[i];
            }
        }
    }
    
    return possible[motels.size()-1];
    
}

int main () {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        motels.push_back(x);
    }
    
    sort(motels.begin(), motels.end());
    
    cout << traverse(a, b) << "\n";
    
}
