#include <bits/stdc++.h>

using namespace std;
#define int long long

const int INF = LONG_LONG_MAX;

class ZFunction{
private:
    int n;
    vector<int> z;
    int patternSize = -1;

public:
    ZFunction(vector<int> str, int len){ // Initializing
        this->n = str.size();
        z.assign(n, 0);
        patternSize = len;

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
        // cout << "z = ";
        // for(auto x : z) cout << x << " ";
        // cout << '\n';
    }

    vector<int> findPattern(){
        vector<int> answ;
        for(int i = 0; i < n; i++){
            if(z[i] == patternSize) answ.push_back(i - patternSize - 1);
        }
        return answ;
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, n;
    cin >> m >> n;
    vector<int> v1(m), v2(n);
    for(int i = 0; i < m; i++){
        cin >> v1[i];
    }
    for(int i = 0; i < n; i++){
        cin >> v2[i];
    }

    if(n < m){
        cout << 0 << '\n';
    }
    else if(m == 1){
        cout << n << '\n';
    }
    else{
        vector<int> text;
        for(int i = 1; i < m; i++){
            text.push_back(v1[i] - v1[i - 1]);
        }
        text.push_back(-INF);
        for(int i = 1; i < n; i++){
            text.push_back(v2[i] - v2[i - 1]);
        }
        // cout << "TEXT: " ;
        // for(auto x : text) cout << x << " ";
        // cout << '\n';
        ZFunction z(text, m - 1);
        cout << z.findPattern().size() << '\n';
    }
    return 0;
}