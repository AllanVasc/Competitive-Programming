#include<bits/stdc++.h>

using namespace std;
#define int long long 

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, b;
    cin >> n >> b;
    vector<tuple<int,int,int,int>> people;
    for(int i = 0; i < n; i++){
        int x, y, t, v;
        cin >> x >> y >> t >> v;
        people.emplace_back(v, x, y, t);
    }
    vector<int> vaoPagar;
    int cnt = 0; // pessoas que vao estar dispostas a pagar a passagem
    for(int i = 0; i < n; i++){
        auto [multa, x, y, time] = people[i];
        if(abs(x - y) <= time) continue;
        if(y < x) continue; // to assumindo que existe
        int timeInTrain = (y + b - 1) / b;
        if(timeInTrain <= time){
            cnt++;
            vaoPagar.push_back(multa);
        }
    }
    sort(vaoPagar.begin(), vaoPagar.end());
    int mx = 0;
    int price = 0;
    for(auto curr : vaoPagar){
        int naoPagam = lower_bound(vaoPagar.begin(), vaoPagar.end(), curr) - vaoPagar.begin();
        int total = (cnt - naoPagam) * curr;
        if(total > mx){
            mx = max(total, mx);
            price = curr;
        }
    }

    cout << price << '\n';
    return 0;
}
