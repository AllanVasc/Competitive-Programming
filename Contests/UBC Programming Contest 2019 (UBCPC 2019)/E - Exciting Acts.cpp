#include <bits/stdc++.h>
using namespace std;
 
int32_t main(){
 
    int n, k;
    cin >> n >> k;
    
    vector<int> v;
    for(int i = 0; i < n; i++){
        int aux;
        cin >> aux;
        v.push_back(aux);
    }
 
    sort(v.begin(), v.end());
 
    int answ = 0;
    for(int i = 0; i < k; i++){
        answ += v[v.size()-1 - i];
    }
    
    cout << answ << '\n';
 
    return 0;
}