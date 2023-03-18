#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int sumDigits(int n){
    int answ = 0;
    while(n){
        answ += n % 10;
        n /= 10;
    }
    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string check = to_string(n);
        string x(check.size(), '0'), y(check.size(), '0');
        
        bool flag = true;
        for(int i = 0; i < check.size(); i++){
            int val = check[i] - '0';
            if(val % 2 == 0){
                x[i] = val / 2 + '0';
                y[i] = val / 2 + '0';
            }
            else{
                x[i] = val/2 + '0' + (flag == true);
                y[i] = val/2 + '0' + (flag != true);
                flag = !flag;
            }
        }

        cout << stoi(x) << " " << stoi(y) << '\n';
    }
    return 0;
}