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
    
    int n, q;
    cin >> n >> q;

    vector<int> v;
    v.assign(n + 1, 0);
    for(int i = 0; i < n; i++) cin >> v[i+1];

    vector<int> prefix_xor;
    vector<int> prefix_sum;
    prefix_xor.assign(n+1, 0);
    prefix_sum.assign(n+1, 0);
    for(int i = 0; i < n; i++){
        prefix_xor[i+1] = prefix_xor[i] ^ v[i+1];
        prefix_sum[i+1] = prefix_sum[i] + v[i+1];
    }

    map<int, vector<int>> mp[2];
    for(int i = 1; i <= n; i ++){
        if(i%2 == 0){
            mp[0][prefix_xor[i]].push_back(i);
        }
        else{
            mp[1][prefix_xor[i]].push_back(i);
        }
    }

    while(q--){
        int l, r;
        cin >> l >> r;

        if( (r - l + 1) % 2 == 1){ 

            if((prefix_xor[r] ^ prefix_xor[l-1]) == 0){
                if((prefix_sum[r] - prefix_sum[l-1]) == 0){
                    cout << 0 << '\n';
                }
                else{
                    cout << 1 << '\n';
                }
            }
            else{
                cout << -1 << '\n';
            }
        }
        else{ // qtd par de numeros
        
            if((prefix_xor[r] ^ prefix_xor[l-1]) == 0){
                
                // cout << "r = " << r << '\n';
                // cout << "l = " << l << '\n';

                int half = (l + r)/2;

                if((prefix_sum[r] - prefix_sum[l-1]) == 0){
                    cout << 0 << '\n';
                }
                else if(v[l] == 0 || v[r] == 0){
                    cout << 1 << '\n';
                }
                else{

                    if(l%2 == 0){
                        auto itr = lower_bound(mp[0][prefix_xor[l - 1]].begin(), mp[0][prefix_xor[l - 1]].end(), l);

                        int answ = -1;
                        if(itr != mp[0][prefix_xor[l - 1]].end()){
                            if(*itr < r && *itr > l) answ = 2;
                        }

                        cout << answ << '\n';
                    }
                    else{
                        auto itr = lower_bound(mp[1][prefix_xor[l - 1]].begin(), mp[1][prefix_xor[l - 1]].end(), l);

                        int answ = -1;
                        if(itr != mp[1][prefix_xor[l - 1]].end()){
                            if(*itr < r && *itr > l) answ = 2;
                        }

                        cout << answ << '\n';
                    }

                }
            }
            else{
                cout << -1 << '\n';
            }
        }

    }
    
    return 0;
}