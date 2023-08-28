#include <bits/stdc++.h>
using namespace std;

#define int long long

int quadrant(PT p){
    if(p.x < 0 && p.y < 0) return 0;
    if(p.x >= 0 && p.y < 0) return 1;
    if(p.x >= 0 && p.y >= 0) return 2;
    return 3;   // p.x < 0 && p.y >= 0
}

struct polar_sort{
    PT pivot;
    polar_sort (PT p): pivot(p) {}
    bool operator ()(PT a, PT b) const {
        a = a - pivot;
        b = b - pivot;
        if(quadrant(a) != quadrant(b)) return quadrant(a) < quadrant(b);
        return cross(a, b) > 0;
    }
};

// Call using
// sort(v.begin(), v.end(), polar_sort(pivot));

/*

Time Complexity:

sort    -> O(nlogn)

Links:

https://codeforces.com/blog/entry/72815

*/