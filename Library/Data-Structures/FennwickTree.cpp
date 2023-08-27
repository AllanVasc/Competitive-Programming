#include <bits/stdc++.h>
using namespace std;

#define int long long

// Implementation of a Binary Indexed Tree (Fennwick Tree) (1-Based) (Sum Operation)
vector<int> bit;

// Array used to construct BIT (0-Based)
vector<int> v;

// Initialize Fennwick Tree
void build(){
    // Initialize all values with 0 (1-based)
    bit = vector<int>(v.size()+1, 0);

    // Putting the values of "v" in bit
    for(int i = 0; i < v.size(); i++) bit[i+1] = v[i];

    // Updating the values 
    for(int i = 1; i < bit.size(); i++){
        int idx = i + (i & (-i));
        if(idx < bit.size()) bit[idx] += bit[i];
    }
}

// Return the sum of [0,idx] in "v" 
int prefix_query(int idx){
    int result = 0;
    for(++idx; idx > 0; idx -= idx & -idx) result += bit[idx];
    return result;
}

// Computes the range sum between two indices (both inclusive) [l,r] in "v"
int range_query(int l, int r){
    if (l == 0) return prefix_query(r);
    else return prefix_query(r) - prefix_query(l - 1);
}

// Update bit adding "add" (idx represent the position in "v")
void update(int idx, int add) {
    for (++idx; idx < bit.size(); idx += idx & -idx) bit[idx] += add;
}

/*

Time Complexity:

build           -> O(n)
prefix_query    -> O(logn)
range_query     -> O(logn)
update          -> O(logn)

Links:

https://www.youtube.com/watch?v=uSFzHCZ4E-8
https://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/
https://cp-algorithms.com/data_structures/fenwick.html
https://www.youtube.com/watch?v=v_wj_mOAlig
https://www.youtube.com/watch?v=CWDQJGaN1gY

*/