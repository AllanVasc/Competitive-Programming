#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

long double eps = 1e-9;
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        long double b1, p1, b2, p2;
        cin >> b1 >> p1 >> b2 >> p2;
        
        if(b1 == 0 || b2 == 0){
            if(b1 == 0 && b2 == 0) cout << "Lazy" << '\n';
            else if(b1 == 0) cout << "Congrats" << '\n';
            else cout << "HaHa" << '\n';
        }
        else{
            long double s1, s2;
            s1 = p1 * log(b1); 
            s2 = p2 * log(b2);
            if(abs(s1 - s2) <= eps) cout << "Lazy" << '\n';
            else if(s1 > s2) cout << "HaHa" << '\n';
            else cout << "Congrats" << '\n';
        }
    }

    return 0;
}