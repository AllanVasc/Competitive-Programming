// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
 
#include <bits/stdc++.h>
using namespace std;
 
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
 
// Function to calculate the cross product (uXv) (2x2 determinant)
double cross (PT p, PT q) { return p.x * q.y - p.y*q.x; }
 
// Function to calculate the magnitude of the vector (|u|)
double norm (PT p) { return hypot(p.x, p.y); }
 
// Monotone chain Algorithm to calculate Convex Hull
vector<PT> convexHull(vector<PT> p, bool needSort = 1){
    if(needSort) sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    int n = p.size(), k = 0;
    if(n <= 1) return p;
    vector<PT> answ(2*n + 2);   // Must be 2*n + 1 for collinear points
 
    // Lower hull
    for(int i = 0; i < n; i++){
        while(k >= 2 && cross(answ[k-1] - answ[k-2], p[i] - answ[k-2]) < 0) k--; // If collinear points are allowed put only "<"
        answ[k++] = p[i];
    }
 
    // Upper hull
    for(int i = n - 2, t = k + 1; i >= 0; i--) {
        while(k >= t && cross(answ[k - 1] - answ[k - 2], p[i] - answ[k - 2]) < 0) k--; // If collinear points are allowed put only "<"
        answ[k++] = p[i];
    }
 
    answ.resize(k-1); // n+1 points where the first is equal to the last
    return answ;
}
 
int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    vector<PT> pt;
 
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        pt.push_back(PT(x,y));
    }
 
    vector<PT> answ = convexHull(pt);
 
    cout << fixed << setprecision(0);
    
    cout << answ.size() << '\n';
    for(int i = 0; i < answ.size(); i++){
        cout << answ[i].x << " " << answ[i].y <<'\n';
    }
    
    return 0;
}