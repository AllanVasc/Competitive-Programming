#include <bits/stdc++.h>
using namespace std;

#define int long long
using ll = long long;

// Implementation of a Fennwick Tree 2D (1-Based) (Sum Operation)
vector<vector<int>> bit;
// Matrix used to construct BIT (0-Based)
vector<vector<int>> v;

void build(){ // Initialize Fennwick Tree 2D
    bit.assign(v.size()+1, vector<int>(v.size()+1, 0)); // Bit[N+1][N+1]

    for(int i = 0; i < v.size(); i++)
        for(int j = 0; j < v[i].size(); j++) 
            bit[i+1][j+1] = v[i][j];

    for(int i = 1; i < bit.size(); i++){
        for(int j = 1; j < bit[i].size(); j++){
            int idx_i = i + (i & (-i));
            int idx_j = j + (j & (-j));
            if(idx_i < bit.size() && idx_j < bit[i].size())
                bit[idx_i][idx_j] += bit[i][j];
        }
    }
}

// Returns the sum of [0,0] to [i,j]
int query(int i, int x){
    int result = 0;
    for(++i; i > 0; i -= i & -i)
        for(int j = x+1; j > 0; j -= j & -j)
            result += bit[i][j];
    return result;
}

// Returns the sum of (i_1,j_1) to (i_2,j_2) (both inclusive)
int range_query(int i_1, int j_1, int i_2, int j_2){
    return query(i_2,j_2) - query(i_1-1,j_2) - query(i_2,j_1-1) + query(i_1-1,j_1-1);
}

// Update bit adding "add" to position v[i][x]
void update(int i, int x, int add){
    for(++i; i < bit.size(); i += i & -i)
        for(int j = x+1; j < bit[i].size(); j += j & -j)
            bit[i][j] += add;
}

/*

Time Complexity

build       -> O(n^2)
query       -> O((logn)^2)
range_query -> O((logn)^2)
update      -> O((logn)^2)

Links:

https://cp-algorithms.com/data_structures/fenwick.html#finding-minimum-of-0-r-in-one-dimensional-array

*/