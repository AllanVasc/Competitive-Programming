// C - Most Similar Words
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n, m;
        cin >> n >> m;

        vector<string> v;

        for(int i = 0; i < n; i++){
            string aux;
            cin >> aux;
            v.push_back(aux);
        }

        ll answ = LONG_LONG_MAX;

        for(int i = 0; i < n; i++){

            for(int j = i+1; j < n; j++){

                ll sum = 0;
                for(int k = 0; k < m; k++){

                    if(v[i][k] - '0' > v[j][k]-'0'){
                        sum += v[i][k] - v[j][k];
                    }
                    else sum += v[j][k] - v[i][k];
                }

                answ = min(answ, sum);

            }
        }

        cout << answ << '\n';
        
        
    }

    return 0;
}
