#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair <int, int> ii;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> start(n);
    vector<int> end(m);
    for(int i = 0; i < n; i++) cin >> start[i];
    for(int i = 0; i < m; i++) cin >> end[i];

    map<int,int> freq;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(end[j] < start[i]) continue;
            freq[end[j] - start[i]]++;
        }
    }
    int answ = 0;
    int mx = 0;
    for(auto [x,y] : freq){
        if(y > mx){
            mx = y;
            answ = x;
        }
    }
    cout << answ << '\n';
    return 0;
}


