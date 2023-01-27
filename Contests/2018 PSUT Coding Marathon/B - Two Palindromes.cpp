#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s1,s2;
    cin >> s1 >> s2;

    int n = s1.size() + s2.size();

    vector<int> freq(26, 0);
    for(int i = 0; i < s1.size(); i++){
        freq[s1[i] - 'a']++;
    }
    for(int i = 0; i < s2.size(); i++){
        freq[s2[i] - 'a']++;
    }

    int impar = 0;
    for(int i = 0; i < 26; i++){
        if(freq[i] % 2 != 0) impar++;
    }

    if(n % 2 == 0 && impar == 0){
        // string answ;
        // for(int i = 0; i < 26; i++){
        //     while(freq[i]){
        //         answ.push_back(i + 'a');
        //         freq[i] -= 2;
        //     }
        // }
        // string aux = answ;
        // reverse(aux.begin(), aux.end());
        // answ = answ + aux;
        // cout << answ << '\n';
        cout << "YES" << '\n';
    }
    else if(n % 2 == 1 && impar == 1){
        // string answ;
        // string middle;
        // for(int i = 0; i < 26; i++){
        //     if(freq[i] % 2 == 1){
        //         middle.push_back(i + 'a');
        //         freq[i]--;
        //     }
        //     while(freq[i]){
        //         answ.push_back(i + 'a');
        //     }
        // }
        // string aux = answ;
        // reverse(aux.begin(), aux.end());
        // answ = answ + middle + aux;
        // cout << answ << '\n';
        cout << "YES" << '\n';
    }
    else{
        cout << "NO" << '\n';
    }

    return 0;
}