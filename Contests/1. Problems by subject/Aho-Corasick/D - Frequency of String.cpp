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

vector<pair<int,int>> words;
vector<vector<int>> match;
vector<int> answ;

template<typename T = string, typename U = char, const int sigma = 26, const int OFFSET = 'a'>
struct AhoCorasick{
private:
    struct Node{
        int nxt[sigma];
        int link, slink, id;
        int parent;
        U label;
        
        Node(int parent = -1, U label = '?') : parent(parent), label(label){
            memset(nxt, -1, sizeof nxt);
            link = slink = id = -1;
        }
        int & operator [](U label) {
            return nxt[label - OFFSET];
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

    void insert(T & s){
        int node = 0;
        for(int i = 0; i < s.size(); i++){
            if(trie[node][s[i]] == -1){
                trie[node][s[i]] = sz++;
                trie.emplace_back(node, s[i]);
            }
            node = trie[node][s[i]];
        }
        trie[node].id = patterns++; // If it can repeat strings, it must be a list of id’s
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
            if(trie[node].slink && trie[trie[node].slink].id == -1){
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
                if(trie[curr].id != -1){
                    match[trie[curr].id].push_back(i - words[trie[curr].id].second + 1);
                }
                curr = next_terminal(curr);
            }
        }
        // cout << "all matchs " << '\n';
        // for(auto x : match){
        //     for(auto y : x){
        //         cout << y << " ";
        //     }
        //     cout << '\n';
        // }
        for(int i = 0; i < match.size(); i++){
            for(int j = words[i].first - 1; j < match[i].size(); j++){
                auto [k, len] = words[i];
                answ[i] = min(answ[i], match[i][j] - match[i][j - k + 1] + 1 + len - 1);
            }
        }
    }
};

signed main() {
    optimize;
    string text;
    cin >> text;
    int n;
    cin >> n;
    AhoCorasick aho;
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        string s; cin >> s;
        aho.insert(s);
        words.push_back({k, s.size()});
    }
    match.assign(n, vector<int>());
    answ.assign(n, INF);
    aho.run(text);
    for(auto x : answ){
        cout << (x == INF ? -1 : x) << '\n';
    }
    return 0;
}