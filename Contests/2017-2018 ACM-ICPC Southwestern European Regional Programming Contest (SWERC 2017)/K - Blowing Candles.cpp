#include <bits/stdc++.h>

using namespace std;
#define double long double

const double inf = 1e100, eps = 1e-9;
int cmp(double a, double b){
    if(abs(a- b) < eps) return 0;
    return (a < b) ? -1:1;
}

struct PT{
    double x, y;
    PT(double x = 0, double y = 0) : x(x), y(y){}

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
ostream &operator<<(ostream &os, const PT &p) {
  return os << "(" << p.x << "," << p.y << ")"; 
}
double dot(PT p, PT q) { return p.x * q.x + p.y * q.y; }
double cross(PT p, PT q){ return p.x*q.y - p.y*q.x; }
PT rotateCCW90(PT p) { return PT(-p.y, p.x); }
double dist(PT p, PT q){
    return hypot(p.x - q.x, p.y - q.y);
}
PT projPtLine(PT a, PT b, PT c){
    return a + (b - a) * dot(b - a, c - a) / dot(b - a, b - a);
}
double distPointSegment(PT a, PT b, PT c){
    // cout << projPtLine(a, b, c) << " ";
    // cout << projPtLine(b, a, c) << "\n";
    return dist(c, projPtLine(a, b, c));
}

vector<PT> convexHull(vector<PT> p, bool needs = 1) {
  if(needs) sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  int n = p.size(), k = 0;
  if(n <= 1) return p;
  vector<PT> h(n + 2);
  for(int i = 0; i < n; i++) {
    while(k >= 2 && cross(h[k - 1] - h[k - 2], p[i] - h[k - 2]) <= 0) k--;
    h[k++] = p[i];
  }
  for(int i = n - 2, t = k + 1; i >= 0; i--) {
    while(k >= t && cross(h[k - 1] - h[k - 2], p[i] - h[k - 2]) <= 0) k--;
    h[k++] = p[i];
  }
  h.resize(k);
  return h;
}

int maximizeDotProduct(const vector <PT> &hull, PT vec){
    int ans = 0;
    int n = hull.size();

    if(n < 20){
        for(int i = 0; i < n; i++){
            if(dot(hull[i], vec) > dot(hull[ans], vec))
                ans = i;
        }
    }

    else{
        if(dot(hull[1], vec) > dot(hull[ans], vec)) ans = 1;

        for(int rep = 0; rep < 2; rep++){
            int l = 2, r = n - 1;
            
            while(l != r){
                int mid = (l + r + 1) / 2;
                bool flag = dot(hull[mid], vec) >= dot(hull[mid - 1], vec);

                if(!rep){
                    flag = flag && dot(hull[mid], vec) >= dot(hull[0], vec);
                }
                else
                    flag = flag || dot(hull[mid - 1], vec) < dot(hull[0], vec);

                if(flag) l = mid;
                else r = mid - 1;
            }

            if(dot(hull[ans], vec) < dot(hull[l], vec)) ans = l;
        }
    }

    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(16) << fixed;

    int n, r;
    cin >> n >> r;

    vector <PT> points, hull;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;

        points.emplace_back(x, y);
    }

    hull = convexHull(points);

    double ans = 1e18;
    for(int i = 0; i+1 < hull.size(); i++){
        PT vec = hull[i+1] - hull[i];
        vec = rotateCCW90(vec);

        int p = maximizeDotProduct(hull, vec);
        ans = min(ans, distPointSegment(hull[i], hull[i+1], hull[p]));
    }

    cout << ans << "\n";
}