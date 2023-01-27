// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;
const int MOD = 1e9 + 7;

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n,k,b,s;
        cin >> n >> k >> b >> s;

        int min_value = b*k;    //a_i

        bool answ = true;
        if(min_value > s){
            answ = false;
        }

        int max_value = min_value + k - 1;

        if(s - max_value - (n-1)*(k-1) > 0 ){
            answ = false;
        }

        if(answ == false){
            cout << -1 << '\n';
        }
        else{

            vector<int> v;
            v.assign(n, 0);
            v[0] = min(max_value,s);
            int falta_soma = s - v[0];

            for(int i = 1; i < n; i++){
                v[i] = min(k-1, falta_soma);
                falta_soma -= v[i];
                if(falta_soma == 0) break;
            }

            for(int i = 0; i < n; i++){
                cout << v[i] << " ";
            }
            cout << '\n';
        }
    }


    return 0;
}