#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        pq.push({v[i], i});
    }
    vector<int> answ(n, -1);
    while(!pq.empty()){
        auto [val, idx] = pq.top();
        pq.pop();
        if(answ[idx] == -1){
            answ[idx] = val;
        }
        if(idx < n){    // idx + 1
            if(answ[idx + 1] < answ[idx] - m){
                answ[idx + 1] = max(0LL, answ[idx] - m);
                answ[idx + 1] = max(answ[idx + 1], v[idx + 1]);
                pq.push({answ[idx + 1], idx + 1});
            }
        }
        if(idx > 0){
            if(answ[idx - 1] < answ[idx] - m){
                answ[idx - 1] = max(0LL, answ[idx] - m);
                answ[idx - 1] = max(answ[idx - 1], v[idx - 1]);
                pq.push({answ[idx - 1], idx - 1});
            }
        }
    }
    for(auto x : answ){
        cout << x << " ";
    }
    cout << '\n';
    return 0;
}