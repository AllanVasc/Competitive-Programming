#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

// Implementation of Knuth-Morris-Pratt algorithm
template<typename T>
struct KMP{
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

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        string s, t;
        cin >> s >> t;

        KMP<string> kmp(t);

        vector<int> answ = kmp.findPattern(s);

        if(answ.size() == 0) cout << "Not Found" << '\n';
        else{
            cout << answ.size() << '\n';
            for(int i = 0; i < answ.size(); i++){
                cout << answ[i] + 1 << " ";
            }
            cout << '\n';
        }

        cout << '\n';
    }

    return 0;
}