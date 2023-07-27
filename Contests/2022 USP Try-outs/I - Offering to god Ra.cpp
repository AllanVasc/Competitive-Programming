#include<bits/stdc++.h>

using namespace std;
#define int long long 

int cnt(int x){
    int ret =0;
    while(x >= 1){
        ret++;
        x/=10;
    }
    return ret;
}

bool cmp(int x, int y){
    if(cnt(y) < cnt(x))return false;
    vector<int> aux, auy;
    while(x >= 1){
        aux.push_back(x%10);
        x/=10;
    }
    while(y >= 1){
        auy.push_back(y%10);
        y/=10;
    }

    for(int i=aux.size()-1, j = auy.size() -1; i>=0; i--, j--){
        if(aux[i] != auy[j]) return false;
    }


    return true;

}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int a, b;
        cin >> a >> b;
        int ori = b;
        int digA = cnt(a), digB = cnt(b);
        while(digB < digA) b*=10, digB++;

        int ans = -1;

        while(ans == -1){
            int num = b + (b%a == 0 ? 0 : (a  - b%a));
        
            if(cmp(ori, num)) ans = num;
            b*=10;
        }

        cout << ans << '\n';


    }


    return 0;
}
