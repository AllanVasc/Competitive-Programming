#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    string s;
    cin >> s;

    int firstzero = 0;
    int i = 0;
    while(i < n && s[i] == '0') i++;
    for(; i < n; i++){
        if(s[i] == '0'){
            firstzero = i;
            break;
        }
    }
    // cout << "achei zero em " << firstzero << '\n';
    string answ = s;
    for(int i = 0; i < firstzero; i++){
        string check;
        for(int j = 0; j < n - firstzero; j++){
            check.push_back(s[i + j]);
        }
        // cout << "check = " << check << '\n';
        string new_possibility = s;
        for(int j = 0; j < n - firstzero; j++){
            if(s[firstzero + j] == '1' || check[j] == '1'){
                new_possibility[firstzero + j] = '1';
            }
        }
        // cout << "possivel resposta = " << new_possibility << '\n';
        answ = max(answ, new_possibility);
    }
    reverse(answ.begin(), answ.end());
    while(answ.size() > 1 && answ.back() == '0') answ.pop_back();
    reverse(answ.begin(), answ.end());

    cout << answ << '\n';
    return 0;
}