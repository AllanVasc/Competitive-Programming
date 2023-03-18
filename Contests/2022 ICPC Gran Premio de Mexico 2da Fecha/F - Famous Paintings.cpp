#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long long

struct PT{
    double x, y;
    PT(double x = 0, double y = 0) : x(x), y(y) {}
    PT operator + (const PT &p) const { return PT(x + p.x, y + p.y); }
    PT operator - (const PT &p) const { return PT(x - p.x, y - p.y); }
    PT operator * (double c) const { return PT(x*c, y*c); }
    PT operator / (double c) const { return PT(x/c, y/c); }
};

double dot (PT p, PT q) { return p.x * q.x + p.y * q.y; }
double cross (PT p, PT q) { return p.x * q.y - p.y * q.x; }

bool parallel(PT a, PT b, PT c, PT d){
    return (cross(b - a, c - d)) == 0;
}

bool collinear(PT a, PT b, PT c, PT d){
    return parallel(a, b, c, d) && (cross(a - b, a - c)) == 0 && (cross(c - d, c - a)) == 0;
}

int32_t main(){
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

    int answ = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                for(int l = k + 1; l < n; l++){
                    if(collinear(v[i], v[j], v[j], v[k]) ||
                       collinear(v[i], v[j], v[k], v[l]) ||
                       collinear(v[i], v[j], v[l], v[i]) ||
                       
                       collinear(v[j], v[k], v[k], v[l]) ||
                       collinear(v[j], v[k], v[k], v[i]) ||

                       collinear(v[k], v[l], v[l], v[i])) continue;
                    
                    answ++;
                }
            }
        }
    }
    cout << answ << '\n';
    return 0;
}