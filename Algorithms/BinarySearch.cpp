#include <bits/stdc++.h>
using namespace std;

// Recursive Binary Search function
int binarySearch(int arr[], int l, int r, int x){

    if (r >= l) {
        int mid = l + (r - l) / 2;

        // Found my answer
        if (arr[mid] == x)
            return mid;
 
        // Element is smaller, just need to look in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Element is greater, just need to look in left subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // Can't find element "x"
    return -1;
}

// Iterative Binary Search function
int binarySearch(int arr[], int l, int r, int x){

    while (l <= r) {
        int m = l + (r - l) / 2;
 
        // Found my answer
        if (arr[m] == x)
            return m;
 
        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;
 
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
 
    // Can't find element "x"
    return -1;
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

Time Complexity

Binary Search                   -> O(logn)
Finding the smallest solution   -> O(x*logz) x is the time complexity of function check();

Links:

https://www.geeksforgeeks.org/binary-search/

*/