#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define double long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;

// Struct to represent a point/vector
struct PT{
    double x, y;
    PT(double x = 0, double y = 0) : x(x), y(y) {}
    PT operator + (const PT &p) const { return PT(x + p.x, y + p.y); }
    PT operator - (const PT &p) const { return PT(x - p.x, y - p.y); }
    PT operator * (double c) const { return PT(x*c, y*c); }
    PT operator / (double c) const { return PT(x/c, y/c); }
};

// Polygon area using Shoelace Formula.
// Points need to be sorted in clockwise or counterclockwise.
double signedPolygonArea(const vector<PT> &p){
    double area = 0;
    for(int i = 0; i < p.size(); i++){
        int j = (i + 1) % p.size();
        area += p[i].x * p[j].y - p[j].x * p[i].y;
    }
    return area;
}

double polygonArea(const vector<PT> &p){ return abs(signedPolygonArea(p)); }

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<PT> p;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        p.push_back(PT(x,y));
    }

    cout << polygonArea(p) << '\n';
    return 0;
}