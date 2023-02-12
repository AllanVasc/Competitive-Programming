#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;

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

// Function to calculate the dot product (u.v)
double dot (PT p, PT q) { return p.x * q.x + p.y * q.y; }

// Function to calculate the cross product (uXv) (2x2 determinant)
double cross (PT p, PT q) { return p.x * q.y - p.y * q.x; }

// Returns true if 2 lines are parallel
bool parallel(PT a, PT b, PT c, PT d){
    return cmp(cross(b - a, c - d)) == 0;
}

// Returns true if two segments are collinear
bool collinear(PT a, PT b, PT c, PT d){
    return parallel(a, b, c, d) && cmp(cross(a - b, a - c)) == 0 && cmp(cross(c - d, c - a)) == 0;
}

// Returns true if two segments are intersecting at some point
bool segmentIntersection(PT a, PT b, PT c, PT d){
    if(collinear(a, b, c, d)){
        if(a == c || a == d || b == c || b == d) return true;
        if(cmp(dot(c - a, c - b)) > 0 && cmp(dot(d - a, d - b)) > 0 && cmp(dot(c - b, d - b)) > 0) return false;
        return true;
    }
    if(cmp(cross(d - a, b - a) * cross(c - a, b - a)) > 0) return false;
    if(cmp(cross(a - c, d - c) * cross(b - c, d - c)) > 0) return false;
    return true;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        PT a(x1, y1);
        PT b(x2, y2);
        PT c(x3, y3);
        PT d(x4, y4);

        if(segmentIntersection(a, b, c, d)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}