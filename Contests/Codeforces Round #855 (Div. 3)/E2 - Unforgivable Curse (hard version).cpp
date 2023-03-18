#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 2* 1e5 + 100;

struct Node{
    int p;
    int freq[26];
};

int sz[ms];
Node parent[ms];

void Build(int n, string s){
    for(int i = 0; i < n; i++){
        parent[i].p = i;
        for(int j = 0; j < 26; j++) parent[i].freq[j] = 0;
        parent[i].freq[s[i] - 'a']++;
        sz[i] = 1;
    }
}

int Find(int v){
    if(v == parent[v].p) return v;
    return parent[v].p = Find(parent[v].p);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a != b){
        if(sz[a] < sz[b]) swap(a, b);
        parent[b].p = a;
        for(int i = 0; i < 26; i++){
            parent[a].freq[i] += parent[b].freq[i];
        }
        sz[a] += sz[b];
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        string s1, s2;
        cin >> s1 >> s2;
        Build(n, s1);
        for(int i = 0; i < n; i++){
            if(i + k < n) Union(i, i + k);
            if(i + k + 1 < n) Union(i, i +k + 1);
        }

        bool has_answ = true;
        for(int i = 0; i < n && has_answ; i++){
            int pai = Find(i);
            if(parent[pai].freq[s2[i] - 'a'] == 0){
                has_answ = false;
            }
            parent[pai].freq[s2[i] - 'a']--;
        }

        for(int i = 0; i < n && has_answ; i++){
            int pai = Find(i);
            for(int j = 0; j < 26; j++){
                if(parent[pai].freq[j] != 0) has_answ = false;
            }
        }

        if(has_answ) cout << "YES" << "\n";
        else cout << "NO" << '\n';
    }
    return 0;
}