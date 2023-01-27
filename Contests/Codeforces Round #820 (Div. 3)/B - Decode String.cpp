// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;
const int MOD = 1e9 + 7;

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        string s;
        cin >> n >> s;

        string answ;

        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '0'){
                int value = 0;
                value = s[i-1] - '0' + 10*(s[i-2] - '0');
                answ += (char) (value + 'a' - 1);
                i -= 2;
            }
            else{
                answ += (char) (s[i] - '0' + 'a' - 1);
            }
        }

        reverse(answ.begin(), answ.end());

        cout << answ << '\n';
        
    }
    return 0;
}