#include<bits/stdc++.h>

using namespace std;
#define int long long 

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    int l = 1;
    int r = n;
    int dist = 1;
    bool step = true;
    while(l != r){
        if(step){
            // esquerda para direita
            int k = (r - l) / dist;
            if(k & 1) r -= dist;
        }
        else{
            int k = (r - l) / dist;
            if(k & 1) l += dist;
        }
        dist *= 2;
        step = !step;
    }
    cout << l << '\n';
    return 0;
}
