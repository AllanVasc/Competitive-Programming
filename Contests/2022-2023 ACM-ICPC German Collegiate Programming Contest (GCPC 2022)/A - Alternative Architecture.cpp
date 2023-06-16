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

int sq(int x){
    return x * x;
}
int32_t main() {
    optimize;
    
    int a, b;
    cin >> a >> b;
    a--, b--;
    int answ = 0;
    // [-a, a)
    for(int x1 = -a; x1 < a; x1++){
        int y1 = -1;
        int l = 0;
        int r = 1e6 + 5;
        int val = sq(a) - sq(x1);
        while(l <= r){
            int mid = l + (r - l)/2;
            if(mid * mid <= val){
                y1 = max(y1, mid);
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        if(sq(y1) != val) continue;
        // cout << "y1 = " << y1 << '\n';
        if((y1 * b) % a != 0) continue;
        if((x1 * b) % a != 0) continue;
        answ++;
    }
    cout << (a == b ? answ/2 : answ) << '\n';
    return 0;
}