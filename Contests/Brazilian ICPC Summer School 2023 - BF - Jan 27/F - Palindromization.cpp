#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

bool is_palin(string & s, int start, int end){
    for(int l = start, r = end; l < r; l++, r--){
        if(s[l] != s[r]) return false;
    }
    return true;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string s;
    cin >> s;

    int n = s.size();
    if(is_palin(s, 0, n - 1)){
        cout << "YES" << '\n';
        cout << (n + 1) / 2 << '\n';
    }
    else{
        bool possible = false;
        int idx = -1;

        for(int l = 0, r = n - 1; l < r; l++, r--){
            if(s[l] != s[r]){
                if(is_palin(s, l + 1, r)){
                    possible = true;
                    idx = l;
                }
                else if(is_palin(s, l, r - 1)){
                    possible = true;
                    idx = r;
                }
                break;
            }
        }
        if(possible){
            cout << "YES" << '\n';
            cout << idx + 1 << '\n';
        }
        else{
            cout << "NO" << '\n';
        }
    }
    
    return 0;
}