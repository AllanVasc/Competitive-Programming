#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
	tree_order_statistics_node_update> indexed_set;

indexed_set s;

// Inserts "X" in set
s.insert(X);

// Deletes "X" in set
s.erase(X);

// Returns an iterator for the element at position "pos" (0-based)
s.find_by_order(pos);

// Returns the position of element "X", another function is to count the amount of elements strictly smaller than "X"
s.order_of_key(X);

/*

Time Complexity

All operations run on O(logn)

Note: When the element does not exist in the indexed_set, the "order_of_key()" function returns the position it SHOULD BE,
if it existed, so it is useful to calculate the amount of elements strictly smaller than "X".

Links:

https://codeforces.com/blog/entry/11080
https://www.geeksforgeeks.org/policy-based-data-structures-g/

*/
