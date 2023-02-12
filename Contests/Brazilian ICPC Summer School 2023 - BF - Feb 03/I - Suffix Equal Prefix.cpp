#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

// Implementation of Z-function algorithm
class ZFunction{
private:
    int n;
    vector<int> z;
    int patternSize = -1;

public:
    ZFunction(string str, string pattern = ""){ // Initializing
        if(!pattern.empty()){
            str = pattern + "$" + str;
            this->patternSize = pattern.size();
        }
        this->n = str.size();
        z.assign(n, 0);

        int l = 0, r = 0;
        for(int i = 1; i < n; i++){ // Z-function
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

    int solve(){
        int answ = 0;
        for(int i = 0; i < z.size(); i++){
            if(z[i] == z.size() - i) answ++;
        }
        return answ;
    }

    vector<int> findPattern(){
        vector<int> answ;
        for(int i = 0; i < n; i++){
            if(z[i] == patternSize) answ.push_back(i - patternSize - 1);
        }
        return answ;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        string s;
        cin >> s;
        ZFunction zzao(s);

        cout << "Case " << cs << ": " << zzao.solve() << '\n';
    }
    return 0;
}