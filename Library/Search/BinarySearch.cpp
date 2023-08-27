#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> & v, int l, int r, int x){
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (v[m] == x) return m;
        if (v[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1; // Can't find element "x"
}

// Finding the smallest solution
// Suppose that we wish to find the smallest value k that is a valid solution for a problem
// We know that check(x) is false when x < k and true when x >= k.
// The initial jump length "z" has to be large enough
int x = -1;
for(int b = z; b >= 1; b /= 2){
    while(!check(x+b)) x += b;
}
int k = x+1;

// Finding the maximum value
// BS can be used to find the maximun value for a function that is first increasing and then decreasing
// Not allowed that consecutive values of the function are equal.
int x = -1;
for(int b = z; b >= 1; b /=2){
    while(f(x+b) < f(x+b+1)) x += b;
}
int k = x+1;

/*

Time Complexity:

Binary Search                   -> O(logn)
Finding the smallest solution   -> O(x*logz) x is the time complexity of function check();
Finding the maximum value       -> O(x*logz) x is the time complexity of function f();

Links:

https://www.geeksforgeeks.org/binary-search/

*/