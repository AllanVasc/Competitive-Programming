#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> full(n, 0);
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3 * n; j++){
                char curr;
                cin >> curr;
                if(curr == '*'){
                    full[j/3]++;
                }
            }
        }

        int answ = 0;
        for(int i = 0; i < n; i++){
            answ = max(answ, full[i]);
        }
        cout << answ * 4 << '\n';
    }
    return 0;
}