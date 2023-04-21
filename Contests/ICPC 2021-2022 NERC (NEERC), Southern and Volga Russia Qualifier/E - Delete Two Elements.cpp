#include<bits/stdc++.h>
using namespace std;

#define int long long
using ii = pair<int,int>;
const int INF = 1e18;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int sum = 0;
    for(int i = 0; i < n; i++) sum += v[i];

    if((2 * sum) % n != 0){
        cout << 0 << '\n';
    }
    else{
        int answ = 0;
        map<int,int> freq;
        int check = (2 * sum) / n;
        for(int i = 0; i < n; i++){
            int val = v[i];
            if(val <= check) answ += freq[check - val];
            freq[val]++;
        }

        cout << answ << '\n';

    }

    return 0;
}