#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 500010;
const int sigma = 26;

int trie[ms][sigma], terminal[ms], z = 1;

void insert(string &s){
    int curr = 0;
    for(int i = 0; i < s.size(); i++){
        int id = s[i] - 'a';
        if(!trie[curr][id]){
            trie[curr][id] = z++;
        }
        curr = trie[curr][id];
    }
    terminal[curr]++;
}

int count(string &s){
    int curr = 0;
    for(int i = 0; i < s.size(); i++){
        int id = s[i] - 'a';
        if(!trie[curr][id]) return false;
        curr = trie[curr][id];
    }
    return terminal[curr];
}

void remove(string &s){
    int curr = 0;
    for(int i = 0; i < s.size(); i++){
        int id = s[i] - 'a';
        if(!trie[curr][id]) return;
        curr = trie[curr][id];
    }
    terminal[curr]--;
}

// Print words in Trie with a given prefix
void print(int curr, string &answ){
    if(terminal[curr]) cout << answ << '\n';

    for(int i = 0; i < sigma; i++){
        if(trie[curr][i]){
            answ.push_back(i + 'a');
            print(trie[curr][i], answ);
            answ.pop_back();
        }
    }
}

/*

Time Complexity:

insert  -> O(n)
remove  -> O(n)
count   -> O(n)

Links:

https://www.youtube.com/watch?v=-urNrIAQnNo
https://www.youtube.com/watch?v=AXjmTQ8LEoI

*/