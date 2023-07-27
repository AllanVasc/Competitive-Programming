#include <bits/stdc++.h>

using namespace std;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<string> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    int ans = n;
    vector<int> foi(n, 0);

    for(int i=0; i<n; i++){
        if(foi[i]) continue;
        for(int s=0; s<v[i].size(); s++){
            for(int j=i+1; j<n; j++){
                if(v[j].size() != v[i].size() || foi[j]) continue;
                bool eq = true;
                for(int k=0, x = s; k<v[j].size() && eq; k++, x = (x+1)%v[i].size()){
                    if(v[j][k] != v[i][x]) eq = false;
                }
                if(eq) foi[j] = true, ans--;
            }
        }
    }

    cout << ans << endl;

    return 0;
}