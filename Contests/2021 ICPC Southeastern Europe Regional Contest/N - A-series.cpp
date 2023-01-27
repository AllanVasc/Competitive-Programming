#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int32_t main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    n++;
 
    vector<int> have;
    vector<int> need;
    vector<int> really;
 
    have.assign(n,0);
    need.assign(n,0);
    really.assign(n,0);
 
    for(int i = 0; i < n; i++){
        cin >> have[i];
    }
    for(int i = 0; i < n; i++){
        cin >> need[i];
    }
    
    int cut = 0;
    int prev = 0;
 
    for(int i = n-1; i >= 0; i--){
        int curr = prev + need[i] - have[i];
        if(curr > 0){
            cut += (curr+2-1)/2;
            prev = (curr+2-1)/2;
            really[i] = curr;
        }
        else{
            prev = 0;
            really[i] = curr;
        }
    }
 
    // for(int i = 0; i < n; i++) cout << really[i] << " ";
    // cout << '\n';
 
    if(really[0] > 0) cout << -1 << '\n';
    else cout << cut << '\n';
 
    return 0;
}