#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector <int> ans(n);
    vector <tuple <int, int, int>> v;

    int cnt = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        cnt += x / (n-1);

        v.emplace_back(x%(n-1) - (x / (n-1)), i, x / (n-1));
    }

    sort(v.begin(), v.end());

    int last = n-1, val = cnt;
    while(last >= 0){
        int am = v.end() - lower_bound(v.begin(), v.end(), make_tuple(n-1 - val, -1, -1));
        if(am + cnt == val) break;

        val = am + cnt;
        last = n - am - 1;
    }

    // cout << last << "\n";

    if(last >= 0){
        for(int i = 0; i < n; i++){
            int x, pos, init;
            tie(x, pos, init) = v[i];

            if(i <= last){
                ans[pos] = x + val;
            }
            else ans[pos] = x + val - (n-1) - 1;
        }

        for(int i = 0; i < n; i++){
            if(i) cout << " ";
            cout << ans[i];
        }
        cout << "\n";
    }
    else cout << "Recurrent\n";

    return 0;
}