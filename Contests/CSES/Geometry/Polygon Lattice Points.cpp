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

// Function to calculate the dot product (u.v)
double dot (PT p, PT q) { return p.x * q.x + p.y * q.y; }

// Function to calculate the cross product (uXv) (2x2 determinant)
double cross (PT p, PT q) { return p.x * q.y - p.y * q.x; }

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<PT> v;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        v.push_back(PT(x, y));
    }

    int area = 0;
    int boundary = 0;
    for(int i = 0; i < n; i++){
        int j = (i + 1) % n;
        area += cross(v[i], v[j]);
        boundary += gcd((int)abs((v[i] - v[j]).x), (int)abs((v[i] - v[j]).y));
    }
    area = abs(area);
    int inside = (area - boundary + 2) / 2;

    cout << inside << " " << boundary << '\n';
    return 0;
}