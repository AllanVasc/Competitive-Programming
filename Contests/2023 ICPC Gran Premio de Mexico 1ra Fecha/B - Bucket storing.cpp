#include<bits/stdc++.h>
using namespace std;

#define int long long
signed main(){
    int n, k, l;
    cin >> n >> k >> l;
    int totalCoffee = n * k;
    cout << (totalCoffee + l - 1) / l << '\n';
    return 0;
}