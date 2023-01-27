// C - Odd/Even Increments
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int t;
    cin >> t;
 
    while(t--){
 
        int n;
        vector<int> v;
 
        cin >> n;
 
        for(int i = 0; i < n; i++){
            int aux;
            cin >> aux;
            v.push_back(aux);
        }
 
        bool parity = v[0]%2;
        bool answ = true;
 
        for(int i = 0; i < n; i+=2){
            if(v[i]%2 != parity){
                answ = false;
                break;
            }
        }
 
        parity = v[1]%2;
        for(int i = 1; i < n; i+=2){
            if(v[i]%2 != parity){
                answ = false;
                break;
            }
        }
 
        if(answ) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
 
    return 0;
}