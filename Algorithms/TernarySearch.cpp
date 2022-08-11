#include <bits/stdc++.h>
using namespace std;

// Algorithm for finding the maximum of f(x)  which is unimodal on an interval [l,r]
// Real numbers
double ternarySearch(double l, double r) {

	double eps = 1e-9;              // Set the error limit
    for(int i = 0; i < 200 && r-l > eps; i++){
        double m1 = (2*l + r)/3.0;
        double m2 = (l + 2*r)/3.0;

        if(f(m1) > f(m2))   //Evaluate Function "f" at m1 and m2
            l = m1;
        else
            r = m2;
    }

    return f(l);        // Return the maximum of f(x) in [l, r]
}

/*

Time Complexity

ternarySearch	-> O(log3(N))

Links:

https://cp-algorithms.com/num_methods/ternary_search.html

*/