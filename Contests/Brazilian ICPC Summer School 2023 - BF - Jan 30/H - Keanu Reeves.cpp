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

    int n;
    cin >> n;
    string s;
    cin >> s;

    int ones = 0, zeros = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') zeros++;
        else ones++;
    }

    if(zeros != ones){
        cout << 1 << '\n';
        cout << s << '\n';
    }
    else{
        cout << 2 << '\n';
        cout << s.substr(0, n - 1) << " " << s.back() << '\n';
    }
    return 0;
}