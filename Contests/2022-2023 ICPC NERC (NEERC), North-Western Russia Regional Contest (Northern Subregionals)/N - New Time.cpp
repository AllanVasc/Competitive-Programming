#include <bits/stdc++.h>

using namespace std;
#define int long long

int answ = 0;
bool solve(int curr, int final, int limit){
    if(curr <= final){
        // so adiantar
        answ += final - curr;
        return false;
    }
    else{
        answ += limit - curr;
        answ += final;
        return true;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int hcurr, mcurr;
    int hfinal, mfinal;
    char trash;
    cin >> hcurr >> trash >> mcurr;
    cin >> hfinal >> trash >> mfinal;

    if(solve(mcurr, mfinal, 60)){
        hcurr++;
        if(hcurr == 24) hcurr = 0;
        solve(hcurr, hfinal, 24);
    }
    else{
        solve(hcurr, hfinal, 24);
    }
    cout << answ << '\n';
    return 0;
}