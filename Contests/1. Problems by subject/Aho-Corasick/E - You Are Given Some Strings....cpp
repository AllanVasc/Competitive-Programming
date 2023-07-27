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

map<string, int> findId;

template<typename T = string, typename U = char, const int sigma = 26, const int OFFSET = 'a'>
struct AhoCorasick{
public:
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
    vector<int> cnt;
    vector<Node> trie;
    vector<int> freq;

public:
    AhoCorasick(){
        sz = 1;
        patterns = 0;
        trie.resize(1);
    }

    void insert(T & s, int val){
        int node = 0;
        for(int i = 0; i < s.size(); i++){
            if(trie[node][s[i]] == -1){
                trie[node][s[i]] = sz++;
                trie.emplace_back(node, s[i]);
            }
            node = trie[node][s[i]];
        }
        trie[node].id = val; // If it can repeat strings, it must be a list of id’s
        while(val >= freq.size()) freq.push_back(0);
        freq[val]++;
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
        cnt.assign(s.size() + 5, 0);
        int node = 0;
        for(int i = 0; i < s.size(); i++){
            node = next(node, s[i]);
            int curr = node;
            while(curr){
                if(trie[curr].id != -1){
                    cnt[i] += freq[trie[curr].id];
                }
                curr = next_terminal(curr);
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
    AhoCorasick aho1, aho2;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        if(findId.count(s) == 0){
            findId[s] = findId.size();
        }
        int id = findId[s];
        aho1.insert(s, id);
        reverse(s.begin(), s.end());
        aho2.insert(s, id);
    }
    aho1.run(text);
    reverse(text.begin(), text.end());
    aho2.run(text);
    int answ = 0;
    for(int i = 0; i < text.size() - 1; i++){
        answ += aho1.cnt[i] * aho2.cnt[text.size() - 1 - (i + 1)];
    }
    cout << answ << '\n';
    return 0;
}