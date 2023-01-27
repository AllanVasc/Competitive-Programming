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
  
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    multiset<int> prices;
    vector<int> customer(m);
    for(int i = 0; i < n; i++){
        int aux;
        cin >> aux;
        prices.insert(aux);
    }

    for(int i = 0; i < m; i++) cin >> customer[i];

    for(int i = 0; i < m; i++){
        auto itr = prices.lower_bound(customer[i]);
        // cout << "itr = " << *itr << '\n';
        
        if(itr == prices.end()){
            if(prices.size() == 0){
                cout << -1 << '\n';
            }
            else{
                itr--;
                cout << *itr << '\n';
                prices.erase(itr);
            }
        }
        else if(*itr > customer[i]){
            if(itr == prices.begin()){
                cout << -1 << '\n';
            }
            else{
                itr--;
                cout << *itr << '\n';
                prices.erase(itr);
            }
        }
        else{
            cout << *itr << '\n';
            prices.erase(itr);
        }
    }

    return 0;
}