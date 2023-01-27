// F - Eating Candies
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
        vector<int> w;
 
        cin >> n;
        for(int i = 0; i < n; i++){
            int aux;
            cin >> aux;
            w.push_back(aux);
        }
 
        int ali = 0, bob = n-1;
        ll w_ali = 0, w_bob = 0;
        ll answ = 0;
        vector<bool> is_eaten(n,false);
        
        while(ali <= bob){
 
            for(;w_ali <= w_bob && ali <= bob; ali++){
                if(is_eaten[ali] == false){
                    w_ali += w[ali];
                    is_eaten[ali] = true;
                }
                else{
                    break;
                }
                if(w_ali == w_bob){
                    answ = (ali + 1) + (n - bob - 1);
                }
            }
 
            for(; w_bob <= w_ali && bob >= ali; bob--){
                if(is_eaten[bob] == false){
                    w_bob += w[bob];
                    is_eaten[bob] = true;
                }
                else{
                    break;
                }
                if(w_ali == w_bob){
                    answ = (ali + 1) + (n - bob - 1);
                }
            }
        }
 
        cout << answ << '\n';
    }
 
    return 0;
}