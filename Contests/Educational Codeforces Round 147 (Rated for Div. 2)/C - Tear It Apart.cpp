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

int32_t main() {
    // optimize;
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int answ = INF;
        for(char cur = 'a'; cur <= 'z'; cur++){
            vector<int> szs;
            int qtt = 0;
            for(int i = 0; i < n; i++){
                if(s[i] == cur){
                    szs.push_back(qtt);
                    qtt = 0;
                }
                else qtt++;
            }
            // cout << "sz: ";
            // for(auto x : szs) cout << x << " ";
            // cout << '\n';
            szs.push_back(qtt);
            int currAnsw = 0;
            for(int i = 0; i < szs.size(); i++){
                int aux = szs[i];
                int qtt = 0;
                while(aux){
                    qtt++;
                    aux /= 2;
                }
                currAnsw = max(currAnsw, qtt);
            }
            answ = min(answ, currAnsw);
        }
        cout << answ << '\n';
    }
    return 0;
}