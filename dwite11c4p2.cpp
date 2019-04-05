//
//  dwite11c4p2.cpp
//  Competitive Programming
//
//  Created by Amey Dhamgunde on 2019-02-18.
//  Copyright © 2019 Amey Dhamgunde. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

int factorization[10005] = {0};
int num;

void primes (int n) {
    
    while (n%2 == 0) {
        factorization[2]++;
        n /= 2;
    }
    
    for (int i = 3; i <= sqrt(n); i+=2) {
        while (n%i == 0) {
            factorization[i]++;
            n /= i;
        }
    }
    
    if (n > 2) {
        factorization[n]++;
    }
    
}

int main () {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    for (int x = 0; x < 5; x++) {
        cin >> num;
        
        for (int i = 2; i <= num; i++) {
            primes(i);
        }
        printf("%d^%d", 2, factorization[2]);
        factorization[2] = 0;
        for (int i = 3; i <= num; i++) {
            if (factorization[i] > 0) {
                printf(" * %d^%d", i, factorization[i]);
            }
            factorization[i] = 0;
        }
        cout << "\n";
    }
    
}
