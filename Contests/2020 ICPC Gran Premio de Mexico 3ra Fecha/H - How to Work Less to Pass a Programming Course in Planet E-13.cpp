#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    int n, g;
    cin >> n >> g;

    vector <int> p(n);
    int total = 0;
    for(int i = 0; i < n; i++){
        cin >> p[i];
        total += p[i];
    }
    vector <vector <pair <int, int>>> ans(n+1);

    for(int i = 1; i < (1<<n); i++){
        int sum = 0, qntd = 0;
        for(int j = 0; j < n; j++){
            if(i & (1<<j)){
                qntd++;
                sum += p[j];
            }
        }

        if(sum*100/total >= g){
            ans[qntd].emplace_back(sum*100/total, i);
        }
    }

    int c = -1;
    for(int i = 0; i <= n; i++){
        if(ans[i].size()){
            c = i;
            break;
        }
    }

    cout << c << " " << ans[c].size() << "\n";
    for(auto i:ans[c]){
        cout << i.first;
        for(int j = 0; j < n; j++){
            if(i.second & (1<<j)){
                cout << " " << j+1;
            }
        }
        cout << "\n";
    }

    return 0;
}