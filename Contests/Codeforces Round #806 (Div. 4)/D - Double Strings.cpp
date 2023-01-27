// D - Double Strings
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;
 
int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
 
    while(t--){
        int n;
        cin >> n;
 
        vector<string> v;
        map<string,int> freq;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            v.push_back(s);
            freq[s]++;
        }
 
        for(int i = 0; i < n; i++){
            bool answ = false;
            for(int j = 0; j < v[i].size() && !answ; j++){
                string s1 = v[i].substr(0,j+1);
                string s2 = v[i].substr(j+1, v[i].size()-(j+1));
                if(freq[s1] != 0 && freq[s2] != 0) answ = true;
            }
            if(answ) cout << 1;
            else cout << 0;
        }
        cout << '\n';
 
    }
 
    return 0;
}