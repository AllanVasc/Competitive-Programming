#include<bits/stdc++.h>
using namespace std;

#define int long long
using ii = pair<int,int>;
using iii = tuple<int, int,int>;
const int INF = 1e18 + 10000;

int check(int mid, vector<iii>& v){
    int n = v.size();
    // cout << "TESTANDO SIZE = " << mid << '\n';
    priority_queue<ii, vector<ii>, greater<ii>> pqMin;
    priority_queue<ii, vector<ii>> pqMax;
    for(int i = 0; i < n; i++){
        auto [qtd, b, c] = v[i];
        if(qtd < mid){
            pqMin.push({c, qtd});
            // cout << "Min = qtd = " << qtd << '\n';
        }
        else if(qtd > mid){
            pqMax.push({b, qtd});
            // cout << "Max = qtd = " << qtd << '\n';
        }
    }
    int cost = 0;
    while(!pqMax.empty()){
        if(pqMin.empty()){
            cost = INF;
            break;
        }
        auto [cMin, qtdMin] = pqMin.top();
        auto [cMax, qtdMax] = pqMax.top();
        pqMin.pop();
        pqMax.pop();

        int canPut = min(mid - qtdMin, qtdMax - mid);
        cost += canPut * (cMin + cMax);
        if(qtdMin + canPut < mid) pqMin.push({cMin, qtdMin + canPut});
        if(qtdMax - canPut > mid) pqMax.push({cMax, qtdMax - canPut}); 
    }
    // cout << "COST = " << cost << '\n';
    return cost;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<iii> v;
    int mxSz = 0;
    for(int i = 0; i < n; i++){
        int qtd, b, c;
        cin >> qtd >> b >> c;
        v.push_back({qtd, b, c});
        mxSz = max(mxSz, qtd);
    }
    sort(v.begin(), v.end());

    int l = 0;
    int r = mxSz;
    int answ = mxSz;
    while(l <= r){
        int mid = l + (r - l)/2;
        if(check(mid, v) <= k){
            answ = min(answ, mid);
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    cout << answ << '\n';
    
    return 0;
}