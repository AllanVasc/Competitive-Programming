// 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

// Implementation of Z-function algorithm
class ZFunction{
private:
    int n;
    vector<int> z;
    int patternSize = -1;
    vector<int> freq;

public:
    ZFunction(string str, string pattern = ""){ // Initializing
        if(!pattern.empty()){
            str = pattern + "$" + str;
            this->patternSize = pattern.size();
        }
        this->n = str.size();
        z.assign(n, 0);
        // z[0] = 1;
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

    vector<int> findPattern(){
        vector<int> answ;
        for(int i = 0; i < n; i++){
            if(z[i] == patternSize) answ.push_back(i - patternSize - 1);
        }
        return answ;
    }

    void solve(string &s){
        vector<ii> answ;

        // cout << "z[i] = ";
        // for(int i = 0; i < n ; i ++){
        //     cout << z[i] << " ";
        // }
        // cout << '\n';

        freq.assign(n + 5, 0);
        for(int i = 0; i < n; i++){
            if(z[i]) freq[z[i]]++;
        }

        // cout << "freq = ";
        // for(int i = 0; i < n; i++){
        //     cout << freq[i] << " ";
        // }
        // cout << '\n';

        vector<int> prefixsum(n + 5, 0);
        prefixsum[n] = freq[n];
        for(int i = n-1; i >= 0; i--){
            prefixsum[i] = prefixsum[i+1] + freq[i];
        }
        // cout << "PS = ";
        // for(int i = 0; i <= n; i++){
        //     cout << prefixsum[i] << " ";
        // }
        // cout << '\n';

        for(int i = 0; i < n; i++){
            if(z[i] == n - i){ // é sufixo 
                answ.push_back({z[i], prefixsum[z[i]]});
            }
        }
        answ.push_back({n,0});
        sort(answ.begin(), answ.end());
        cout << answ.size() << '\n';
        for(int i = 0; i < answ.size(); i++){
            cout << answ[i].first << " " << answ[i].second + 1 << '\n';
        }
    }
};

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;

    ZFunction z_function(s);
    
    z_function.solve(s);

    return 0;
}
