#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
 
    int n;
    cin >> n;
 
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
 
    int k;
    cin >> k;
 
    vector<int> custos(k);
    for(int i = 0; i < k; i++) cin >> custos[i];
 
    int most = a[0];
    for(int i = 0; i < n; i++){
        most = max(most, a[i]);
    }
    // cout << most << '\n';
 
    int answ = k*most;
    for(int i = 0; i < k; i++){
        answ += custos[i];
    }
    cout << answ << '\n';
}