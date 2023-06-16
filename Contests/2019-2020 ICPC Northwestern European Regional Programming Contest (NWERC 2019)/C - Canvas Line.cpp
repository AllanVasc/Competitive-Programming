#include <bits/stdc++.h>

using namespace std;
#define ii pair<int,int>


int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<ii> v(n);
    for(int i=0; i<n; i++) cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end());
    v.push_back({-1, -1});
    vector<int> need(n+1, 2);

    int p; cin >> p;
    vector<int> pin(p);
    for(int i=0; i<p; i++) cin >> pin[i];
    sort(pin.begin(), pin.end());

    for(int i=0; i<p; i++){
        for(int j=0; j<n; j++){
            auto [a, b] = v[j];
            if(pin[i] >= a && pin[i]<=b){
                need[j]--;
                if(need[j] < 0){
                    cout << "impossible\n";
                    return 0;
                }
            }
        }
    }
    vector<int> ans;
    for(int i=0; i<n; i++){
        if(need[i] == 0) continue;
        
        
        bool found = binary_search(pin.begin(), pin.end(), v[i].second);
        if(v[i+1].first == v[i].second && !found && need[i+1]){
            ans.push_back(v[i].second);
            need[i]--;
            need[i+1]--;
        }
        
        for(int j=1; j<=5 && need[i]; j++){
            bool f = binary_search(pin.begin(), pin.end(), v[i].first +j);
            if(!f){
                ans.push_back(v[i].first + j);
                need[i]--;
            }
        }
    }

    cout << ans.size() << '\n';
    for(auto x: ans) cout << x << " ";
    cout << '\n';
}