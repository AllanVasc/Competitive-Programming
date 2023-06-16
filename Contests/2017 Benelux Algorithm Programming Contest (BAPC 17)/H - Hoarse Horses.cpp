#include <bits/stdc++.h>
using namespace std;

#define int long long
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

vector<vector<int>> g;
vector<bool> visited;
void dfs(int u){
    visited[u] = true;
    for(auto v : g[u]){
        if(!visited[v]) dfs(v);
    }
}

#define Vector Point

int sign(int x) {
    return !x ? 0 : (x < 0 ? -1 : 1);
}

template<typename T>
struct Point {
    T x, y;

    Point(): x(0), y(0) {}
    Point(T x, T y): x(x), y(y) {}

    Vector<T> operator -() {
        return Vector<T>(-x, -y);
    }

    Point<T> operator +(Vector<T> v) {
        return Point<T>(x + v.x, y + v.y);
    }

    Vector<T> operator -(Point<T> other) {
        return Point<T>(x - other.x, y - other.y);
    }

    Vector<T> operator *(T k) {
        return Vector<T>(x * k, y * k);
    }

    T operator *(Vector<T> other) {
        return x * other.x + y * other.y;
    }

    T operator /(Vector<T> other) {
        return x * other.y - y * other.x;
    }

    bool operator <(const Point<T> &other) const {
        if (!sign(x - other.x))
            return sign(y - other.y) < 0;

        return sign(x - other.x) < 0;
    }
};

template<typename T>
bool intersect(T a, T b, T c, T d) {
    if (sign(a - b) > 0) swap(a, b);
    if (sign(c - d) > 0) swap(c, d);
    return sign(max(a, c) - min(b, d)) <= 0;
}

template<typename T>
bool seg_seg(Point<T> A, Point<T> B, Point<T> C, Point<T> D) {
    Vector<T> CA = A - C, CB = B - C, CD = D - C;
    if (!sign(CA / CD) && !sign(CB / CD))
        return intersect(A.x, B.x, C.x, D.x) && intersect(A.y, B.y, C.y, D.y);

    Vector<T> AB = B - A, AC = C - A, AD = D - A;
    return sign(AB / AC) != sign(AB / AD) && sign(CA / CD) != sign(CB / CD);
}

int32_t main() {
    optimize;
    
    int n;
    cin >> n;
    g.assign(n, vector<int>());
    visited.assign(n, false);
    vector<pair<Point<int>, Point<int>>> lines;
    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        lines.pb({Point(x1, y1), Point(x2, y2)});
    }
    int intersections = 0;
    for(int i = 0; i < n; i++){
        auto [a, b] = lines[i]; 
        for(int j = i + 1; j < n; j++){
            auto [c, d] = lines[j]; 
            if(seg_seg(a, b, c, d)){
                intersections++;
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    int components = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            components++;
            dfs(i);
        }
    }
    cout << components - n + intersections << '\n';
    return 0;
}