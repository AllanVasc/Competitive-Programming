#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;

bool check(int linha, int k, int limit){
    int total = 0;
    if(linha <= k){
        total += ((1 + linha) * linha) / 2;
    }
    else{
        total += ((1 + k) * k) / 2;
        int a1 = k;
        int an = a1 + (linha - k) * - 1;
        total += (a1 + an) * (linha - k + 1) / 2;
        total -= a1;
    }
    return total < limit;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int k, x;
        cin >> k >> x;

        int left = 0;
        int right = 2 * k - 1;
        int answ = 0;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(check(mid, k, x)){
                answ = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        // cout << "answ = " << answ << '\n';
        if(answ != 2*k - 1) answ++;
        cout << answ << '\n';
    }
   
    return 0;
}