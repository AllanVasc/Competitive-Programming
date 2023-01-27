//1527A - And Then There Were K
#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int qtdTestes;
    cin >> qtdTestes;
 
    while(qtdTestes--){
        
        int n;
        cin >> n;
        ll max = 0;
 
        bitset<32> bit(n);
 
        for(int i = 0; i < 32; i++){
            
            bit[i] = !bit[i];
            //cout << bit[i] << " ";
        }
        //cout << endl;
 
        bool achei0 = false;
        for(int i = 31; i >= 0; i--){
 
            if(achei0){
                max += pow(2, i);
            }
 
            if(bit[i] == 0) achei0 = true;
 
        }
 
        cout << max << endl;
    }
 
}
 
/*
 
 
*/