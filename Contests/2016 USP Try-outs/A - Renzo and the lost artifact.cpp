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

const double inf = 1e100, eps = 1e-12;
const double PI = acos(-1.0L);

int cmp(double a, double b = 0){
    if(abs(a-b) < eps) return 0;
    return (a < b) ? -1 : +1;
}

// Struct to represent a point/vector
struct PT{
    double x, y;
    PT(double x = 0, double y = 0) : x(x), y(y) {}
    PT operator + (const PT &p) const { return PT(x + p.x, y + p.y); }
    PT operator - (const PT &p) const { return PT(x - p.x, y - p.y); }
    PT operator * (double c) const { return PT(x*c, y*c); }
    PT operator / (double c) const { return PT(x/c, y/c); }
    bool operator < (const PT &p) const {
        if(cmp(x, p.x) != 0) return x < p.x;
        return cmp(y, p.y) < 0;
    }
    bool operator == (const PT &p) const { return !cmp(x, p.x) && !cmp(y, p.y); }
    bool operator != (const PT &p) const { return !(p == *this); }
};

vector<PT> v;
PT func(PT x0, double h, double w){
    PT v2 = v[3] - v[0];
    PT u2 = v[1] - v[0];
    return v[0] + (u2 * (x0.x / w)) + (v2 * (x0.y / h));
}
signed main() {
    optimize;
    int h, w;
    cin >> h >> w;
    for(int i = 0; i < 4; i++){
        double x, y;
        cin >> x >> y;
        v.push_back(PT(x, y));
    }
    PT answ(1, 1);
    for(int i = 0; i < 1e7; i++){
        answ = func(answ, h, w);
    }
    cout << setprecision(10) << fixed;
    cout << answ.x << " " << answ.y << '\n';
    return 0;
}