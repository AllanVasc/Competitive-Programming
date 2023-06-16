#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int a = 0;
    int b = 0;
    priority_queue<int> pq;
    for(int i = 0; i < n; i++) pq.push(v[i]);

    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            a += pq.top();
        }
        else{
            b += pq.top();
        }

        pq.pop();
    }


    cout << a << " " << b << '\n';


    return 0;
}