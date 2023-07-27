#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

// Implementation of Z-function algorithm
class ZFunction{
public:
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

    vector<int> findPattern(){
        vector<int> answ;
        for(int i = 0; i < n; i++){
            if(z[i] == patternSize) answ.push_back(i - patternSize - 1);
        }
        return answ;
    }
};

// Implementation of Knuth-Morris-Pratt algorithm
template<typename T>
struct KMP{
public:    
    T pattern;
    int m;
    vector<int> lps;

public:
    KMP(T pattern){
        m = pattern.size();
        this->pattern = pattern;
        get_lps();
    }

    vector<int> findPattern(T text){
        vector<int> matches;
        int n = text.size(), last = 0;
        for(int i = 0; i < n; i++){
            int j = last;
            while(j > 0 && (j >= m || text[i] != pattern[j]))
                j = lps[j - 1];
            
            last = (j < m && text[i] == pattern[j]) ? j + 1 : 0;
            if(last == m) matches.push_back(i - m + 1);
        }
        return matches;
    }

private:
    // Find Longest proper prefix which is also suffix
    void get_lps(){
        lps.assign(m, 0);
        for(int i = 1; i < m; i++){
            int j = lps[i - 1];
            while(j > 0 && pattern[i] != pattern[j])
                j = lps[j - 1];
            if(pattern[i] == pattern[j]) lps[i] = j + 1;
        }
    }
};

signed main() {
    optimize;
    string s;
    cin >> s;
    ZFunction z(s);
    KMP<string> kmp(s);
    for(auto x : z.z) cout << x << " ";
    cout << '\n';
    for(auto x : kmp.lps) cout << x << " ";
    cout << '\n';
    return 0;
}