//
//  ccc09s4.cpp
//  Competitive Programming
//
//  Created by Amey Dhamgunde on 2019-02-18.
//  Copyright © 2019 Amey Dhamgunde. All rights reserved.
//

#include <bits/stdc++.h>
#define inf 0x3f3f3f3f

using namespace std;

vector<pair<int, int>> adj[5005];
int dist[5005];
int starting[5005];
int n, k;
int t, x, y, c, z, p, startingnode, mincost = inf;

void dijkstra (int start) {
    
    priority_queue<pair<int, int>> q;
    
    dist[start] = 0;
    q.push({0, start});
    
    while (!q.empty()) {
        int a = q.top().second;
        int fd = q.top().first;
        q.pop();
        
        if (dist[a] < fd) continue;
        for (auto u : adj[a]) {
            int b = u.first, w = u.second;
            
            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                q.push({-dist[b], b});
            }
        }
    }
}

int main () {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> t;
    
    memset(dist, 0x3f, sizeof dist);
    memset(starting, -1, sizeof starting);
    
    for (int i = 0; i < t; i++) {
        cin >> x >> y >> c;
        adj[x].push_back({y, c});
        adj[y].push_back({x, c});
    }
    
    cin >> k;
    
    for (int i = 1; i <= k; i++) {
        cin >> z >> p;
        starting[z] = p;
    }
    
    cin >> startingnode;
    
    dijkstra(startingnode);
    
    for (int i = 1; i <= n; i++) {
        if (starting[i] != -1) {
            mincost = min(mincost, dist[i]+starting[i]);
        }
    }
    
    cout << mincost;
}
