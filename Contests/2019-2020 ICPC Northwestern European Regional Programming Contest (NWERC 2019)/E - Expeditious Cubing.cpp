#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<int> numbers;
    for(int i = 0; i < 4; i++){
        string s;
        cin >> s;
        int number = 0;
        for(int j = 0; j < s.size(); j++){
            if(s[j] == '.') continue;
            number *= 10;
            number += s[j] - '0';
        }
        numbers.push_back(number);
    }

    string s;
    cin >> s;
    int target = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '.') continue;
        target *= 10;
        target += s[i] - '0';
    }
    int mn = LONG_LONG_MAX;
    int mx = -1;
    for(int i = 1; i <= 2000; i++){
        vector<int> check = numbers;
        check.push_back(i);
        sort(check.begin(), check.end());
        int average = 0;
        for(int j = 1; j < 4; j++){
            average += check[j];
        }
        if(average <= 3 * target){
            // possivel
            mn = min(mn, i);
            mx = max(mx, i);
        }
    }

    // cout << "mn = " << mn << '\n';
    // cout << "mx = " << mx << '\n';
    if(mn == LONG_LONG_MAX){
        cout << "impossible" << '\n';
    }
    else if(mn == 1 && mx == 2000){
        cout << "infinite" << '\n';
    }
    else{
        string answ = to_string(mx);
        for(int i = 0; i < answ.size(); i++){
            if(i == answ.size() - 2){
                cout << '.';
            }
            cout << answ[i];
        }
        cout << '\n';

    }

    return 0;
}