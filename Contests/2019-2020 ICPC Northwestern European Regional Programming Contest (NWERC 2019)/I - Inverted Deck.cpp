#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    vector<int> sorted = v;
    sort(sorted.begin(), sorted.end());
    int firstPos = -1;
    int lastPos = -1;
    for(int i = 0; i < n && firstPos == -1; i++){
        if(v[i] != sorted[i]){
            firstPos = i;
            lastPos = i;
            for(int j = i + 1; j < n; j++){
                if(v[j] != sorted[j]){
                    lastPos = max(lastPos, j);
                }
            }
        }
    }
    // cout << "fistPos = " << firstPos << '\n';
    // cout << "lastPos = " << lastPos << '\n';
    vector<int> reversed = v;
    reverse(reversed.begin() + firstPos, reversed.begin() + lastPos + 1);
    // for(auto i : reversed) cout << i << " ";
    // cout << '\n';
    bool flag = true;
    for(int i = 0; i < n; i++){
        if(sorted[i] != reversed[i]){
            flag = false;
        }
    }
    if(!flag){
        cout << "impossible" << '\n';
    }
    else{
        firstPos = max(firstPos, 0LL);
        lastPos = max(lastPos, 0LL);
        cout << firstPos + 1 << " " << lastPos + 1 << '\n';
    }
}