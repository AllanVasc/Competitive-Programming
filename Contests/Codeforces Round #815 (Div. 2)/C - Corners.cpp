// 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector<string> v;

        int qtd1 = 0;
        for(int i = 0; i < n; i++){
            string aux;
            cin >> aux;
            v.push_back(aux);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                //cout << v[i][j] << " ";
                if(v[i][j] == '1') qtd1++;
            }
            //cout << '\n';
        }

        bool double_zero = false;
        bool has_zero = false;

        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < m-1; j++){
                int qtd0 = 0;
                if(v[i][j] == '0') qtd0++;
                if(v[i+1][j] == '0') qtd0++;
                if(v[i][j+1] == '0') qtd0++;
                if(v[i+1][j+1] == '0') qtd0++;

                if(qtd0 >= 2){
                    double_zero = true;
                    has_zero = true;
                    break;
                }
                if(qtd0 > 0) has_zero = true;
            }
        }

        // cout << "double zero = " << double_zero << " has_zero = " << has_zero << '\n';
        int answ;

        if(double_zero) answ = qtd1;
        else if(has_zero) answ = qtd1 - 1;
        else answ = qtd1 - 2;

        cout << answ << '\n';
    }
    return 0;
}
