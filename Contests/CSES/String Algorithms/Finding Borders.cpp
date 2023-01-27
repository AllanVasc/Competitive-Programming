#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

class ZFunction{
    int n;
    vector<int> z;
    int patternSize = -1;

public:
    ZFunction(string str, string pattern = ""){
        if(!pattern.empty()){
            str = pattern + "$" + str;
            this->patternSize = pattern.size();
        }
        this->n = str.size();
        z.assign(n, 0);

        int l = 0, r = 0;
        for(int i = 1; i < n; i++){
            if(i <= r){
                z[i] = min(r - i + 1, z[i - l]);
            }
            while(i + z[i] < n && str[z[i]] == str[i + z[i]]) z[i]++;
            if(i + z[i] - 1 > r){
                l = i;
                r = i + z[i] - 1;
            }
        }
    }

    vector<int> solve(){
        vector<int> answ;

        for(int i = z.size() - 1; i > 0; i--){
            if(z[i] == z.size() - i) answ.push_back(z[i]);
        }

        return answ;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    string s;
    cin >> s;

    ZFunction solver(s);

    vector<int> answ = solver.solve();
    for(int i = 0; i < answ.size(); i++){
        cout << answ[i] << " ";
    }
    cout << '\n';
    return 0;
}