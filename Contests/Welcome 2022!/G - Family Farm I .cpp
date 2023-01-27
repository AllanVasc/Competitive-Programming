// G - Family Farm I 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    ll t;
 
    cin >> t;
    
    ll answ = 0;

    string prev;
    string next;

    cin >> prev;

    for(int i = 0; i < t-1; i++){

        cin >> next;

        if(prev.size() == next.size()){

            for(int i = 0; i < prev.size(); i++){
                if(prev[i] != next[i]){
                    answ++;
                }
            }

        }
        else{   

            answ++;
            int n = prev.size();

            for(int i = 0; i < n; i++){

                if(prev[i] != next[i] && prev[i] != next[n + i]){
                    if(next[i] == next[n + i]) answ++;
                    else answ += 2;
                }

                else if(prev[i] != next[i] || prev[i] != next[n+i]) answ++;
            }
            
        }

        prev = next;
    }

    cout << answ << '\n';
 
    return 0;
}
