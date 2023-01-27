// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;
const int MOD = 1e9 + 7;

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        priority_queue<pair<int,int>> pq;

        int n = s.size();
        int min_cost = abs(s[0] - s[n-1]);
        
        vector<int> answ;

        vector<vector<int>> pos;
        pos.assign(26, vector<int>());
        for(int i = 0; i < n; i++){
            pos[s[i] - 'a'].push_back(i);
        }

        if(s[0] > s[n-1]){ // vou descendo 
            for(int i = s[0] - 'a'; i >= s[n-1] - 'a'; i--){
                for(int j = 0; j < pos[i].size(); j++){
                    answ.push_back(pos[i][j]);
                }
            }
        }
        else{
            for(int i = s[0] - 'a'; i <= s[n-1] - 'a'; i++){
                for(int j = 0; j < pos[i].size(); j++){
                    answ.push_back(pos[i][j]);
                }
            }
        }

        cout << min_cost << " " << answ.size() << '\n';;
        for(int i = 0; i < answ.size(); i++){
            cout << answ[i] + 1 << " ";
        }    
        cout << '\n';
    }
    return 0;
}