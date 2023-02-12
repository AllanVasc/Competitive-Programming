#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string s;
    cin >> s;
    map<char, int> freq;
    for(int i = 0; i < s.size(); i++){
        freq[s[i]]++;
    }
    int answ = 0;
    for(auto i : freq){
        answ += i.second * i.second;
    }
    cout << answ << '\n';
    return 0;
}