#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<int> answ;

void solve(int n){

    for(int i = 1; i <= n; i++){
        int sum = i;
        for(int steps = 0; steps < 100000; steps++){
            int curr = sum;
            sum = 0;
            while(curr){
                sum += (curr % 10)*(curr % 10);
                curr /= 10;
            }
        }
        if(sum == 1){
            answ.push_back(i);
        }
    }
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;

    solve(n);
    // for(int i = 0; i < answ.size(); i++){
    //     cout << answ[i] << " ";
    // }
    // cout << '\n';
    cout << answ.size() << '\n';
    return 0;
}