#include <bits/stdc++.h>
using namespace std;

#define int long long
using ll = long long;

vector<int> v;

int partition(int l, int r){
    int pivot = v[l + (r-l)/2];
    while(l < r){
        if(v[l] >= pivot){
            swap(v[l], v[r]);
            r--;
        }
        else
            l++;
    }

    if(v[l] < pivot) l++;

    return l;
}

// Algorithm to find the smallest "k"s elements using QuickSelect
// QuickSelect can be used to find the "k" element as well.
vector<int> smallest_k_elements(int k){
    int l = 0;
    int r = v.size()-1;
    int pivotIdx = v.size();

    while(pivotIdx != k){
        pivotIdx = partition(l,r);
        if(pivotIdx < k)
            l = pivotIdx;
        else
            r = pivotIdx - 1;
    }

    return vector<int>(v.begin(), v.begin() + k);
}

/*

Time Complexity

QuickSelect -> O(n) In the average case, in the worst case it runs on O(n^2) but it is rare.

Links:

https://www.youtube.com/watch?v=ooLKYx1TlSE

*/
