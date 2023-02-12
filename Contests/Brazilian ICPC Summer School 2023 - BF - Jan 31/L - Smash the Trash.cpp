#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;

vector<int> v;
bool check(int pessoas){
    int offset = 0;
    int n = v.size();
    for(int i = 0; i < n; i++){
        if(i == n - 1){
            if(v[i] + offset <= pessoas) return true;
            else return false;
        }
        
        if(v[i] + offset <= pessoas){
            offset = 0;
            continue;
        }
        int x = 2 * pessoas - (v[i] + offset);
        if(x < 0) return false;
        int y = (v[i] + offset) - pessoas;
        offset = 2 * y;
    }

    return true;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    
    v.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> v[i];

    int left = v.back();
    int right = 1e6;
    int answ = -1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(check(mid)){
            answ = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    cout << answ << '\n';
   
    return 0;
}