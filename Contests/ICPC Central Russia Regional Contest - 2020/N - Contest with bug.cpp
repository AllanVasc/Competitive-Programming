#include <bits/stdc++.h>

using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k, n;
    cin >> k >> n;

    vector <int> t(n);
    for(int i = 0; i < n; i++)
        cin >> t[i];

    sort(t.begin(), t.end());

    int qtdA = 0, penA = 0;
    do{
        int time = 0, pen = 0, am = 0;
        for(int i = 0; i < n; i++){
            time += t[i];
            if(time <= k){
                am++;
                pen += time;
                pen %= 1440;
            }
            else break;
        }

        if(am > qtdA || (am == qtdA && penA > pen)){
            qtdA = am;
            penA = pen;
        }
    }
    while (next_permutation(t.begin(), t.end()));
    
    cout << qtdA << " " << penA << "\n";

    return 0;
}