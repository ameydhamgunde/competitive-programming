//
//  ccc15s3.cpp
//  Competitive Programming
//
//  Created by Amey Dhamgunde on 2018-12-31.
//  Copyright © 2018 Amey Dhamgunde. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <iterator>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int main () {
    int g, p;
    cin >> g >> p;
    
    set<int> airport;
    
    for (int i = 1; i < g+1; i++) {
        airport.insert(-i);
        
    }
    
    for (int i = 0; i < p; i++) {
        int plane;
        cin >> plane;
        if (airport.lower_bound(-plane) == airport.end()) {
            cout << i << endl;
            return 0;
        }
        
        airport.erase(airport.lower_bound(-plane));
    }
    
    cout << p << endl;
    return 0;
}
