// D - Not a Cheap String
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;
 
const int MAXN = 200000 + 100;
 
int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int t;
    cin >> t;
 
    while(t--){
        string s;
        cin >> s;
        int p;
        cin >> p;
 
        vector<vector<int>> v;
        v.assign(27,vector<int>());
        int total_cost = 0;
        for(int i = 0; i < s.size(); i++){
            v[s[i]-'a'].push_back(i);
            total_cost += s[i] - 'a' + 1;
        }
 
        vector<bool> mantem(s.size()+1, true);
 
        for(int i = 25; i >= 0 && total_cost > p; i--){
            for(int j = 0; j < v[i].size() && total_cost > p; j++){
                mantem[v[i][j]] = false;
                total_cost -= i+1;
            }
        }
 
        string answ;
        for(int i = 0; i < s.size(); i++){
            if(mantem[i]) answ.push_back(s[i]);
        }
 
        cout << answ << '\n';
 
    }
    return 0;
}