#include <bits/stdc++.h>

using namespace std;

int32_t main(){
    string s;
    cin >> s;

    for(int i = 2; i <= s.size(); i<<=1){
        for(int l = 0; l + i - 1 < s.size(); l += i){
            for(int j = 0; j < i - j - 1; j++){
                swap(s[l + j], s[l + i - j - 1]);
            }
        }
    }

    cout << s << "\n";

    return 0;
}