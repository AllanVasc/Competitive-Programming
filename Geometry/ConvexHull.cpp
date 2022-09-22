#include <bits/stdc++.h>
using namespace std;

#include "./Geometry.cpp"

// Monotone chain Algorithm to calculate Convex Hull
vector<PT> convexHull(vector<PT> p, bool needSort = 1){
    if(needSort) sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    int n = p.size(), k = 0;
    if(n <= 1) return p;
    vector<PT> answ(n + 2);   // Must be 2*n + 1 for collinear points

    // Lower hull
    for(int i = 0; i < n; i++){
        while(k >= 2 && cross(answ[k-1] - answ[k-2], p[i] - answ[k-2]) <= 0) k--; // If collinear points are allowed put only "<"
        answ[k++] = p[i];
    }

    // Upper hull
    for(int i = n - 2, t = k + 1; i >= 0; i--) {
        while(k >= t && cross(answ[k - 1] - answ[k - 2], p[i] - answ[k - 2]) <= 0) k--; // If collinear points are allowed put only "<"
        answ[k++] = p[i];
    }

    answ.resize(k); // n+1 points where the first is equal to the last
    return answ;
}

/*

Time Complexity

convexHull  -> O(nlogn) 

Links:

https://cp-algorithms.com/geometry/convex-hull.html#implementation_1
https://www.youtube.com/watch?v=JS-eBdqb1uM     

*/