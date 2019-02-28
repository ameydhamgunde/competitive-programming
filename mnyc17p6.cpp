//
//  mnyc17p6.cpp
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

using namespace std;

void distinctFrequencies (int start, int end, int bells[], int n) {
    vector<int> distinct;
    
    for (int i = start-1; i < end; i++) {
        if (find(distinct.begin(), distinct.end(), bells[i]) == distinct.end()) { // cannot be found
            distinct.push_back(bells[i]);
        }
    }

    cout << distinct.size() << "\n";
}

int main () {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q, temp, instruction, num1, num2;
    cin >> n >> q;
    
    int bells[n];
    
    for (int i = 0; i < n; i++) {
        cin >> temp;
        bells[i] = temp;
    }
    
    for (int i = 0; i < q; i++) {
        cin >> instruction;
        switch (instruction) {
            case 1:
                cin >> num1 >> num2;
                bells[num1-1] = num2;
                break;
                
            case 2:
                cin >> num1 >> num2;
                distinctFrequencies(num1, num2, bells, n);
                break;
                
            default:
                break;
        }
    }
}
