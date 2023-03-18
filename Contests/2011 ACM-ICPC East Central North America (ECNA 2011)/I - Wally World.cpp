#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

using ii = pair<int,int>;

const double inf = 1e100, eps = 1e-12;
const double PI = acos(-1.0L);
int cmp(double a, double b = 0){
    if(abs(a-b) < eps) return 0;
    return (a < b) ? -1 : +1;
}

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

double dot (PT p, PT q) { return p.x * q.x + p.y * q.y; }
double cross (PT p, PT q) { return p.x * q.y - p.y * q.x; }
double dist (PT p, PT q) { return hypot(p.x - q.x, p.y - q.y); }

bool parallel(PT a, PT b, PT c, PT d){
    return cmp(cross(b - a, c - d)) == 0;
}
bool collinear(PT a, PT b, PT c, PT d){
    return parallel(a, b, c, d) && cmp(cross(a - b, a - c)) == 0 && cmp(cross(c - d, c - a)) == 0;
}

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

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ii l1, l2;
    int cnt = 1;
    cout << fixed << setprecision(3);
    while(cin >> l1.first >> l1.second >> l2.first >> l2.second){
        if(l1.first == l1.second && 
           l1.second == l2.first && 
           l2.first == l2.second && 
           l2.second == 0) break;
        cout << "Case " << cnt << ": ";
        cnt++;
        ii start, end;
        cin >> start.first >> start.second >> end.first >> end.second;

        PT lover1(l1.first, l1.second);
        PT lover2(l2.first, l2.second);
        PT line1(start.first, start.second);
        PT line2(end.first, end.second);
        if(segmentIntersection(lover1, lover2, line1, line2)){
            double val1 = (dist(lover1, line1) + dist(lover2, line1)) / 2.0;
            double val2 = (dist(lover1, line2) + dist(lover2, line2)) / 2.0;
            double answ = min(val1, val2);

            cout << answ << '\n';
        }
        else{
            double answ = dist(lover1, lover2) / 2.0;
            cout << answ << '\n';
        }
    }
    return 0;
}