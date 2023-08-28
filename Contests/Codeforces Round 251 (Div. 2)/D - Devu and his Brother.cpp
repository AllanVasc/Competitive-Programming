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

signed main() {
    optimize;
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    set<int> conj;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> psa(n + 1, 0), psb(m + 1, 0);
    for(int i = 0; i < n; i++){
        conj.insert(a[i]);
        psa[i + 1] = psa[i] + a[i];
    }
    for(int i = 0; i < m; i++){
        conj.insert(b[i]);
        psb[i + 1] = psb[i] + b[i];
    }

    int answ = INF;
    for(auto val : conj){
        // cout << "chutando " << val << '\n';
        int cnt = 0;
        int posA = lower_bound(a.begin(), a.end(), val) - a.begin();
        // cout << "posA = " << posA << '\n';
        if(posA == n){
            cnt += (posA * val) - psa[posA];
        }
        else{
            if(a[posA] > val) posA--;
            cnt += (posA + 1) * val - psa[posA + 1];
        }
        // cout << "cnt = " << cnt << '\n';
        int posB = lower_bound(b.begin(), b.end(), val + 1) - b.begin();
        // cout << "posB = " << posB << '\n';
        if(posB == m){
            cnt += (val - b.back());
        }
        else{
            cnt += (psb.back() - (psb[posB])) - (val * (m - posB));
        }
        // cout << "cnt = " << cnt << '\n';
        answ = min(answ, cnt);
    }

    cout << answ << '\n';
    return 0;
}