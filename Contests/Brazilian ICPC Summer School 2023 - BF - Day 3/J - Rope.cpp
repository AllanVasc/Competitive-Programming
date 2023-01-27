#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<long double,long double>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

long double dist(ii a, ii b){
    long double answ = sqrtl( (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
    // cout << answ << '\n';
    return answ ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    long double r;
    cin >> n >> r;

    vector<ii> points(n);
    for(int i = 0; i < n; i++){
        cin >> points[i].first >> points[i].second;
    }
    long double comprimento = 2*r*acos(-1);

    cout << fixed << setprecision(2);
    if(n == 1){
        cout << comprimento << '\n';
    }
    else{

        long double answ = 0;
        for(int i = 0; i < n; i++){
            answ += dist(points[i], points[(i + 1) % n]);
        }
        
        cout << answ + comprimento << '\n';
    }

    return 0;
}