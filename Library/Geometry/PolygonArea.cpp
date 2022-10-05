#include <bits/stdc++.h>
using namespace std;

// Calculation of polygon area using Shoelace Formula. (v -> (X,Y))
// Vertices need to be sorted in clockwise manner or anticlockwise from the first vertex to last.
double polygonArea(vector<pair<double,double>> v, int n){

    double area = 0.0;

    int j = n-1;
    for(int i = 0; i < n; i++){
        area += (v[j].first + v[i].first)*(v[j].second - v[i].second);
        j = i;  // j is previous vertex to i
    }

    return abs(area/2.0);   // Return absolute value
}

/*

Time Complexity

polygonArea     -> O(n) 

Links:

https://www.geeksforgeeks.org/area-of-a-polygon-with-given-n-ordered-vertices/

*/