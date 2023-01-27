// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
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

        vector<int> d;
        d.assign(n, 0);
        for(int i = 0; i < n; i++) cin >> d[i];

        vector<int> answ;
        answ.assign(n, 0);
        answ[0] = d[0];

        bool check = true;
        for(int i = 1; i < n; i++){
            
            int op1 = d[i] + answ[i-1];
            int op2 = -(d[i] - answ[i-1]);

            if(op1 >= 0 && op2 >= 0 && op1 != op2){
                check = false;
            }

            if(op1 < 0) swap(op1, op2);

            answ[i] = op1;
        }

        if(check){
            for(int i = 0; i < n; i++){
                cout << answ[i] << " ";
            }
            cout << '\n';
        }
        else{
            cout << -1 << '\n';
        }
    }
    return 0;
}