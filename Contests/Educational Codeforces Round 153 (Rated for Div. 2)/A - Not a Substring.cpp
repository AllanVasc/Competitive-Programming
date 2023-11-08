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

signed main() {
    optimize;
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        string answ1, answ2;
        while(answ1.size() != 2 * s.size()){
            answ1 += "()";
        }
        while(answ2.size() != 2 * s.size()){
            answ2 = "(" + answ2 + ")";
        }
        // cout << answ1 << '\n';
        // cout << answ2 << '\n';
        for(int i = 0; i < answ1.size(); i++){
            bool equal = true;
            if(i + s.size() > answ1.size()) continue;
            for(int j = 0; j < s.size(); j++){
                if(answ1[i + j] != s[j]){
                    equal = false;
                    break;
                }
            }
            if(equal) answ1.erase();
        }
        for(int i = 0; i < answ2.size(); i++){
            bool equal = true;
            if(i + s.size() > answ2.size()) continue;
            for(int j = 0; j < s.size(); j++){
                if(answ2[i + j] != s[j]){
                    equal = false;
                    break;
                }
            }
            if(equal) answ2.erase();
        }
        if(answ1.size()){
            cout << "YES" << '\n';
            cout << answ1 << '\n';
        }
        else if(answ2.size()){
            cout << "YES" << '\n';
            cout << answ2 << '\n';
        }
        else cout << "NO" << '\n';
    }
    return 0;
}