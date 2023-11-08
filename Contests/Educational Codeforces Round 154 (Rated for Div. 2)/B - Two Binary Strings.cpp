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

bool isEqual(string & s1, string & s2, int l, int r){
    for(int i = l; i <= r; i++){
        if(s1[i] != s2[i]) return false;
    }
    return true;
}

bool check(string & s1, string & s2){
    int n = s1.size();
    bool found = false;
    for(int i = 0; i < n && !found; i++){
        if(s1[0] == s1[i] && s2[0] == s2[i]){
            for(int j = n - 1; j > i; j--){
                if(s1[n - 1] == s1[j] && s2[n - 1] == s2[j]){
                    if(isEqual(s1, s2, i + 1, j - 1)){
                        found = true;
                        break;
                    }
                }
            }
        }
    }
    return found;
}

signed main() {
    optimize;
    int t; cin >> t;
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;
        if(s1 == s2){
            cout << "YES" << '\n';
            continue;
        }
        bool answ = check(s1, s2);\
        // reverse(s1.begin(), s1.end());
        // reverse(s2.begin(), s2.end());
        // answ |= check(s1, s2);
        cout << (answ ? "YES" : "NO") << '\n';
    }
    return 0;
}