#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

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

signed main() {
    optimize;
    int n, c;
    cin >> n >> c;
    map<int,int> mpNumber;
    map<pii, vector<int>> edgeId;
    mpNumber[c] = 0;
    vector<int> difC;
    vector<int> equalC;
    for(int i = 0; i < n; i++){
        int a, b, w;
        cin >> a >> b >> w;
        if(!w){
            if(a == c) equalC.push_back(i + 1);
            else difC.push_back(i + 1);
        }
        else{
            if(mpNumber.count(a) == 0){
                mpNumber[a] = mpNumber.size();
            }
            if(mpNumber.count(b) == 0){
                mpNumber[b] = mpNumber.size();
            }
            edgeId[{mpNumber[a],mpNumber[b]}].push_back(i + 1);
        }
    }
    Euler<true> euler(mpNumber.size());
    for(auto it : edgeId){
        for(auto x : it.second){
            euler.addEdge(it.first.first, it.first.second);
        }
    }
    auto path = euler.getPath(0);
    if(!path.first){
        cout << "No" << '\n';
        return 0;
    }
    int curr = mpNumber[c];
    vector<int> answ;
    while(!difC.empty()){
        answ.push_back(difC.back());
        difC.pop_back();
    }
    for(int i = 1; i < path.second.size(); i++){
        auto [x, id1] = path.second[i - 1];
        auto [y, id2] = path.second[i];
        answ.push_back(edgeId[{x, y}].back());
        edgeId[{x, y}].pop_back();
        if(y != mpNumber[c]){
            while(!equalC.empty()){
                answ.push_back(equalC.back());
                equalC.pop_back();
            }
        }
    }
    if(answ.size() != n){
        cout << "No" << '\n';
    }
    else{
        cout << "Yes" << '\n';
        for(auto x : answ){
            cout << x << " ";
        }
        cout << '\n';
    }
    return 0;
}