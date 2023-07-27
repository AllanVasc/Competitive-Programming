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
        trie[node].id.push_back(patterns++); // If it can repeat strings, it must be a list of id’s
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

    string run(int n, int m){
        int total = n + m;
        queue<pii> q;
        q.push({0, 0});
        vector<vector<bool>> visited(350, vector<bool>(1 << (total), false));
        vector<vector<tuple<int,int, char>>> parent(350, vector<tuple<int,int, char>>(1 << (total), {-1, -1, '?'}));
        visited[0][0] = true;
        pair<int,int> last = {-1, -1};
        while(!q.empty()){
            auto [node, mask] = q.front();
            q.pop();
            int need = 0;
            int cant = 0;
            for(int i = 0; i < n; i++){
                if(mask & (1 << i)) need++;
            }
            for(int i = n; i < n + m; i++){
                if(mask & (1 << i)) cant++;
            }
            if(cant) continue;
            if(need == n){
                // found answ
                last = {node, mask};
                break;
            }
            for(char i = 'a'; i <= 'j'; i++){
                int nextNode = next(node, i);
                int aux = nextNode;
                int newMask = mask;
                while(aux){
                    for(auto x : trie[aux].id){
                        newMask |= (1 << x);
                    }
                    aux = next_terminal(aux);
                }
                if(!visited[nextNode][newMask]){
                    visited[nextNode][newMask] = true;
                    parent[nextNode][newMask] = {node, mask, i};
                    q.push({nextNode, newMask});
                }
            }
        }
        if(last.first == -1) return "-";
        // recovery answ
        string answ;
        while(last.first != -1){
            auto [pai, mask, c] = parent[last.first][last.second];
            answ.push_back(c);
            last = {pai, mask};
        }
        answ.pop_back();
        reverse(answ.begin(), answ.end());
        return answ;
    }
};

signed main() {
    optimize;
    int n, m;
    cin >> n >> m;
    AhoCorasick aho;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        aho.insert(s);
    }
    for(int i = 0; i < m; i++){
        string s; cin >> s;
        aho.insert(s);
    }
    cout << aho.run(n, m) << '\n';
    return 0;
}