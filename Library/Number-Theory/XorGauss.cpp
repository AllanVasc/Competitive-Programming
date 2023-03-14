#include <bits/stdc++.h>
using namespace std;

#define int long long

template<class T = unsigned int>
class XorGauss{
    public:
    int d, sz;
    vector<T> basis;
    XorGauss(int n) : d(n){
        basis.assign(d, 0);
        sz = 0;
    }
    bool add(T mask){
        for(int i = d - 1; i >= 0; i--){
            if((mask & (((T)1) << i)) == 0) continue;
            if(basis[i]) mask ^= basis[i];
            else{
                basis[i] = mask;
                sz++;
                return true;
            }
        }
        return false;
    }
    // Returns the smallest possible value of a vector
    // by subtracting a linear combination from the basis
    T reduce(T mask){
        for(int i = d - 1; i >= 0; i--){
            mask = min(mask, mask ^basis[i]);
        }
        return mask;
    }
    // Returns the largest possible value of a vector
    T augment(T mask){
        return ~reduce(~mask);
    }
    // Checks whether the vector can be formed by a linear combination of the basis
    bool check(T mask){
        for(int i = d - 1; i >= 0; i--){
            if((mask & (((T)1) << i)) == 0) continue;
            if(!basis[i]) return false;
            mask ^= basis[i];
        }
        return true;
    }
};

/*

Time Complexity:

add ->  O(d)

Links:

https://codeforces.com/blog/entry/68953

*/