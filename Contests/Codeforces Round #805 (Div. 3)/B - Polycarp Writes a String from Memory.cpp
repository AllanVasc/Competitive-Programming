// B - Polycarp Writes a String from Memory
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
 
        set<char> conj;
        int answ = 1;
 
        for(int i = 0; i < s.size(); i++){
            if(conj.size() == 3 && conj.find(s[i]) == conj.end()){
                answ++;
                conj.clear();
                conj.insert(s[i]);
            }
            else
                conj.insert(s[i]);
        }
 
        cout << answ << '\n';
    }
    return 0;
}