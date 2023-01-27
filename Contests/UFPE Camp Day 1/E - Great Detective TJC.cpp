// 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<int> v;
        for(int i = 0; i < n; i++){
            int aux;
            cin >> aux;
            v.push_back(aux);
        }
        sort(v.begin(), v.end());

        bool answ = false;
        for(int i = 0; i < n-1; i++){
            if((v[i] ^ v[i+1]) == 1) answ = true;
            // cout << (v[i] ^ v[i+1]) << '\n';
        }

        if(answ) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }

    return 0;
}
