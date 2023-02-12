#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define double long double

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

// Debug function
ostream &operator << (ostream &os, const PT &p){
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

// Function to calculate the dot product (u.v)
double dot (PT p, PT q) { return p.x * q.x + p.y*q.y; }

double dist (PT p, PT q) { return hypot(p.x-q.x, p.y-q.y); }

double pointToSegmentDist(PT a, PT b, PT p){
    PT vec_ab = b - a;
    PT vec_ap = p - a;
    double proj = dot(vec_ap, vec_ab);
    double abLenSquared = vec_ab.x * vec_ab.x + vec_ab.y * vec_ab.y;
    double distInSeg = proj / abLenSquared;
    PT closestPoint;
    if(distInSeg <= 0){
        closestPoint = a;
    }
    else if(distInSeg >= 1){
        closestPoint = b;
    }
    else{
        closestPoint = a + vec_ab * distInSeg;
    }
    return dist(closestPoint, p);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int x,y, x1,y1,x2,y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;

    double answ = INF;
    PT p1(x1, y1);
    PT p2(x2, y1);
    PT p3(x2,y2);
    PT p4(x1, y2);
    PT p(x, y);
    answ = min(answ, pointToSegmentDist(p1, p2, p));
    answ = min(answ, pointToSegmentDist(p2, p3, p));
    answ = min(answ, pointToSegmentDist(p3, p4, p));
    answ = min(answ, pointToSegmentDist(p4, p1, p));

    cout << fixed << setprecision(3);
    cout << answ << '\n';
    return 0;
}