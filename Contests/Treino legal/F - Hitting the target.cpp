//  F - Hitting the target
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
 
    int r;
    cin >> r;
 
    vector<ii> arrow;
    vector<bool> check;
    check.assign(3,0);
 
    for(int i = 0; i < 3; i++){
        ii aux;
        cin >> aux.first >> aux.second;
        arrow.push_back(aux);
    }
 
    int answ = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 3; j++){
            if(!check[j] && distance(arrow[j].first,arrow[j].second) <= (i+1)*r){
                answ += 10 - i;
                check[j] = true;
            }
        }
    }
    
    cout << answ << '\n';
 
    return 0;
}
