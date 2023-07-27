#include <bits/stdc++.h>

#define int long long
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int cnt = 0;
        bool parity = false;
        while(n){

            if(n == 1){
                cnt++;
                break;
            }
            if(!parity){
                if(k % 2){
                    cnt += (k + 1) / 2;
                    break;
                }
                else{
                    cnt += (n + 1) / 2;
                    k = k / 2;
                    if(!parity && (n % 2 == 0)) parity = parity;
                    if(!parity && (n % 2 == 1)) parity = !parity;
                    n = n / 2;
                }
            }
            else{
                if(k % 2 == 0){
                    cnt += k / 2;
                    break;
                }
                else{
                    cnt += n / 2;
                    k = (k + 1) / 2;
                    if(parity && (n % 2 == 0)) parity = parity;
                    if(parity && (n % 2 == 1)) parity = !parity;
                    n = (n + 1) / 2;
                }
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}