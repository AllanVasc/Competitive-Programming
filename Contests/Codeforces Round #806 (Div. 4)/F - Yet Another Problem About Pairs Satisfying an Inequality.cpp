// F - Yet Another Problem About Pairs Satisfying an Inequality
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

vector<int> bit;

void build(int n){
    bit = vector<int>(n+1,0);
    for(int i = 0; i < n; i++) bit[i+1] = 0;
    for(int i = 1; i < bit.size(); i++){
        int idx = i + (i&(-i));
        if(idx < bit.size()) bit[idx] += bit[i];
    }
}

int prefix_query(int idx){
    int answ = 0;
    for(++idx; idx > 0; idx -= idx & -idx) answ += bit[idx];
    return answ;
}

int range_query(int l, int r){
    if(l == 0) return prefix_query(r);
    else return prefix_query(r) - prefix_query(l-1);
}

void update(int idx, int add){
    for(++idx; idx < bit.size(); idx += idx & -idx) bit[idx] += add;
}

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
 
    while(t--){
        int n;
        cin >> n;
        vector<ii> v;

        for(int i = 0; i < n; i++){
            int aux;
            cin >> aux;
            v.push_back({aux,i+1});
        }
        
        build(n);

        int answ = 0;
        for(int i = 0; i < n; i++){
            if(v[i].first < v[i].second){
                int aux;
                if(v[i].first > n) aux = n;
                else aux = v[i].first;
                
                if(aux > 1)
                    answ += range_query(1,aux-1);
                update(i+1,1);
            }
        }

        cout << answ << '\n';
    }
 
    return 0;
}