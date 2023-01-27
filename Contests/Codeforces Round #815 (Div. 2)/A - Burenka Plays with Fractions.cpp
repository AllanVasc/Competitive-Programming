// 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int INF = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;

const int MAXN = 2*1e5 + 100;

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;

    while(t--){

        int a,b,c,d;
        cin >> a >> b >> c >> d;
        
        int g;

        if(a != 0 && b != 0){
            g = __gcd(a,b);
            a = a/g;
            b = b/g;
        }
        
        if(c != 0 && d != 0){
            g = __gcd(c,d);
            c = c/g;
            d = d/g;
        }
        
        if(a != 0 && c != 0){
            g = __gcd(a,c);
            a = a/g;
            c = c/g;
        }
        
        if(b != 0 && d != 0){
            g = __gcd(b,d);
            b = b/g;
            d = d/g;
        }

        // cout << a << " " << b << '\n';
        // cout << c << " " << d << '\n';

        unsigned int numerador = (c*b);
        unsigned int denominador = (d*a);

        // cout << "num = " << numerador << " deno = " << denominador << '\n';
        int answ = -1;

        if(numerador == denominador){
            answ = 0;
        }
        else{

            if(numerador != 0 && denominador != 0){
                numerador = numerador/__gcd(numerador, denominador);
                denominador = denominador/__gcd(numerador, denominador);
            }

            if(numerador <= 1 || denominador <= 1){
                answ = 1;
            }
            else{
                answ = 2;
            }

        }
    
        cout << answ << '\n';
    }

    return 0;
}