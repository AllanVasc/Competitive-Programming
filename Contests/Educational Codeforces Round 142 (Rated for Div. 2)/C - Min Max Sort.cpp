#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        vector<int> pos(n + 1);
        for(int i = 0; i < n; i++){
            cin >> v[i];
            pos[v[i]] = i;
        }

        int answ = n / 2;
        int l, r;
        if(n % 2 == 1){
            l = n/2 + 1;
            r = n/2 + 1;
            answ++;
        }
        else{
            l = n / 2;
            r = l + 1;
        }

        int prevl = l;
        int prevr = r;
        while(pos[l] <= pos[r]){
            // cout << "l = " << l << " r = " << r << '\n';
            if(pos[l] <= pos[prevl] && pos[r] >= pos[prevr]){
                answ--;
                prevl = l;
                prevr = r;
            }
            else{
                break;
            }

            l--;
            r++;
            if(l == 0) break;
        }

        cout << answ << '\n';
    }
    return 0;
}