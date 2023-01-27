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
    map<int,int> freq;

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

        for(int i = 0; i < n; i++){
            freq[z[i]]++;
        }
    }

    vector<int> findPattern(){
        vector<int> answ;
        for(int i = 0; i < n; i++){
            if(z[i] == patternSize) answ.push_back(i - patternSize - 1);
        }
        return answ;
    }

    string solve(string &s){
        string answ;
        int maxz = 0;

        for(int i = 0; i < n; i++){
            if(z[i] == n - i){ // é sufixo

                if(maxz >= z[i]){
                    for(int j = answ.size(); j < z[i]; j++){
                        answ += s[j];
                    }
                    break;
                }

                // cout << "achei = " << answ << '\n';
            }
            
            if(z[i] > maxz) maxz = z[i];
        }

        return answ;
    }
};

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;

    ZFunction z_function(s);

    string answ = z_function.solve(s);

    if(answ.empty()){
        cout << "Just a legend" << '\n';
    }
    else 
        cout << answ << '\n';

    return 0;
}
