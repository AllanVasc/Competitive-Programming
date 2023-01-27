// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string s;
        cin >> s;

        int answ = n, curr = 0, have = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                curr++;
                if(curr <= have) answ--;
                have = curr;
            }
            else{
                curr--;
            }
        }

        cout << answ << '\n';
        
    }
    return 0;
}