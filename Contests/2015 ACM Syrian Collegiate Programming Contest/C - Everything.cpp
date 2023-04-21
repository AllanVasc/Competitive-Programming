#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 5e5 +100;
const int sigma = 26;
int trie[ms][sigma], terminal[ms], z = 1;
vector<int> answ;

void clearTrie(){
    memset(trie, 0, sizeof trie);
    memset(terminal, 0, sizeof terminal);
    z = 1;
}

void insert(string& s){
    int curr = 0;
    for(int i = 0; i < s.size(); i++){
        int id = s[i] - 'a';
        if(trie[curr][id] == 0){
            trie[curr][id] = z++;
        }
        terminal[curr]++;
        curr = trie[curr][id];
    }
    terminal[curr]++;
}

void query(string& s, int idx, int type){
    int steps = type;
    int curr = 0;
    for(int i = 0; i < s.size(); i++){
        int id = s[i] - 'a';
        answ[idx] = min(answ[idx], steps + terminal[curr]);
        curr = trie[curr][id];
        steps++;
    }
    answ[idx] = min(answ[idx], steps + terminal[curr]);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<string,int>> v;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            v.push_back({s,i});
        }
        sort(v.begin(), v.end());
        answ.assign(n, INF);

        clearTrie();
        for(int i = 0; i < n; i++){
            auto [s, idx] = v[i];
            insert(s);
            query(s, idx, 0);
        }
        clearTrie();
        for(int i = n - 1; i >= 0; i--){
            auto [s, idx] = v[i];
            insert(s);
            query(s, idx, 1);
        }

        for(int i = 0; i < n; i++){
            cout << answ[i] << (i == n - 1 ? '\n' : ' ');
        }
    }
    return 0;
}