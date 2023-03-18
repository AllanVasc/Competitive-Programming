#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> psDist;
    psDist.push_back(0);
    for(int i = 0; i < n - 1; i++){
        int aux;
        cin >> aux;
        psDist.push_back(psDist.back() + aux);
    }

    vector<int> ssDist;
    ssDist.push_back(0);
    for(int i = psDist.size() - 1; i > 0; i--){
        ssDist.push_back(ssDist.back() + psDist[i] - psDist[i - 1]);
    }
    reverse(ssDist.begin(), ssDist.end());

    vector<int> times(n);
    for(int i = 0; i < n; i++) cin >> times[i];

    vector<int> psTimes;
    psTimes.push_back(0);
    for(int i = 0; i < n; i++){
        psTimes.push_back(psTimes.back() + times[i]);
    }
    vector<int> ssTimes;
    ssTimes.push_back(0);
    for(int i = n - 1; i >= 0; i--){
        ssTimes.push_back(ssTimes.back() + times[i]);
    }
    reverse(ssTimes.begin(), ssTimes.end());

    // cout << "PS dist: ";
    // for(auto x : psDist) cout << x << " ";
    // cout << '\n';
    // cout << "SS dist: ";
    // for(auto x : ssDist) cout << x << " ";
    // cout << '\n';
    // cout << "psTime: ";
    // for(auto x : psTimes) cout << x << " ";
    // cout << '\n';
    // cout << "ssTimes: ";
    // for(auto x : ssTimes) cout << x << " ";
    // cout << '\n';

    int answ = 0;
    for(int i = 0; i < n; i++){
        int timeTrain1 = psDist[i] + psTimes[i];
        int timeTrain2 = ssDist[i] + ssTimes[i + 1];
        int diff = abs(timeTrain1 - timeTrain2);
        if(times[i] - diff >= 0){
            answ = times[i] - diff;
        }
    }
    cout << answ << '\n';
}