#include <bits/stdc++.h>

using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector <int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    bool changed = true;

    for(int i = 0; i < k && changed; i++){
        map <int, int> freq;

        for(int j = 0; j < n; j++)
            freq[v[j]]++;

        changed = false;
        for(int j = 0; j < n; j++){
            int nv = freq[v[j]];
            if(v[j] != nv) changed = true;

            v[j] = nv;
        }
    }

    for(int i = 0; i < n; i++){
        if(i) cout << " ";
        cout << v[i];
    }

    cout << "\n";

}