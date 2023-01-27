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

    int step = 25;

    int a = 1, b = 2;
    int dist1 = 0, dist2 = 0;
    
    while(step--){
        
        cout << "? " << a << " " << b << endl;

        cin >> dist1;

        if(dist1 == -1){
            cout << "! " << b-1 << endl;
            return 0;
        }

        cout << "? " << b << " " << a << endl;

        cin >> dist2;

        if(dist1 != dist2){
            cout << "! " << dist1 + dist2 << endl;
            return 0;
        }
        else{
            b++;
        }
    }

    return 0;
}