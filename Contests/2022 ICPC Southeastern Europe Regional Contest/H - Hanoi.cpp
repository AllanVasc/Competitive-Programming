#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<int> third;
    third.push_back(1000);
    vector<pair<int,int>> answ;
    for(int i = 0; i < n; i++){
        int curr = v.back();
        v.pop_back();
        answ.push_back({1, 2});
        int cnt = 0;
        while(third.back() < curr){
            answ.push_back({3, 1});
            v.push_back(third.back());
            third.pop_back();
            cnt++;
        }
        third.push_back(curr);
        answ.push_back({2, 3});
        for(int j = 0; j < cnt; j++){
            answ.push_back({1, 3});
            third.push_back(v.back());
            v.pop_back();
        }
    }
    cout << answ.size() << '\n';
    for(auto [x, y] : answ){
        cout << x << " " << y << '\n';
    }
    return 0;
}