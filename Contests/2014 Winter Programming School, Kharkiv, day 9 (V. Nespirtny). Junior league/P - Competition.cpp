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
    
    long double a, b, c;
    cin >> a >> b >> c;

    vector<long double> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    sort(v.begin(), v.end());
    if(v[0] + v[1] > v[2]){
        long double x1 = 0;
        long double y1 = 0;
        long double x2 = a;
        long double y2 = 0;
        long double x3 = (c * c - b* b + a * a) / (long double) (2 * a);
        long double y3 = sqrtl(c * c - x3 * x3);

        cout << fixed << setprecision(6);
        cout << x1 << " " << y1 << '\n';
        cout << x2 << " " << y2 << '\n';
        cout << x3 << " " << y3 << '\n';
    }
    else{
        cout << "Impossible" << '\n';
    }
    return 0;
}