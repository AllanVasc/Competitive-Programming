#include <bits/stdc++.h>
using namespace std;

/*
Algorithm for finding the maximum of f(x)  which is unimodal on an interval [l,r]
Unimodal:
1. f strictly increases first, reaches a maximum (at a single point or over an interval), and then strictly decreases.
2. f strictly decreases first, reaches a minimum, and then strictly increases.
*/

// Real numbers [l, r]
double ternarySearch(double l, double r) {
    double eps = 1e-9;  // Set the error limit
    for(int i = 0; i < 200 && r-l > eps; i++){
        double m1 = (2*l + r)/3.0;
        double m2 = (l + 2*r)/3.0;
        if(f(m1) > f(m2)) l = m1;
        else r = m2;
    }
    return f(l);    // Return the maximum of f(x) in [l, r]
}

// Integers numbers [l, r]
int ternarySearch(int l, int r){
    int lo = l - 1;
    int hi = r;
    while(hi - lo > 1){
        int mid = (hi + lo) >> 1;
        if(f(mid) > f(mid + 1)) hi = mid;
        else lo = mid;
    }
    return f(lo + 1);
}

/*

Time Complexity

ternarySearch	-> O(log3(N))

Links:

https://cp-algorithms.com/num_methods/ternary_search.html

*/