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
        int n, a, b;
        cin >> n >> a >> b;

        vector<bool> used(n + 5, false);
        vector<int> answ;
        answ.push_back(a);
        used[a] = true;
        int curr = b + 1;
        while(answ.size() < n/2 && curr <= n){
            if(used[curr] == false){
                answ.push_back(curr);
                used[curr] = true;
            }
            curr++;
        }
        curr = a + 1;
        while(answ.size() < n/2 && curr <= n){
            if(used[curr] == false){
                answ.push_back(curr);
                used[curr] = true;
            }
            curr++;
        }

        if(used[b] == true){
            cout << -1 << '\n';
        }
        else{
            answ.push_back(b);
            used[b] = true;
            curr = a - 1;
            while(answ.size() < n && curr >= 1){
                if(used[curr] == false){
                    answ.push_back(curr);
                    used[curr] = true;
                }
                curr--;
            }
            curr = b - 1;
            while(answ.size() < n && curr >= 1){
                if(used[curr] == false){
                    answ.push_back(curr);
                    used[curr] = true;
                }
                curr--;
            }

            bool has_answ = true;
            if(answ.size() != n) has_answ = false;
            else{
                for(int i = 0; i < n/2; i++){
                    if(answ[i] < a) has_answ = false;
                }
                for(int j = n/2; j < n; j++){
                    if(answ[j] > b) has_answ = false;
                }
            }

            if(!has_answ) cout << -1 << '\n';
            else{
                for(int i = 0; i < n; i++){
                    cout << answ[i] << " ";
                }
                cout << '\n';
            }
        }
    }
    
 
    return 0;
}