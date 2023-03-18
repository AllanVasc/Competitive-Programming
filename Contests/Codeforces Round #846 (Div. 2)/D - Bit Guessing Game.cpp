#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int ask(int x){
    cout << "- " << x << endl;
    int ans;
    cin >> ans;
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int start;
        cin >> start;
        int answ = 0;
        int bit = 0;
        int last_answ = start;
        while(start){
            int sub = (1 << bit);
            int res = ask(sub);
            if(res < last_answ){
                answ += (1 << bit);
                bit++;
            }
            else{
                int reallyBit = bit + (res - last_answ + 1);
                answ += (1 << reallyBit);
                bit = bit + (res - last_answ + 1) + 1;
            }
            last_answ = res;
            start--;
        }
        cout << "! " << answ << endl;
    }
    return 0;
}