//  B - Building a Bianzhong
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;
 
long double distance(int x, int y){
    return sqrt((x-0)*(x-0) + (y-0)*(y-0));
}
 
int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
 
    if((((1+n)*n)/2)%2 != 0) cout << "-1" << '\n';
    else{
 
        if(n%2 == 0){
 
        for(int i = 0; i < n/2; i++){
            if(i%2 != 0) cout << '+';
            else cout << '-' ;
        }
 
        for(int i = 1; i <= n/2; i++){
            if(i%2 != 0) cout << '+';
            else cout << '-';
        }
        cout << '\n';
        }
        else{
            int i = 0;
            for(i = 0; i < n/2; i++){
                if(i%2 == 0) cout << "++";
                else cout << "--";
            }
 
            if(i%2 != 0) cout << "-\n";
            else cout << "+\n";
        }
    }
 
    return 0;
}
