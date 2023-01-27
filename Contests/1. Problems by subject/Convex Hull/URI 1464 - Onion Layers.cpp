// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const double inf = 1e100, eps = 1e-12;
const double PI = acos(-1.0L);

int cmp(int a, int b = 0){
    if(abs(a-b) < eps) return 0;
    return (a < b) ? -1 : +1;
}

// Struct to represent a point/vector
struct PT{
    int x, y;
    PT(int x = 0, int y = 0) : x(x), y(y) {}
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

vector<PT> convexHull(vector<PT>& p, bool needSort = 1){
    if(needSort) sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    int n = p.size(), k = 0;
    if(n <= 1) return p;
    vector<PT> answ(2*n + 1);   // Must be 2*n + 1 for collinear points

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

    answ.resize(k); // n+1 points where the first is equal to the last
    return answ;
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;

    while(cin >> n && n != 0){

        vector<PT> v;
        for(int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;

            v.push_back(PT(x,y));
        }

        int count = 0;
        while(v.size()){
            vector<PT> answ;
            if(n == v.size()) answ = convexHull(v);
            else answ = convexHull(v, 0);

            // cout << "v = " << '\n';
            // for(int i = 0; i < v.size(); i++){
            //     cout << v[i] << '\n';
            // }

            // cout << "Camada = " << '\n';
            // for(int i = 0; i < answ.size(); i++){
            //     cout << answ[i] << '\n';
            // }
            
            count++;
            set<PT> check;
            for(int i = 0; i < answ.size(); i++){
                check.insert(answ[i]);
            }
            
            vector<PT> aux;
            for(int i = 0; i < v.size(); i++){
                if(check.count(v[i]) == 0){
                    aux.push_back(v[i]);
                }
            }
            v = aux;
        }

        if(count%2 == 1){
            cout << "Take this onion to the lab!" << '\n';
        }
        else{
            cout << "Do not take this onion to the lab!" << '\n';
        }

    }


    return 0;
}