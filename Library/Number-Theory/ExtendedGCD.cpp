#include <bits/stdc++.h>
using namespace std;

#define int long long

// Extended Euclidean Algorithm
struct GCD_type { int x, y, d; };
GCD_type ex_GCD(int a, int b){
        if(b == 0) return {1, 0, a};
        auto answ = ex_GCD(b, a % b);
        return {answ.y, answ.x - a / b * answ.y, answ.d};
}

/*

Time Complexity

ex_GCD ->  O(log(min(a, b))

Links:

https://cp-algorithms.com/algebra/extended-euclid-algorithm.html
https://www.math.cmu.edu/~bkell/21110-2010s/extended-euclidean.html
https://cp-algorithms.com/algebra/linear-diophantine-equation.html

*/