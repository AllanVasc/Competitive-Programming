// A - Deletions of Two Adjacent Letters
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

        string s;
        string letra;

        cin >> s >> letra;
        bool answ = 0;
        for(int i = 0; i < s.size(); i+=2){
            if(s[i] == letra[0]){
                answ = true;
                break;
            }
        }

        if(answ) cout << "YES\n";
        else cout << "NO\n";
 
    }
 
    return 0;
}