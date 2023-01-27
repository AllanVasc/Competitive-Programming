//  N - Majority
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
    
        int v;
        cin >> v;
 
        map<int,int> freq;
        for(int i = 0; i < v; i ++){
            int aux;
            cin >> aux;
            freq[aux]++;
        }
 
        int max = -1;
        int answ = -1;
        for(auto i: freq){
            // cout << i.first << " " << i.second << '\n';
            if(max == i.second){
                if(i.first < answ){
                    answ = i.first;
                }
            }
            else if(max < i.second){
                answ = i.first;
                max = i.second;
            }
        }
        cout << answ << '\n';
 
    }
    return 0;
}