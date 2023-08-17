#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
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

const double inf = 1e100, eps = 1e-9;
const double PI = acos(-1.0L);

int cmp(double a, double b = 0) {
  if (abs(a-b) < eps) return 0;
  return (a < b) ? -1 : +1;
}

struct pt{
    int x, y;
    pt(int x = 0, int y = 0) : x(x), y(y) {}
    pt operator + (const pt &p) const { return pt(x + p.x, y + p.y); }
    pt operator - (const pt &p) const { return pt(x - p.x, y - p.y); }
    pt operator * (int c) const { return pt(x * c, y * c); }

};

// Debug function
ostream &operator << (ostream &os, const pt &p){
    return os << "(" << p.x << "," << p.y << ")";
}

int quadrant(pt p){
    if(p.x < 0 && p.y < 0) return 2;
    if(p.x >= 0 && p.y < 0) return 3;
    if(p.x >= 0 && p.y >= 0) return 0;
    return 1;
}

// Function to calculate the dot product (u.v)
int dot (pt p, pt q) { return p.x * q.x + p.y * q.y; }
// Function to calculate the cross product (uXv) (2x2 determinant)
int cross (pt p, pt q) { return p.x * q.y - p.y * q.x; }

double angle (pt p, pt q) { return atan2(cross(p, q), dot(p, q)); }
double polarAngle (pt p) {
  double a = atan2(p.y, p.x);
  return a < 0 ? a + 2*PI : a;
}

struct polar_sort{
    pt pivot;
    polar_sort(pt p) : pivot(p) {}
    bool operator ()(pt a, pt b) const {
        a = a - pivot;
        b = b - pivot;
        if(quadrant(a) != quadrant(b)) return quadrant(a) < quadrant(b);
        return cross(a, b) > 0;
    }
};

signed main() {
    optimize;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pt> v;
        for(int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            v.push_back(pt(x, y));
        }
        sort(v.begin(), v.end(), polar_sort(pt(0, 0)));
        int answ = 0;
        int l = 0;
        int r = l;
        int cnt = 0;
        while(l < n){
            while(cnt < n){
                bool isInLeft = (cross(v[l], v[r % n]) >= 0);
                if(isInLeft){
                    cnt++;
                    r++;
                    r %= n;
                }
                else{
                    break;
                }
            }
            // cout << "consigo remover de [" << l << "," << r << ")\n";
            // cout << "cnt = " << cnt << '\n';
            answ = max({answ, cnt});
            if(cnt == n) break;
            cnt--;
            l++;
        }
        cout << n - answ << '\n';
    }
    return 0;
}