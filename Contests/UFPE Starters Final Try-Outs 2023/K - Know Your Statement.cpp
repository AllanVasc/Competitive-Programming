#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

struct Node{
    set<int> end;
    set<int> passed;
    Node(){}
};

const int ms = 1e6;
const int sigma = 26;
int trie[ms][sigma];
Node terminal[ms];
int z = 1;

void insert(string& s, int idx){
    int curr = 0;
    for(int i = 0; i < s.size(); i++){
        int id = s[i] - 'a';
        if(!trie[curr][id]){
            trie[curr][id] = z++;
        }
        curr = trie[curr][id];
        terminal[curr].passed.insert(idx);
    }
    terminal[curr].end.insert(idx);
}

void remove(string& s, int idx){
    int curr = 0;
    for(int i = 0; i < s.size(); i++){
        int id = s[i] - 'a';
        curr = trie[curr][id];
        terminal[curr].passed.erase(idx);
    }
    terminal[curr].end.erase(idx);
}

// Alguma string [l,r] eh prefixo de s
bool query2(string&s, int l, int r){
    int curr = 0;
    for(int i = 0; i < s.size(); i++){
        int id = s[i] - 'a';
        if(!trie[curr][id]){
            return false;
        }
        curr = trie[curr][id];
        if(terminal[curr].end.size()){
            auto answ = terminal[curr].end.lower_bound(l);
            if(answ != terminal[curr].end.end() &&
               (*answ) <= r) return true;
        }
    }
    return false;
}

// s eh prefixo de alguma string [l, r]
bool query3(string& s, int l, int r){
    int curr = 0;
    for(int i = 0; i < s.size(); i++){
        int id = s[i] - 'a';
        if(!trie[curr][id]) return false;
        curr = trie[curr][id];
    }
    auto answ = terminal[curr].passed.lower_bound(l);
        if(answ != terminal[curr].passed.end() &&
           (*answ) <= r) return true;
    else return false;
}

int32_t main() {
    optimize;
    
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        insert(v[i], i);
    }
    int q;
    cin >> q;
    while(q--){
        int cmd; cin >> cmd;
        if(cmd == 1){
            int idx;
            string s;
            cin >> idx >> s;
            idx--;
            remove(v[idx], idx);
            v[idx] = s;
            insert(v[idx], idx);
        }
        else if(cmd == 2){
            int l, r;
            string s;
            cin >> l >> r >> s;
            l--, r--;
            if(query2(s, l, r)) cout << "Y" << '\n';
            else cout << "N" << '\n';
        }
        else{
            int l, r;
            string s;
            cin >> l >> r >> s;
            l--, r--;
            if(query3(s, l, r)) cout << "Y" << '\n';
            else cout << "N" << '\n';
        }
    }
    return 0;
}