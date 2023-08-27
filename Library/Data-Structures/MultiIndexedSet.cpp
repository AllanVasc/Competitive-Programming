#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long // This line needs to be after imports

template<typename T>
class multi_indexed_set{
    tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag,
	    tree_order_statistics_node_update> miset;
    unordered_map<T, int> freq;

    public:
	void insert(T x){
	    freq[x]++;
	    miset.insert({x, freq[x]});
	}
	void erase(T x){
	    if(!freq[x]) return;
	    miset.erase({x, freq[x]});
	    freq[x]--;
	}
	int order_of_key(T x){ return miset.order_of_key({x, 0}); }
	int count(T x) { return freq[x]; }
	int size(){ return miset.size(); }

};
multi_indexed_set<int> ms;

// Inserts "X" in multiset
ms.insert(X);

// Deletes "X" in multiset
ms.erase(X);

// Returns the position of element "X", another function is to count the amount of elements strictly smaller than "X"
ms.order_of_key(X);

// Returns the number of elements equal to "X"
ms.count(X);

// Returns the size of the multiset
ms.size();

/*

Time Complexity:

ms.insert(X)        -> O(logn)
ms.erase(X)         -> O(logn)
ms.order_of_key(X); -> O(logn)
ms.count(X)         -> O(1) (Average)
ms.size()           -> O(1)

Note: We can implement the "find_by_order" function

*/