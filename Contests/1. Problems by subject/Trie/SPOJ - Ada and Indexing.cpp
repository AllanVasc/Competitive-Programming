#include <bits/stdc++.h>
using namespace std;
  
// #define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 4*1e6;
const int sigma = 26;

int trie[ms][sigma], terminal[ms], z = 1;

void insert(string &s){
    int curr = 0;
    for(int i = 0; i < s.size(); i++){
        int id = s[i] - 'a';
        if(!trie[curr][id]) trie[curr][id] = z++;
        terminal[curr]++;
        curr = trie[curr][id];
    }
    terminal[curr]++;
}

int count(string &prefix){
    int curr = 0;
    for(int i = 0; i < prefix.size(); i++){
        int id = prefix[i] - 'a';
        if(!trie[curr][id]) return 0;
        curr = trie[curr][id];
    }
    return terminal[curr];
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,q;
    cin >> n >> q;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        insert(s);
    }

    for(int i = 0; i < q; i++){
        string s;
        cin >> s;
        int answ = count(s);
        cout << answ << '\n';
    }

    return 0;
}