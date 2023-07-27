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
        int n, k, g;
        cin >> n >> k >> g;

        int maxRest = (g + 1) / 2 - 1;

        if(n * maxRest >= k * g){
            cout << k * g << '\n';
        }
        else{
            int falta = k * g - (n * maxRest);
            falta %= g;

            int answ = (n - 1) * maxRest;
            int newVal = maxRest + falta;
            int rest = newVal % g;
            if(rest >= (g + 1) / 2){
                answ -= g - rest;
            }
            else{
                answ += rest;
            }
            cout << answ << '\n';
        }
    }
    return 0;
}