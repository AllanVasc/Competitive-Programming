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

int32_t main() {
    optimize;
    
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        set<int> unique;
        bool less = false;
        int cnt = 0;
        int answ = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '<'){
                if(less == true){
                    cnt++;
                }
                else{
                    cnt = 1;
                }
                less = true;
            }
            else{
                if(!less){
                    cnt++;
                }
                else{
                    cnt = 1;
                }
                less = false;
            }
            answ = max(answ, cnt);
        }
        cout << answ + 1 << '\n'; 
    }
    return 0;
}