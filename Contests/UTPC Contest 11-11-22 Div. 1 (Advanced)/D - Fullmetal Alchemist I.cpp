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
            if(i <= r) z[i] = min(r - i + 1, z[i - l]);
            while(i + z[i] < n && str[z[i]] == str[i + z[i]]) z[i]++;
            if(i + z[i] - 1 > r){
                l = i;
                r = i + z[i] - 1;
            }
        }
    }

    int solve(){
        int answ = 0;
        for(int i = patternSize; i < n; i++){
            answ = max(answ, z[i]);
        }
        return answ;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    if(n == 1){
        string aux;
        cin >> aux;
        cout << aux.size() << '\n';
    }
    else{
        string s1, s2;
        cin >> s1 >> s2;
        ZFunction z(s1, s2);

        int answ1 = s1.size() + s2.size() - z.solve();
        ZFunction z2(s2, s1);
        int answ2 = s1.size() + s2.size() - z2.solve();

        cout << min(answ1, answ2) << '\n';
    }
    return 0;
}