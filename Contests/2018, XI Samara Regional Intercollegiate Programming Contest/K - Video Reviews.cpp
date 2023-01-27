#include<bits/stdc++.h>
#define endl "\n"

using namespace std;
typedef long long ll;

vector<int> v;

bool check(int qtd, int m){
    int count = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] <= count) count++;
        else if(qtd){
            count++;
            qtd--;
        }
    }

    if(count >= m) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    v.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> v[i];

    int l = 0;
    int r = n;
    int answ = n;
    
    while(l <= r){
        int mid = l + (r-l)/2;

        if(check(mid, m)){
            answ = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    cout << answ << '\n';
    
}