//
//  ccc00s5.cpp
//  Competitive Programming
//
//  Created by Amey Dhamgunde on 2019-02-15.
//  Copyright © 2019 Amey Dhamgunde. All rights reserved.
//

#include <bits/stdc++.h>
#define inf 1e9

using namespace std;

bool eaten[103];
int n;
double x[103], y[103]; // x[i] and y[i] are the coordinates of the ith sheep


int main () {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    
    for (double xcoord = 0; xcoord <= 1000; xcoord += 0.01) { // loop through all points the wolf could be
        
        double best = inf;
        vector<int> choose;
        
        for (int i = 1; i <= n; i++) {
            
            if (sqrt(y[i]*y[i] + (x[i] - xcoord)*(x[i] - xcoord)) < best) { // hypotenuse
                
                choose.clear();
                choose.push_back(i);
                best = sqrt(y[i]*y[i] + (x[i] - xcoord)*(x[i] - xcoord)) ;
                
            } else if (sqrt(y[i]*y[i] + (x[i] - xcoord)*(x[i] - xcoord)) == best) { // aka same possibility
                choose.push_back(i);
            }
            
        }
        
        for (auto i : choose) {
            eaten[i] = true;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (eaten[i]) {
            printf("The sheep at (%.2f, %.2f) might be eaten.\n", x[i], y[i]);
        }
    }
}
