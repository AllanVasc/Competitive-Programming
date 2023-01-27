// D - Colorful Stamp
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
        string s;
 
        cin >> n >> s;
 
        bool b = false;
        bool r = false;
        bool answ = true;
 
        for(int i = 0; i < n; i++){
            if(s[i] == 'B'){
                b = true;
            }
            else if(s[i] == 'R'){
                r = true;
            }
            else if(s[i] == 'W'){
 
                if(b != r){
                    answ = false;
                    break;
                }
                else{
                    b = false;
                    r = false;
                }
 
            }
        }
 
        if(b != r){
            answ = false;
        }
 
        if(answ) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
 
    return 0;
}