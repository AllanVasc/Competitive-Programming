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

    string s = "a";
    int i = 0;
    int limit = 0;
    int offset = 0;
    while(s.size() != n){
        if(i == limit){
            offset++;
            s.push_back('a' + offset);
            limit = s.size() - 1;
            i = 0;
        }
        else{
            s.push_back(s[i]);
            i++;
        }
    }

    cout << s << '\n';
    return 0;
}