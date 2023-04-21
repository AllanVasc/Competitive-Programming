#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const double inf = 1e100, eps = 1e-9;
const double PI = acos(-1.0L);
int cmp (double a, double b = 0) {
  if (abs(a-b) < eps) return 0;
  return (a < b) ? -1 : +1;
}
struct PT {
  double x, y;
  PT(double x = 0, double y = 0) : x(x), y(y) {}
  PT operator + (const PT &p) const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p) const { return PT(x-p.x, y-p.y); }
  PT operator * (double c) const { return PT(x*c, y*c); }
  PT operator / (double c) const { return PT(x/c, y/c); }
  bool operator <(const PT &p) const {
    if(cmp(x, p.x) != 0) return x < p.x;
    return cmp(y, p.y) < 0;
  }
  bool operator ==(const PT &p) const {return !cmp(x, p.x) && !cmp(y, p.y);}
  bool operator != (const PT &p) const {return !(p == *this);}
};

double dist (PT p, PT q) { return hypot(p.x-q.x, p.y-q.y); }
double norm (PT p) { return hypot(p.x, p.y); }
PT rotateCCW90 (PT p) { return PT(-p.y, p.x); }

vector<PT> circleCircle (PT a, double r, PT b, double R) {
  vector<PT> ret;
  double d = norm(a-b);
  if (d > r + R || d + min(r, R) < max(r, R)) return ret;
  double x = (d*d - R*R + r*r) / (2*d); // x = r*cos(R opposite angle)
  double y = sqrt(r*r - x*x);
  PT v = (b - a)/d;
  ret.push_back(a + v*x + rotateCCW90(v)*y);
  if (cmp(y) > 0)
    ret.push_back(a + v*x - rotateCCW90(v)*y);
  return ret;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int x1, y1, x2, y2, d;
    cin >> x1 >> y1 >> x2 >> y2 >> d;
    PT a(x1, y1);
    PT b(x2, y2);
    vector<PT> answ = circleCircle(a, d, b, dist(a,b));
    cout << fixed << setprecision(8);
    if(answ.size() < 2){
        cout << "NO" << '\n';
    }
    else{
        cout << "YES" << '\n';
        cout << answ[0].x << " " << answ[0].y << " " 
             << answ[1].x << " " << answ[1].y << '\n';
    }
    return 0;
}