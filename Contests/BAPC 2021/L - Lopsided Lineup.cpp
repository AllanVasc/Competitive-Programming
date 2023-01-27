// 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int INF = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;


int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> v;
    v.assign(n, vector<int>());

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int aux;
            cin >> aux;
            v[i].push_back(aux);
        }
    }

    vector<ii> p;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            sum += v[i][j];
        }
        p.push_back({sum,i});
    }

    sort(p.begin(), p.end());

    int suma = 0;
    int sumb = 0;

    for(int i = 0; i < n/2; i++){
        suma += p[i].first;
    }
    for(int i = n/2; i < n; i++){
        sumb += p[i].first;
    }

    cout << (sumb - suma)/2 << '\n';

    return 0;
}
