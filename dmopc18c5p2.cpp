//
//  dmopc18c5p2.cpp
//  Competitive Programming
//
//  Created by Amey Dhamgunde on 2019-02-17.
//  Copyright © 2019 Amey Dhamgunde. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

double screen[1005][1005];
double sum, temp, avg, factor, mins = 2;
pair<int, int> minimum;

int n, m;

void func () {
    factor = 0.48/avg;
    sum = 0.0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            screen[i][j] = (screen[i][j]*factor > 1) ? 1 : screen[i][j]*factor;
            sum+= screen[i][j];
        }
    }
    avg = sum/(n*m);
    if (abs(avg-0.48000) < 0.000001) {
        printf("%lf", (screen[minimum.first][minimum.second]/mins));
    } else {
        func();
    }
}

int main () {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> temp;
            sum += temp;
            screen[i][j] = temp;
            if (temp < mins) {
                mins = temp;
                minimum = make_pair(i, j);
            }
        }
    }
    
    avg = sum/(n*m);
    
    if (abs(avg-0.48) < 0.00001) {
        cout << "correctly exposed";
    } else if (avg > 0.48) {
        printf("overexposed\n %lf", (0.48/avg));
    } else {
        cout << "underexposed\n";
        func();
    }
}
