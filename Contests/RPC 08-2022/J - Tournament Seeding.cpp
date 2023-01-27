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

    int n, k;
    cin >> n >> k;

    int total = 1;
    for(int i = 0; i < n; i++){
        total = 2*total;
    }

    vector<int> v(total);
    for(int i = 0; i < total; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());

    int answ = 0;
    while(total){
        for(int i = total/2 - 1, j = total-1; i >= 0 && j >= total/2;){
            if(v[i] - v[j] <= k){
                // cout << "check em " << v[i] << " e " << v[j] << '\n';
                // cout << "irei somar " << j+1 - total/2 << '\n';
                answ++;
                i--;
                j--;
            }
            else{
                j--;
            }
        }
        total = total/2;
    }

    cout << answ << '\n';

    return 0;
}