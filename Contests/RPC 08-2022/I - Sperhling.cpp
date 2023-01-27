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

    string s1,s2;
    cin >> s1 >> s2;

    int idx = 0;

    while(idx < s1.size() || idx < s2.size()){
        if(s1[idx] != s2[idx]) break;
        idx++;
    }

    int answ = s1.size() - idx;
    answ += s2.size() - idx;

    cout << answ << '\n';

    return 0;
}