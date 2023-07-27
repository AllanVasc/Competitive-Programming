#include <bits/stdc++.h>

using namespace std;
#define int long long

double eps = 1e-6;
int cmp(long double a, long double b){
    if(abs(a - b) < eps) return 0;
    if(a < b) return -1;
    else return 1;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("joy.in", "r", stdin);
    freopen("joy.out", "w", stdout);

    int sx, sy, fx, fy;
    cin >> sx >> sy >> fx >> fy;

    int nfx = fx, nfy = fy;
    int n, k, v;
    cin >> n >> k >> v;

    vector <tuple <int, int, int>> w(n);
    vector <pair <int, int>> ws(k);
    for(int i = 0; i < n; i++){
        int t, x, y;
        cin >> t >> x >> y;

        w[i] = {t, x, y};
    }

    int cur = 0, wnx = 0, wny = 0;
    for(int i = 0; i < k; i++){
        if(cur < n && get<0>(w[cur]) == i){
            wnx = get<1>(w[cur]);
            wny = get<2>(w[cur]);
            cur++;
        }
    
        ws[i] = {wnx, wny};
        nfx -= wnx;
        nfy -= wny;
    }


    if(cmp(v * k, hypot((nfx - sx), (nfy - sy))) < 0){
        cout << "No\n";
        return 0;
    }

    long double nv = hypot((nfx - sx), (nfy - sy));
    long double vx, vy, posx = sx, posy = sy, alpha;
    alpha = atan2((nfy - sy), (nfx - sx));
    vx = nv / k * cosl(alpha);
    vy = nv / k * sinl(alpha);

    // cout << vx << " " << vy << "\n";

    cout << "Yes\n";
    cout << setprecision(9) << fixed;
    for(int i = 0; i < k; i++){
        posx += vx + ws[i].first;
        posy += vy + ws[i].second;

        cout << posx << " " << posy << "\n";
    }

    return 0;
}