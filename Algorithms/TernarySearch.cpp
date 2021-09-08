#include <bits/stdc++.h>
using namespace std;

// Algorithm for finding the maximum of f(x)  which is unimodal on an interval [l,r]
double ternarySearch(double l, double r) {

	double eps = 1e-9;              // Set the error limit
    while (r - l > eps) {

        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;

        if (f(m1) < f(m2))			//Evaluate Function "f" at m1 and m2
            l = m1;
        else
            r = m2;
    }
    return f(l);                	// Return the maximum of f(x) in [l, r]
}

/*

Time Complexity

ternarySearch	-> O(log3(N))

Links:

https://cp-algorithms.com/num_methods/ternary_search.html

*/