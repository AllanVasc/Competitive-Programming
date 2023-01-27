#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<int> v;
    for(int i = 0; i < n-1; i++){
        int aux;
        cin >> aux;
        v.push_back(aux);
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < n-1; i++){
        if(v[i] != i + 1){
            cout << i + 1 << '\n';
            return 0;
        }
    }
    cout << n << '\n';
    
    return 0;
}