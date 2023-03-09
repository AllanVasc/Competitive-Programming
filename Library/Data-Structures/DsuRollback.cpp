#include <bits/stdc++.h>
using namespace std;

#define int long long
using ii = pair<int,int>;

struct Dsu{
    vector<int> parent, sz;
    vector<ii> changes;
    int comps;

    Dsu(int n){
        comps = n;
        parent.assign(comps, 0);
        iota(parent.begin(), parent.end(), 0);
        sz.assign(comps, 1);
    }

    int find(int u){
        if(u == parent[u]) return u;
        else return find(parent[u]);
    }

    void merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b){
            changes.push_back({-1, -1});
            return;
        }
        if(sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        changes.push_back({a, b});
        comps--;
    }

    void rollback(){
        auto [a, b] = changes.back();
        changes.pop_back();
        if(a == -1) return;
        sz[a] -= sz[b];
        parent[b] = b;
        comps++;
    }
};

/*

Time Complexity:

find        -> O(logn)
merge       -> O(logn)
rollback    -> O(1)

Links:

https://www.youtube.com/watch?v=AW_iea9xpFw

*/