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
        string s1, s2;
        cin >> s1 >> s2;

        int n = s1.size(), m = s2.size();
        if(s1[0] == s2[0]){
            cout << "YES" << "\n";
            cout << s1[0] << '*' << '\n';
        }
        else if(s1[n - 1] == s2[m - 1]){
            cout << "YES" << '\n';
            cout << '*' << s1[n - 1] << '\n';
        }
        else{
            string answ = "";
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(s1[i] == s2[j] && s1[i + 1] == s2[j + 1]){
                        answ.push_back(s1[i]);
                        answ.push_back(s1[i + 1]);
                        break;
                    }
                }
                if(answ.size() > 0) break;
            }

            if(answ.size() == 0) cout << "NO" << "\n";
            else{
                cout << "YES" << '\n';
                cout << "*" + answ + "*" << '\n';
            }
        }
    }
    return 0;
}