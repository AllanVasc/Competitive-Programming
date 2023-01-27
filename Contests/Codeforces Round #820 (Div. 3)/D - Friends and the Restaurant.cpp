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

        int n;
        cin >> n;

        vector<int> x(n, 0);
        vector<int> y(n, 0);

        for(int i = 0; i < n; i++){
            cin >> x[i];
        }
        for(int i = 0; i < n; i++){
            cin >> y[i];
        }

        vector<int> contr(n,0);
        for(int i = 0; i < n; i++){
            contr[i] = y[i] - x[i];
            //cout << contr[i] << " ";
        }
        //cout << '\n';

        sort(contr.begin(), contr.end());

        int answ = 0;
        for(int l = 0, r = n-1; l < r;){
            // cout << "olhando: " << l << " " << r;
            if(contr[r] + contr[l] >= 0){
                answ++;
                l++;
                r--;
            }
            else{
                l++;
            }
        }

        cout << answ << '\n';
    }
    return 0;
}