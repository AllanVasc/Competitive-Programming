#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, t;
    cin >> n >> t;

    vector <int> sai(n, 0), entra(n, 0);
    int sum = 0, msum = 0, msai = 0, mentra = 0, idx = 0;

    for(int i = 0; i < t; i++){
        int x, y;
        cin >> x >> y;

        x--, y--;

        sai[x]++;
        entra[y]++;

        sum += entra[x];
        sum += sai[y];

        if(x==y) sum--;
        
        msai = max(sai[x], msai);
        mentra = max(mentra, entra[y]);
        if(sai[x] + entra[x] > sai[idx] + entra[idx]) idx = x;
        if(sai[y] + entra[y] > sai[idx] + entra[idx]) idx = y;

        
        msum = max(max(msum, sai[idx] + entra[idx] + 1), msai + mentra);

        cout << sum << " " << msum << "\n";
    }

    return 0;
}