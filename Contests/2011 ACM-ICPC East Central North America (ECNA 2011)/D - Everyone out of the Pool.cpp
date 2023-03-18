#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    set<int> sq;
    for(int i = 1; i * i <= 1e9 + 5; i++){
        sq.insert(i * i);
    }
    set<int> triang;
    for(int i = 1; (((1 + i) * i) / 2) <= 1e9 + 5; i++){
        triang.insert((((1 + i) * i) / 2));
    }

    set<int> possible;
    for(auto x : sq){
        if(triang.count(x - 1) != 0){
            possible.insert(x);
        }
    }
    int a, b;
    int cnt = 1;
    while(cin >> a >> b){
        if(a == 0 && b == 0) break;
        int answ = 0;
        for(auto x : possible){
            if(x > a && x < b) answ++;
        }
        cout << "Case " << cnt << ": ";
        cout << answ << '\n';
        cnt++;
    }
    return 0;
}