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
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        vector<int> even;
        vector<int> evenPos;
        vector<int> odd;
        vector<int> oddPos;
        for(int i = 0; i < n; i++){
            cin >> v[i];
            if(v[i] % 2){
                odd.push_back(v[i]);
                oddPos.push_back(i);
            }
            else{
                even.push_back(v[i]);
                evenPos.push_back(i);
            }
        }
        sort(ALL(even));
        sort(ALL(evenPos));
        sort(ALL(odd));
        sort(ALL(oddPos));
        vector<int> answ(n);
        for(int i = 0; i < even.size(); i++){
            answ[evenPos[i]] = even[i];
        }
        for(int i = 0; i < odd.size(); i++){
            answ[oddPos[i]] = odd[i];
        }
        bool possible = true;
        for(int i = 1; i < n; i++){
            if(answ[i] < answ[i - 1]) possible = false;
        }
        cout << (possible ? "YES" : "NO") << '\n';
    }
    return 0;
}