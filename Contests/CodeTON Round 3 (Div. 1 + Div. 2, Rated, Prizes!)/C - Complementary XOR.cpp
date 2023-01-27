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
    
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        string a,b;
        cin >> a >> b;

        int qtd_zero = 0;
        vector<ii> answ;
        for(int i = 0; i < n; i++){
            if(a[i] == '0'){
                qtd_zero++;
                answ.push_back({i+1, i+1});
            }
        }

        int qtd_one = 0;
        for(int i = 0; i < n; i++){
            if(a[i] == '0'){
                if(qtd_zero % 2 == 0){
                    b[i] = 1 - (b[i] - '0') + '0';
                }
            }
            else{
                if(qtd_zero % 2 == 1){
                    b[i] = 1 - (b[i] - '0') + '0';
                }
            }
            if(b[i] == '1') qtd_one++;
        }

        if(qtd_one != 0 && qtd_one != n){
            cout << "NO" << '\n';
        }
        else{
            if(qtd_one == n){
                answ.push_back({1,1});
                answ.push_back({2,n});
            }
            else{
                answ.push_back({1,n});
            }            

            cout << "YES" << '\n';
            cout << answ.size() << '\n';
            for(auto i : answ){
                cout << i.first << " " << i.second << '\n';
            }
        }
        
    }

    return 0;
}