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

vector<string> words;
vector<vector<int>> answ;

template<typename T = string, typename U = char, const int sigma = 60>
struct AhoCorasick{
private:
    struct Node{
        map<U, int> nxt;
        int link, slink;
        vector<int> id;
        int parent;
        U label;

        Node(int parent = -1, U label = '?') : parent(parent), label(label){
            link = slink = -1;
            id.clear();
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
            if(trie[node].nxt.count(s[i]) == 0){
                trie[node].nxt[s[i]] = sz++;
                trie.emplace_back(node, s[i]);
            }
            node = trie[node].nxt[s[i]];
        }
        trie[node].id.push_back(patterns++); // Maybe need to be a list of id's
    }

    int next(int node, U label){
        if(trie[node].nxt.count(label) == 0){
            if(!node) trie[node].nxt[label] = 0;
            else trie[node].nxt[label] = next(next_suffix(node), label);
        }
        return trie[node].nxt[label];
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
                    answ[id].push_back(i - words[id].size() + 1);
                }
                curr = next_terminal(curr);
            }
        }
    }
};

signed main() {
    optimize;

    int n;
    while(cin >> n){
        AhoCorasick<string, char, 52> aho;
        answ.assign(n, vector<int>());
        words.clear();
        cin.ignore();
        for(int i = 0; i < n; i++){
            string aux;
            getline(cin, aux);
            words.push_back(aux);
            aho.add(aux);
        }
        string text;
        getline(cin, text);
        aho.run(text);
        for(int i = 0; i < n; i++){
            sort(answ[i].begin(), answ[i].end());
            for(int j = 0; j < answ[i].size(); j++){
                cout << answ[i][j] << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}