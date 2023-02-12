#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<char> vowel = { 'a', 'e', 'i', 'o', 'u'};

ii count(int n){
    int qtd_vowel = 0;
    int qtd_y = 0;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++){
            for(auto curr_v : vowel){
                if(tolower(s[j]) == curr_v){
                    qtd_vowel++;
                    break;
                }
            }
            if(tolower(s[j]) == 'y') qtd_y++;
        }
    }
    // cout << "vogal = " << qtd_vowel << " y = " << qtd_y << '\n';
    return {qtd_vowel, qtd_y};
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        vector<ii> answ(3, {0,0});

        
        answ[0] = count(n1);
        answ[1] = count(n2);
        answ[2] = count(n3);
        
        int sum1 = answ[0].first + answ[0].second;
        int sum2 = answ[1].first + answ[1].second;
        int sum3 = answ[2].first + answ[2].second;

        if(answ[0].first > 5 || answ[1].first > 7 || answ[2].first > 5){
            cout << "NO" << '\n';
        }
        else if(sum1 >= 5 && sum2 >= 7 && sum3 >= 5){
            cout << "YES" << '\n';
        }
        else{
            cout << "NO" << '\n';
        }
    }
    return 0;
}