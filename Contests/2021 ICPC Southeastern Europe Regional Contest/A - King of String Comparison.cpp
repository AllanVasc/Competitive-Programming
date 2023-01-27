// 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int INF = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    string s1,s2;
    cin >> s1 >> s2;

    int last = -1;
    bool less = false;
    int answ = 0;
    for(int i = n-1; i >= 0; i --){
        if(s1[i] < s2[i]){
            less = true;
            last = i;
            answ += n - last;
        }
        else if(s1[i] > s2[i]){
            less = false;
            last = i;
        }
        else{ // equal
            if(less)
                answ += n - last;
        }
    }

    cout << answ << '\n';
    return 0;
}
