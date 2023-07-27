#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>

/*

Hierholzer’s Algorithm to find Euler path/circuit in a graph
To use directed graph: Euler<true> euler;

getPath(src): Try to find a Euler Path/circuit starting in "src"
the function returns a pair {possible, path}, path being a vector
of {vertex, edge id to reach vertex}
Obs.: In the first path's position id = -1

If you find a circuit the first and last vertex will be equal.

getCycle(): Find a Euler circuit if it exists.
Obs.: The first vertex doesn't repeat in the end

* See the conditions required to exist a path/circuit 
and how to find the "src" in Theorems/Graph.txt

*/

template<bool directed = false> 
struct Euler{
    vector<vector<pii>> g;
    vector<int> used;
    int n;

    Euler(int n) : n(n), g(n) {}

    void addEdge(int a, int b){
        int id = used.size();
        used.push_back(false);
        g[a].emplace_back(b, id);
        if(!directed) g[b].emplace_back(a, id);
    }

    // You need to pass the correct "src"
    pair<bool, vector<pii>> getPath(int src){
        if(!used.size()) return {true, {}};
        for(int & i : used) i = false;
        vector<int> point(n, 0);
        // { {vertex, prev vertex}, edge id}
        vector<pair<pii, int>> ret, st = { {{src, -1}, -1} };
        while(st.size()){
            int curr = st.back().first.first;
            int & it = point[curr];
            while(it < g[curr].size() && used[g[curr][it].second]) it++;
            if(it == g[curr].size()){ // no more edges out of "curr"
                if(ret.size() && ret.back().first.second != curr)
                    return {false, {}};
                ret.push_back(st.back());
                st.pop_back();
            }
            else{
                st.push_back({ {g[curr][it].first, curr}, g[curr][it].second });
                used[g[curr][it].second] = true;
            }
        }
        if(ret.size() != used.size() + 1) return {false, {}};
        vector<pii> answ;
        for(auto i : ret) answ.emplace_back(i.first.first, i.second);
        reverse(answ.begin(), answ.end());
        return {true, answ};
    }

    pair<bool, vector<pii>> getCycle(){
        if(!used.size()) return {true, {}};
        int src = 0;
        while(!g[src].size()) src++;
        auto answ = getPath(src);
        if(!answ.first || answ.second[0].first != answ.second.back().first){
            return {false, {}};
        }
        answ.second[0].second = answ.second.back().second;
        answ.second.pop_back();
        return answ;
    }
};

/*

Time Complexity

getPath     -> O(V + E)
getCycle    -> O(V + E)

Links:

https://www.youtube.com/watch?v=8MpoO2zA2l4
https://usaco.guide/adv/eulerian-tours?lang=cpp
https://cp-algorithms.com/graph/euler_path.html

*/