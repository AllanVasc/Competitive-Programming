#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

struct PT{
    int x, y;
    PT(int x = 0, int y = 0) : x(x), y(y) {}
    PT operator + (const PT &p) const { return PT(x + p.x, y + p.y); }
    PT operator - (const PT &p) const { return PT(x - p.x, y - p.y); }
};
// Debug function
ostream &operator << (ostream &os, const PT &p){
    return os << "(" << p.x << "," << p.y << ")";
}
int cross (PT p, PT q) { return p.x * q.y - p.y * q.x; }

int quadrant(PT p){
    if(p.x < 0 && p.y < 0) return 0;
    if(p.x >= 0 && p.y < 0) return 1;
    if(p.x >= 0 && p.y >= 0) return 2;
    return 3;   // p.x < 0 && p.y >= 0
}

struct cmp{
    PT pivot;
    cmp (PT p): pivot(p) {}
    bool operator ()(PT a, PT b) const {
        a = a - pivot;
        b = b - pivot;
        if(quadrant(a) != quadrant(b)) return quadrant(a) < quadrant(b);
        return cross(a, b) > 0;
    }
};

// Call using
// sort(v.begin(), v.end(), cmp(pivot));

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("bedone.in", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<PT> v;
        for(int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            v.push_back(PT(x, y));

        }

        for(int i = 0; i < n; i++){
            PT pivot = v[i];
            vector<PT> aux;
            for(int j = 0; j < n; j++){
                if(j != i) aux.push_back(v[j]);
            }
            sort(aux.begin(), aux.end(), cmp(pivot));
            
            int l = 0, r = 0;
            int answ = n;
            int sz = aux.size();
            int cnt = 1;
            while(l < sz && answ != 0){
                // cout << "l = " << aux[l] << '\n';
                // cout << "r = " << aux[r] << "\n";
                while(l < sz && cross(aux[l] - pivot, aux[r % sz] - pivot) < 0){
                    l++;
                    cnt--;
                }
                answ = min(answ, sz - cnt);
                r++;
                cnt++;
            }

            cout << answ << '\n';
        }
    }
    return 0;
}