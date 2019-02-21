//
//  bbc08g.cpp
//  Competitive Programming
//
//  Created by Amey Dhamgunde on 2019-01-01.
//  Copyright © 2019 Amey Dhamgunde. All rights reserved.
//

//#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <iterator>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> adj;

void dijkstra (int n) {
    long long distance[n];
    bool processed[n];
    vector<long long> previous[n];
    
    priority_queue<pair<long long, long long>> q;
    
    for (int i = 0; i < n; i++) {
        distance[i] = 9223372036854775806;
        processed[i] = false;
    }
    
    distance[0] = 0;
    q.push({0, 0});
    previous[0].push_back(0);
    
    while (!q.empty()) {
        //cout << q.top().first << " " << q.top().second << "\n";
        int a = q.top().second; q.pop();
        if (processed[a]) {
            continue;
        } else {
            processed[a] = true;
            for (auto u : adj[a]) { // a is the first node, b is the next node, w is the length
                int b = u.first, w = u.second;
            
                if (distance[a] + w*pow(10LL, previous[a].size()-1) < distance[b]) {
                    processed[b] = false;
                    distance[b] = distance[a] + w*pow(10LL, previous[a].size()-1);
                    q.push({-distance[b], b});
                    previous[b] = previous[a];
                    previous[b].push_back(b);
                } else if (distance[a] + w*pow(10LL, previous[a].size()-1) == distance[b] && previous[b].size() > previous[a].size()+1) {
                    processed[b] = false;
                    q.push({-distance[b], b});
                    previous[b] = previous[a];
                    previous[b].push_back(b);
                }
            }
        }
    }

    cout << distance[n-1] << "\n";
    cout << previous[n-1].size() << "\n";
    for (unsigned int i = 0; i < previous[n-1].size(); i++) {
        cout << previous[n-1][i] << " ";
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m; // n is the number of cities, m is the number of roads
    
    adj.resize(n);
    
    int a, b, len;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> len;
        adj[a].push_back({b, len});
        adj[b].push_back({a, len});
    }
    
    dijkstra(n);
    
}
