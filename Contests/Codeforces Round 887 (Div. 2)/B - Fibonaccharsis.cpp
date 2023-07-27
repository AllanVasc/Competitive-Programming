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

const int ms = 2e5 + 5;

signed main() {
    optimize;
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if(k > 3 * n){
            cout << 0 << '\n';
        }
        else{
            int lastA = 0;
            int coefA = 1;  // k = 3
            int lastB = 1;
            int coefB = 1;
            for(int i = 4; i <= k; i++){
                int aux = coefA;
                coefA = coefA + lastA;
                lastA = aux;
                aux = coefB;
                coefB = coefB + lastB;
                lastB = aux;
            }
            // cout << "a = " << coefA << '\n';
            // cout << "b = " << coefB << '\n';
            int x = 0;
            int answ = 0;
            while(x <= n){
                int y = n - coefA * x;
                
                if(y % coefB == 0 && y/coefB >= x){
                    // cout <<"x = " << x << " y = " << y << '\n';
                    answ++;
                }
                x++;
            }
            cout << answ << '\n';
        }
    }
    return 0;
}