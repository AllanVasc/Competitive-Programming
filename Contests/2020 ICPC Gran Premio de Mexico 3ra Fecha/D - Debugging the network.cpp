#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    int t;
    cin >> t;

    while(t--){
        string s;
        int k;
        cin >> s >> k;

        string ans = "";
        int acc = 0;
        bool broke = false;
        for(int i = 0; i < s.size() && !broke; i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                for(int j = 0; j < max(1LL, acc); j++) ans.push_back(s[i]);
                acc = 0;
            }
            else{
                acc *= 10;
                acc += (s[i] - '0');

                if(acc > k) broke = true;
            }

            if(ans.size() > k) broke = true;
        }

        if(broke || acc) cout << "unfeasible\n";
        else cout << ans << "\n";
    }

    return 0;
}