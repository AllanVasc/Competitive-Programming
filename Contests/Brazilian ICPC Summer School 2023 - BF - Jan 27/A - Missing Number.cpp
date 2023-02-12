#include <bits/stdc++.h>
using namespace std;

#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int ask(int idx, int bit){
    cout << "? " << idx << " " << bit << endl;
    int answ;
    cin >> answ;
    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    
    vector<int> now(n + 1, 0);
    vector<int> mark(n + 1, true);

    int curr_bit = 0;
    int answ = 0;
    int qtd_question = 2*n + 19;
    int marked = 0;

    while(marked < n && qtd_question){
        int zeros = 0, ones = 0;
        for(int i = 0; i < n; i++){
            if(mark[i]){
                now[i] = ask(i + 1, curr_bit);
                qtd_question--;
                if(now[i]) ones++;
                else zeros++;
            }
        }

        if(ones < zeros){
            answ = (answ | (1 << curr_bit));
            for(int i = 0; i < n; i++){
                if(!now[i]){
                    if(mark[i]) marked++;
                    mark[i] = false;
                }
            }
        }
        else{
            for(int i = 0; i < n; i++){
                if(now[i]){
                    if(mark[i]) marked++;
                    mark[i] = false;
                }
            }
        }
        curr_bit++;
    }

    cout << "! " << answ << endl;
    return 0;
}