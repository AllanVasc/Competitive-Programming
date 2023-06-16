#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

const double PI = acos(-1);

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int m, n;
    double r;
    int ax, ay, bx, by;
    cin >> m >> n >> r;
    cin >> ax >> ay >> bx >> by;

    double answ = 1e100;

    for(int i = 0; i <= n; i++){
        answ = min(answ, abs(ay - i) * r / (1.0 * n) + abs(by - i) * r / (1.0 * n) + abs(ax - bx) * PI * (i * r / (1.0 * n)) / (1.0 * m));
    }
    cout << setprecision(8) << fixed;
    cout << answ << '\n';
    return 0;
}