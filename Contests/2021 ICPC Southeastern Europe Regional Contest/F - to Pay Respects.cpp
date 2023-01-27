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

    int n,x,r,p,k;
    cin >> n >> x >> r >> p >> k;

    string round;
    cin >> round;

    priority_queue<ii, vector<ii>> pq;
    for(int i = 0; i < n; i++){
        if(round[i] == '0'){
            pq.push( {(n-i)*p, i} );
        }
        else{
            pq.push( {(n-i)*(p+r), i});
        }
    }

    vector<int> cast(n,0);
    while(k--){
        cast[pq.top().second] = 1;
        pq.pop();
    }

    int answ = x*n;
    int stackp = 0;
    int stackr = 0;

    for(int i = 0; i < n; i++){

        if(round[i] == '1'){
            stackr++;
        }

        if(cast[i] == 1){
            stackp++;
            if(stackr) stackr--;
        }
        
        answ += stackp*p - stackr*r;
    }
    
    cout << answ << '\n';
    
    return 0;
}
