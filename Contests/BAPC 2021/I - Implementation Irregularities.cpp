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

    vector<int> duration(n,0);
    vector<int> prefixSum(n,0);
    vector<int> cronotime(n,0);

    for(int i = 0; i < n; i++) cin >> duration[i];
    for(int i = 0; i < n; i++) cin >> cronotime[i];

    vector<ii> match;

    for(int i = 0; i < n; i++){
        if(cronotime[i] != -1){
            match.push_back({cronotime[i],duration[i]});
        }
    }

    sort(match.begin(), match.end());

    prefixSum[0] = match[0].second;
    for(int i = 1; i < match.size(); i++){
        prefixSum[i] += prefixSum[i-1] + match[i].second;
    }

    int totalPC = 1;
    for(int i = 0; i < match.size(); i++){
        if(match[i].first < double(prefixSum[i])/totalPC){
            totalPC += (prefixSum[i]+ match[i].first - 1)/match[i].first - totalPC;
        } 
    }

    cout << totalPC << '\n';

    return 0;
}
