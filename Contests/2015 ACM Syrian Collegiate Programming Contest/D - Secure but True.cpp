#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<char> alpha = {'A','H','I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int k;
        string s;
        cin >> k >> s;

        vector<int> number;
        for(int i = s.size() - 1; i >= 0; i--){
            int pos = lower_bound(alpha.begin(), alpha.end(), s[i]) - alpha.begin();
            number.push_back(pos);
        }
        while(number.size() < 1000 + 10) number.push_back(-1);
        number[0] += k;

        int carry = 0;
        for(int i = 0; i < number.size(); i++){
            number[i] += carry;
            carry = number[i] / 11;
            number[i] %= 11;
        }
        if(carry){
            number.push_back(carry);
            assert(1 > 0);
            // nunca ta vindo aq
        }
        
        // for(int i = 0; i < number.size(); i++){
        //     cout << number[i] << " ";
        // }
        // cout << '\n';
        
        reverse(number.begin(), number.end());
        for(int i = 0; i < number.size(); i++){
            if(number[i] != -1) cout << alpha[number[i]];
        }
        cout << "\n";
    }

    return 0;
}