#include <bits/stdc++.h>

#define int long long
using namespace std;
long double eps = 1e-11;
const int  INF = 1e9;

vector<int> v;

bool check(int lim, int k){
    int cnt = 0;
    int n = v.size();
    for(int i = 0; i < n; i++){
        if(v[i] >= lim) break;
        auto pos = upper_bound(v.begin(), v.end(), lim - v[i]) - v.begin();
        pos--;
        if(pos > i){
            cnt += pos - i;
        }
        if(cnt >= k) return true;
    }
    return (cnt >= k);
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    v.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int l = v[0] + v[1];
    int r = v[n - 1] + v[n - 1];
    int answ = r;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid, k)){
            answ = min(answ, mid);
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << answ << '\n';
    return 0;
}