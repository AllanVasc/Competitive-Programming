#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int msb(int x){
    int msb_p = -1;
    while(x){
        x >>= 1;
        msb_p++;
    }
    return msb_p;
}

int andRange(int x, int y){
    int answ = 0;
    while(x && y){
        int msb_x = msb(x);
        int msb_y = msb(y);

        if(msb_x != msb_y) break;
        int value = (1LL << msb_x);
        answ += value;
        x -= value;
        y -= value;
    }
    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;

        int left = n;
        int right = 5e18;
        int answ = -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            int value = andRange(n, mid);
            if(value <= m){
                if(value == m) answ = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        cout << answ << '\n';
    }
    return 0;
}