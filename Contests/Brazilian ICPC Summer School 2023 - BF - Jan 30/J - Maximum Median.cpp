#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<int> v;
bool check(int value, int op){
    int curr = 0;
    int n = v.size();

    for(int i = n / 2; i < n; i++){
        if(v[i] > value) continue;
        curr += (value - v[i]);
    }
    return (curr <= op);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;

    v.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    int answ = -1;

    int left = 1;
    int right = 1e10;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(check(mid, k)){
            answ = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    cout << answ << '\n';
    return 0;
}