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

    int a, b, x, y;
    cin >> a >> b >> x >> y;

    vector<int> firsts;
    firsts.push_back(0);
    bool flag = true;
    int qtd = 1;
    int last = 0;
    int total = 1;
    while(firsts.back() <= 1e9){
        if(flag){
            qtd *= a;
            firsts.push_back(total);
            total += qtd;
            flag = !flag;
        }
        else{
            qtd *= b;
            firsts.push_back(total);
            total += qtd;
            flag = !flag;
        }
    }
    // cout << firsts.size() << '\n';
    // for(int i = 0; i < firsts.size(); i++){
    //     cout << firsts[i] << '\n';
    // }

    while(x != y){
        if(x < y) swap(x, y);

        int line = 0;
        for(int i = 0; i < firsts.size(); i++){
            if(firsts[i] <= x) line = i;
        }

        int qtd = x - firsts[line];

        if(line % 2 == 0){  // Transação "b"
            int jump = qtd/b;
            // cout << "jump = " << jump << '\n';
            x = firsts[line - 1] + jump;
        }
        else{   // transação "a"
            int jump = qtd/a;
            // cout << "jump = " << jump << '\n';
            x = firsts[line - 1] + jump;
        }
        // cout << "x = " << x << '\n';
    }

    cout << x << '\n';
    return 0;
}