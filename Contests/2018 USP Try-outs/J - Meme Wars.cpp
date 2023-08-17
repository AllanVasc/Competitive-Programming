#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 2 * 1e3;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    string last = "a";
    char nxt = 'b';
    while(last.size() <= ms){
        string curr = last + nxt + last;
        nxt++;
        swap(curr, last);
    }
    // cout << last << '\n';
    cout << last[n - 1] << '\n';
}