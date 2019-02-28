//
//  acc2p1.cpp
//  Competitive Programming
//
//  Created by Amey Dhamgunde on 2019-02-18.
//  Copyright © 2019 Amey Dhamgunde. All rights reserved.
//

#include <bits/stdc++.h>
#define inf 1000000000

using namespace std;

int dist[105][105][105], n, m; //vertex, vertex, days

int main () {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    memset(dist, inf, sizeof(dist));
    
    cin >> n;
    int temp;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> temp;
            if (i != j && temp == 0) {
                dist[i][j][1] = inf;
            } else {
                dist[i][j][1] = temp;
            }
        }
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j][1] = min(dist[i][j][1],
                                     dist[i][k][1]+dist[k][j][1]);
            }
        }
    }
    
    for (int x = 2 ; x <= n; x++) {
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (i != j) {
                        dist[i][j][x] = dist[i][k][x-1] + dist[k][j][1];
                    }
                    
                }
            }
        }
    }
    cin >> m;
    int s, t, d;
    for (int i = 0; i < m; i++) {
        cin >> s >> t >> d;
        if (dist[s][t][d] > dist[s][t][1]) {
            cout << "0\n";
        } else {
            cout << dist[s][t][d] << "\n";
        }
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << dist[i][j][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}
