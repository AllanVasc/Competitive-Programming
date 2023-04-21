#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<int> alpha = {0, 1, 2, 3, 5, 6, 7, 8, 9};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;

        vector<int> answ(4000, 0);
        answ[0] = 0;
        answ[0] += k;
        int carry = 0;
        for(int i = 0; i < answ.size(); i++){
            answ[i] += carry;
            carry = answ[i] / 9;
            answ[i] %= 9;
        }
        
        int found = false;
        for(int i = answ.size() - 1; i >= 0; i--){
            if(answ[i] != 0) found = true;
            if(found) cout << alpha[answ[i]];
        }
        cout << '\n';
    }
    return 0;
}