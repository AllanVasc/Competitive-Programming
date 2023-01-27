// 
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

    int n;
    cin >> n;

    int qtdodd = 0;
    int qtddeven = 0;
    for(int i = 0; i < n; i++){
        int aux;
        cin >> aux;
        if(aux%2 == 0) qtddeven++;
        else qtdodd++;
    }

    if(abs(qtddeven-qtdodd) <= 1) cout << "Good" << '\n';
    else cout << "Not Good" << '\n';

    return 0;
}
