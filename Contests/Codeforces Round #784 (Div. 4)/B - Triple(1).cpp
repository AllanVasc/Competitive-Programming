// B - Triple
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
 
int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    ll t;
 
    cin >> t;
 
    while(t--){
 
        int n;
        map<int,int> f;
        bool check = false;
 
        cin >> n;
 
        for(int i = 0; i < n; i++){
            int aux;
            cin >> aux;
            f[aux]++;
        }
        map<int,int>::iterator itr = f.begin();
 
        while(itr != f.end()){
            if(itr->second >= 3){
                cout << itr->first << '\n';
                check = true;
                break;
            }
            itr++;
        }
 
        if(check == false){
            cout << "-1" << '\n';
        }
    }
 
    return 0;
}