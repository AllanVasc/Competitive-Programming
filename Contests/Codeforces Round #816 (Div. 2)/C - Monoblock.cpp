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

    int n, q;
    cin >> n >> q;

    vector<int> v;
    v.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> v[i];

    // awesomeness = joint's + 1
    int answ = 0;
    for(int i = 0; i < n-1; i++){
        if(v[i] != v[i+1]){ // couting how many subarray "pick" this joint
            answ += (i+1)*(n-(i+1));
        }
    }

    answ += n*(n+1)/2; // contribution by "+1" of awesomeness

    while(q--){
        int i,x;
        cin >> i >> x;
        i--;
        
        // If exist's joints i will remove
        if(i+1 <= n-1 && v[i] != v[i+1]){
            answ -= (i+1)*(n-(i+1));
        }
        if(i-1 >= 0 && v[i] != v[i-1]){
            answ -= (i-1+1)*(n-(i-1+1));
        }

        v[i] = x;
        
        // Check if I have new barricades
        if(i+1 <= n-1 && v[i] != v[i+1]){
            answ += (i+1)*(n-(i+1));
        }
        if(i-1 >= 0 && v[i] != v[i-1]){
            answ += (i-1+1)*(n-(i-1+1));
        }

        cout << answ << '\n';
    }

    return 0;
}