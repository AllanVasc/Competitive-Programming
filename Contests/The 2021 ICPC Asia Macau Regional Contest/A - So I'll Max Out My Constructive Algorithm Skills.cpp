#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector <int> input(n*n), ans;

        for(int i = 0; i < n*n; i++){
            cin >> input[i];
        }

        for(int i = 0; i < n*n; i += 2*n){
            for(int j = 0; j < n && i+j < n*n; j++){
                ans.push_back(input[i+j]);
            }

            for(int j = n - 1; j >= 0 && i+j+n < n*n; j--){
                ans.push_back(input[i+j+n]);
            }
        }

        int pot = 0;
        for(int i = 1; i < n*n; i++){
            if(ans[i-1] > ans[i]) pot--;
            else pot++;
        }

        if(pot > 0) reverse(ans.begin(), ans.end());
        for(int i = 0; i < n*n; i++){
            if(i) cout << " ";
            cout << ans[i];
        }
        cout << "\n";

    }


    return 0;
}