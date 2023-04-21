#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n, d;
        cin >> n >> d;
        string number;
        cin >> number;

        int pos = n - 1;
        for(int i = n - 1; i >= 0; i--){
            if(d > number[i] - '0') pos = min(pos, i);
        }
        string answ;
        for(int i = 0; i < n; i++){
            if(i == pos){
                if(d > number[i] - '0'){
                    answ.push_back(d + '0');
                    answ.push_back(number[i]);
                }
                else{
                    answ.push_back(number[i]);
                    answ.push_back(d + '0');
                }
            }
            else answ.push_back(number[i]);
        }

        cout << answ << '\n';
    }
    return 0;
}