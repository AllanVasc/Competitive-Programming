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

int f(int x, int a, int b){
    return (b + 20*x) * (a - 4 * x);
}

int calc(int bonus, int op){
    // [0, op]
    int lo = -1, hi = op;
    while (hi - lo > 1){
        int mid = (hi + lo)>>1;
        if (f(mid, op, bonus) > f(mid + 1, op, bonus)) 
            hi = mid;
        else 
            lo = mid; 
    }

    return f(lo + 1, op, bonus);        // Return the maximum of f(x) in [l, r]
}

signed main() {
    optimize;
    int t; 
    cin >> t;
    while(t--){
        int s, k;
        cin >> s >> k;
        int answ = s*k;
        if(s % 10 == 5){
            answ = max(answ, (s + 5) * (k - 1));
        }
        else if(s % 10){
            for(int i = 0; i < 4; i++){
                if(!k) break;
                int last = s % 10;
                s += last;
                k--;
                if(k) answ = max(answ, calc(s, k));
            }
        }
        cout << answ << '\n';
    }
    return 0;
}