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

int sz = 0;
void ask(int q, set<int>& conj){
    string s;
    for(int i = 1; i <= 26; i++){
        if(i & (1 << q)){
            s.pb('a' + i - 1);
        }
    }
    cout << "? " << s << endl;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int aux; cin >> aux;
        conj.insert(aux - 1);
        sz = max(sz, aux);
    }
}
void answer(string& s){
    cout << "! " << s << endl;
}

int32_t main() {
    optimize;
    
    vector<set<int>> queries(5);
    for(int i = 0; i < 5; i++){
        ask(i, queries[i]);
    }
    string answ(sz, '*');
    // for(int i = 0; i < 5; i++){
    //     cout << "q " << i + 1 << " : ";
    //     for(auto x : queries[i]) cout << x << " ";
    //     cout << endl;
    // }
    char let = 'a';
    for(int i = 1; i <= 26; i++, let++){
        vector<int> freq(sz, 0);
        for(int j = 0; j < 5; j++){
            if(i & (1 << j)){
                for(auto x : queries[j]) freq[x]++;
            }
            else{
                for(auto x : queries[j]) freq[x]--;
            }
        }
        for(int j = 0; j < sz; j++){
            if(freq[j] == __builtin_popcount(i)) answ[j] = let;
        }
    }
    answer(answ);
    return 0;
}