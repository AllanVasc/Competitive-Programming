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

    int n, k;
    cin >> n >> k;

    map<int,int> freq;
    for(int i = 0; i < n; i++){
        int number, qtd;
        cin >> number >> qtd;
        freq[number] += qtd;
    }

    int cnt = 0;
    for(auto i : freq){
        cnt += i.second;
        if(cnt >= k){
            cout << i.first << '\n';
            break;
        }
    }
    
    return 0;
}