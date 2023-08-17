#include <bits/stdc++.h>

using namespace std;
#define ii pair <int, int>
vector <vector <ii>> h;

void hanoi(int x){
    for(auto [from, to] :h[x-1]){
        if(from == 1) from = 2;
        else if(from == 2) from = 1;

        if(to == 1) to = 2;
        else if(to == 2) to = 1;

        h[x].emplace_back(from, to);
    }

    h[x].emplace_back(0, 2);

    for(auto [from, to] :h[x-1]){
        if(from == 1) from = 0;
        else if(from == 0) from = 1;

        if(to == 1) to = 0;
        else if(to == 0) to = 1;

        h[x].emplace_back(from, to);
    }
}

bool query(int n, int k){
    if(k < h[n].size()) return false;

    int diff = k - h[n].size();
    if(diff & 1){
        ii old_last = h[n].back();
        h[n].pop_back();

        if(old_last.first == 1){
            h[n].emplace_back(1, 0);
            h[n].emplace_back(0, 2);
        }
        else{
            h[n].emplace_back(0, 1);
            h[n].emplace_back(1, 2);
        }

        diff--;
    }

    for(; diff > 0; diff -=2){
        h[n].emplace_back(2, 1);
        h[n].emplace_back(1, 2);
    }

    return true;

}

void init(int n){
    h.resize(n+1);

    for(int i = 1; i<=n; i++) hanoi(i);
}

int main(){
    int n, k;
    cin >> n >> k;

    init(n);

    if(query(n, k)){
        cout << "Y\n";
        for(auto [from, to]:h[n])
            cout << (char)(from + 'A') << " " << (char)(to + 'A') << "\n";
    }
    else cout << "N\n";


    return 0;
}