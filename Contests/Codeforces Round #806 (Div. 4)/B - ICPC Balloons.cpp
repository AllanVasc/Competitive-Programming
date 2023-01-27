// B - ICPC Balloons
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
        map<char,int> already;
        int n;
        cin >> n;
        string s;
        cin >> s;
        int answ = 0;
        for(int i = 0; i < s.size(); i++){
            if(already[s[i]] == 0){
                already[s[i]] = 1;
                answ += 2;
            }
            else answ += 1;
        }
        cout << answ << '\n';
    }
 
    return 0;
}