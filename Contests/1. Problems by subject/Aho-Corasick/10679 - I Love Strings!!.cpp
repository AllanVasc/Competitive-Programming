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

template<class T>
struct CoordinateCompression{
    vector<T> v;
    void push(const T & a) { v.push_back(a); }
    int build(){
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        return (int) v.size();
    }
    int operator[] (const T & a){
        auto it = lower_bound(v.begin(), v.end(), a);
        return it - v.begin();
    }
};

CoordinateCompression<char> mp;

vector<bool> answ;

template<typename T = string, typename U = char, const int sigma = 60>
struct AhoCorasick{
private:
    struct Node{
        int nxt[sigma];
        int link, slink;
        vector<int> id;
        int parent;
        U label;

        Node(int parent = -1, U label = '?') : parent(parent), label(label){
            memset(nxt, -1, sizeof nxt);
            link = slink = -1;
            id.clear();
        }
        int & operator [](U c){
            int val = mp[c];
            return nxt[val];
        }
    };

    int sz, patterns;
    vector<Node> trie;

public:
    AhoCorasick(){
        sz = 1;
        patterns = 0;
        trie.resize(1);
    }

    void add(T & s){
        int node = 0;
        for(int i = 0; i < s.size(); i++){
            if(trie[node][s[i]] == -1){
                trie[node][s[i]] = sz++;
                trie.emplace_back(node, s[i]);
            }
            node = trie[node][s[i]];
        }
        trie[node].id.push_back(patterns++); // Maybe need to be a list of id's
    }

    int next(int node, U label){
        if(trie[node][label] == -1){
            if(!node) trie[node][label] = 0;
            else trie[node][label] = next(next_suffix(node), label);
        }
        return trie[node][label];
    }

    int next_suffix(int node){
        if(!node || !trie[node].parent) return 0;
        if(trie[node].link == -1){
            trie[node].link = next(next_suffix(trie[node].parent), trie[node].label);
        }
        return trie[node].link;
    }
    int next_terminal(int node){ // Super suffix link
        if(!node || !trie[node].parent) return 0;
        if(trie[node].slink == -1){
            trie[node].slink = next_suffix(node);
            if(trie[node].slink && trie[trie[node].slink].id.size() == 0){
                trie[node].slink = next_terminal(trie[node].slink);
            }
        }
        return trie[node].slink;
    }

    void run(T & s){
        int node = 0;
        for(int i = 0; i < s.size(); i++){
            node = next(node, s[i]);
            int curr = node;
            while(curr){
                for(auto id : trie[curr].id){
                    answ[id] = true;
                }
                curr = next_terminal(curr);
            }
        }
    }
};

signed main() {
    optimize;
    
    for(char c = 'a'; c <= 'z'; c++) mp.push(c);
    for(char c = 'A'; c <= 'Z'; c++) mp.push(c);
    mp.build();

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int q;
        cin >> q;
        AhoCorasick<string, char, 52> aho;
        answ.assign(q, false);
        for(int i = 0; i < q; i++){
            string aux;
            cin >> aux;
            aho.add(aux);
        }
        aho.run(s);
        for(auto x : answ) cout << (x ? "y" : "n") << '\n';
    }
    return 0;
}