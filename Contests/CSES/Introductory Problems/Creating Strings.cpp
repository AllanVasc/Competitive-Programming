#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<ii> solve(int n, int initial, int end, int help){
    if(n == 1){
        vector<ii> answ;
        answ.push_back({initial, end});
        return answ;
    }
    else{
        vector<ii> answ = solve(n - 1, initial, help, end);
        answ.push_back({initial, end});
        vector<ii> aux = solve(n - 1, help, end, initial);
        for(auto i : aux){
            answ.push_back(i);
        }

        return answ;
    }
}

void print(vector<char>& v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
    }
    cout << '\n';
}
int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    vector<char> v;
    vector<vector<char>> answ;
    for(int i = 0; i < s.size(); i++){
        v.push_back(s[i]);
    }

    sort(v.begin(), v.end());

    answ.push_back(v);
    while(next_permutation(v.begin(), v.end())) answ.push_back(v);

    cout << answ.size() << '\n';
    for(int i = 0; i < answ.size(); i++){
        print(answ[i]);
    }

    return 0;
}