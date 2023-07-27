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

template<typename T = string, typename U = char, const int sigma = 26, const int OFFSET = 'a'>
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
        int & operator [](U label) { // Change according to the problem
            return nxt[label - OFFSET];
        }
    };

    int sz, patterns;
    vector<Node> trie;
    vector<int> patSz;

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
        trie[node].id.push_back(patterns++); // If it can repeat strings, it must be a list of id’s
        patSz.push_back(s.size());
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

    vector<int> dp;
    const int mod = 1e9 + 7;
    int solve(string & text){
        int n = text.size();
        dp.assign(n + 1, 0);
        dp[0] = 1;
        int node = 0;
        for(int i = 0; i < n; i++){
            node = next(node, text[i]);
            int aux = node;
            while(aux){
                for(auto id : trie[aux].id){
                    dp[i + 1] += dp[i + 1 - patSz[id]];
                    dp[i + 1] %= mod;
                }
                aux = next_terminal(aux);
            }
        }
        return dp[n];
    }
};

signed main() {
    optimize;
    int n; cin >> n;
    AhoCorasick aho;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        aho.insert(s);
    }
    string text;
    cin >> text;
    cout << aho.solve(text) << '\n';
    return 0;
}