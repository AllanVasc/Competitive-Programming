#include <bits/stdc++.h>
using namespace std;
  
#define int long long

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
        if(s[i] != '*'){
            int id = s[i] - 'a';
            if(!trie[curr][id]) trie[curr][id] = z++;
            curr = trie[curr][id];
        }
        else{
            for(int j = 0; j < sigma; j++){
                int new_curr = curr;
                int id = j;
                if(!trie[new_curr][id]) trie[new_curr][id] = z++;
                new_curr = trie[new_curr][id];

                for(int k = i + 1; k < s.size(); k++){
                    int id = s[k] - 'a';
                    if(!trie[new_curr][id]) trie[new_curr][id] = z++;
                    new_curr = trie[new_curr][id];
                }
                terminal[new_curr]++;
            }
            return;
        }
    }
}

// Print words in Trie with a given prefix
// void print(int curr, string &answ){
//     if(terminal[curr]) cout << answ << '\n';

//     for(int i = 0; i < sigma; i++){
//         if(trie[curr][i]){
//             answ.push_back(i + 'a');
//             print(trie[curr][i], answ);
//             answ.pop_back();
//         }
//     }
// }

string answ;
int qtd_max = 0;

void solve(int curr, string &s){
    if(terminal[curr]){
        if(qtd_max < terminal[curr]){
            qtd_max = terminal[curr];
            answ = s;
        }
    }
    for(int i = 0; i < 26; i++){
        if(trie[curr][i]){
            s.push_back(i + 'a');
            solve(trie[curr][i], s);
            s.pop_back();
        }
    }
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, c;
    cin >> n >> c;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        insert(s);
    }

    string s;
    solve(0, s);

    cout << answ << " " << qtd_max << '\n';

    return 0;
}