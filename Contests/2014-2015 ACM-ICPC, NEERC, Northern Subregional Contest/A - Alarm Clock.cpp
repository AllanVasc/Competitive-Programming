#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("alarm.in", "r", stdin);
    freopen("alarm.out", "w", stdout);

    vector <int> amount = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    vector <tuple <int, int, int, int>> ans;

    int n;
    cin >> n;

    for(int h1 = 0; h1 < 3 && ans.empty(); h1++){
        for(int h2 = 0; h2 < 10 && ans.empty(); h2++){
            for(int m1 = 0; m1 < 7 && ans.empty(); m1++){
                for(int m2 = 0; m2 < 10 && ans.empty(); m2++){
                    int aux = 0;
                    aux += amount[h1];
                    aux += amount[h2];
                    aux += amount[m1];
                    aux += amount[m2];

                    if(aux == n){
                        int h, m;
                        h = h1*10 + h2;
                        m = m1*10 + m2;

                        if(!h || h >= 24) continue;
                        if(m < 0 || m >= 60) continue;

                        ans.emplace_back(h1, h2, m1, m2);
                    }

                }
            }
        }
    }

    if(ans.empty()) cout << "Impossible\n";
    else{
        int h1, h2, m1, m2;

        tie(h1, h2, m1, m2) = ans[0];
        cout << h1 << h2 << ":" << m1 << m2 << "\n";
    }



    return 0;
}