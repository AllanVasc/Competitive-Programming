#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int getDigit(char c){
    if(isalpha(c)){
        return c - 'A' + 10;
    }
    else{
        return c - '0';
    }
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;

    while(t--){
        int x, y;
        string z;
        cin >> x >> y >> z;

        int converted = 0;
        int mul = 1;
        for(int i = z.size() - 1; i >= 0; i--){
            converted += getDigit(z[i])*mul;
            mul *= x;
        }

        string answ;
        if(y == 1) answ.assign(converted, '1');
        else if(converted == 0) answ = "0";
        else{
            while(converted){
                int aux = converted%y;
                converted /= y;

                if(aux < 10) answ.push_back(aux + '0');
                else answ.push_back(aux - 10 + 'A');
            }
        }

        reverse(answ.begin(), answ.end());
        cout << answ << '\n';

    }
    return 0;
}