// C - Cypher
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
 
        for(int i = 0; i < n; i++){
            int qtd;
            cin >> qtd;
            string s;
            cin >> s;
            for(int j = 0; j < qtd; j++){
                if(s[j] == 'D'){
                    if(v[i] == 9){
                        v[i] = 0;
                    }
                    else{
                        v[i]++;
                    }
                }
                else if(s[j] == 'U'){
                    if(v[i] == 0){
                        v[i] = 9;
                    }
                    else{
                        v[i]--;
                    }
                }
            }
            cout << v[i] << " ";
        }
        cout << '\n';
 
    }
 
    return 0;
}