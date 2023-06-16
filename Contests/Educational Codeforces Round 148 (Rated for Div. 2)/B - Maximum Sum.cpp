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
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        sort(ALL(v));
        int answ = 0;
        int currSum = 0;
        for(int i = 2*k; i < n; i++) currSum += v[i];
        //  << currSum << '\n';
        answ = max(answ, currSum);
        int l = 2*k - 1;
        int r = n - 1;
        while(l >= 0){
            currSum += v[l];
            currSum += v[l - 1];
            //  << currSum << '\n';
            l -= 2;
            currSum -= v[r];
            r--;
            answ = max(answ, currSum);
        }
        cout << answ << '\n';
    }
    return 0;
}