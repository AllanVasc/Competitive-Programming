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

// Returns true if a point c is on segment a-b
bool ptInSegment(PT a, PT b, PT c){
    if(a == b) return a == c;
    a = a - c, b = b - c;
    return cmp(cross(a, b)) == 0 && cmp(dot(a, b)) <= 0;
}

int pointInPolygon(const vector<PT> &p, PT q){
    int windingNumber = 0;
    for(int i = 0; i < p.size(); i++){
        if(p[i] == q) return 0;
        int j = (i + 1) % p.size();
        if(p[i].y == q.y && p[j].y == q.y){ // "Throwing" the horizontal ray
            if(ptInSegment(p[i], p[j], q))
                return 0;
        }
        else{
            bool below = p[i].y < q.y;
            if(below == (p[j].y < q.y)) continue;
            auto orientation = cross(q - p[i], p[j] - p[i]);
            if(cmp(orientation) == 0) return 0;
            if(below == (orientation < 0)) windingNumber += below ? 1 : -1;
        }
    }
    return windingNumber == 0 ? 1 : -1;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<PT> polygon;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        polygon.push_back(PT(x, y));
    }
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        PT c(x,y);
        int answ = pointInPolygon(polygon, c);
        if(answ == -1){
            cout << "INSIDE\n";
        }
        else if(answ == 0){
            cout << "BOUNDARY\n";
        }
        else{
            cout << "OUTSIDE\n";
        }
    }
    return 0;
}