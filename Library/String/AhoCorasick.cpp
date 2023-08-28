#include <bits/stdc++.h>
using namespace std;

#define int long long

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
        int & operator [](U label) { // Change according to the problem
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
        trie[node].id = patterns++; // If it can repeat strings, it must be a list of IDs
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
};

/*

Time Complexity:

add             -> O(|s|)
build           -> O(m * sigma) m = total length of its constituent strings (if using BFS)
next            -> O(1) amortized
next_suffix     -> O(1) amortized
next_terminal   -> O(1) amortized

Links:

https://cp-algorithms.com/string/aho_corasick.html
https://usaco.guide/adv/string-search?lang=cpp
https://www.youtube.com/watch?v=vpH5gSSapjI

*/