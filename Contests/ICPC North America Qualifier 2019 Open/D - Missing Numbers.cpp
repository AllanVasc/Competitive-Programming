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
    bool answ = 1;
    for(int i = 1; i < 200; i++){
        int aux;
        cin >> aux;
        while(i < aux){
            cout << i << '\n';
            i++;
            answ = false;
        }
    }
    if(answ) cout << "good job" << '\n';
    return 0;
}
