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

long double calc(long double b, long double h){
    return b * h / 2.0;
}

signed main() {
    optimize;
    int t;
    cin >> t;
    while(t--){
        int n, d, h;
        cin >> n >> d >> h;
        vector<int> pos(n);
        for(int i = 0; i < n; i++) cin >> pos[i];
        sort(ALL(pos));
        pos.erase(unique(pos.begin(), pos.end()), pos.end());
        n = pos.size();
        long double area = 0;
        for(int i = 1; i < n; i++){
            if(pos[i - 1] + h > pos[i]){
                // overlap
                long double hOver = pos[i - 1] + h - pos[i];
                long double newBase = (1.0 * hOver * d) / (1.0 * h);
                // cout << "new h = " << hOver << '\n';
                // cout << "new b = " << newBase << '\n';
                area += calc(d, h) - calc(newBase, hOver);
            }
            else{
                area += calc(d, h);
            }
        }
        area += calc(d, h);
        cout << setprecision(10) << fixed;
        cout << area << '\n';
    }
    return 0;
}