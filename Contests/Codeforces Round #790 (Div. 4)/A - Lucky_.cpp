// A - Lucky?
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
 
       string s;
       cin >> s;

       ll sumA = 0;
       ll sumB = 0;
       for(int i = 0; i < 3; i++){
           sumA += s[i]-'0';
       }
       for(int i = 3; i < 6; i++){
           sumB += s[i] -'0';
       }

       if(sumA == sumB){
           cout << "YES" << '\n';
       }
       else cout << "NO" << '\n';
    }
 
    return 0;
}
