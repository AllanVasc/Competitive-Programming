#include <bits/stdc++.h>

using namespace std;
#define int long long
#define iii tuple<int,int,int>

const int ms = 1e6 + 5;

int last[ms];
vector<int> num;

vector<int> fact(int x){
    vector<int> ret;
    for(int i=2; i*i<=x; i++){
        if(x%i == 0){
            ret.push_back(i);
            while(x%i == 0) x/=i;
        }
    }
    if(x > 1) ret.push_back(x);
    return ret;
}

int toNum(int l, int r){
    int ret = 0;
    for(int i=l, mul=1; i<=r; i++, mul*=10){
        ret += num[i]*mul;
    }
    return ret;
}

int check(int lwr, int pref, int suf, vector<int> &primes){
    // tem que ser um numero maior ou igual a lwr e com o o numero da direita menor que suf
    int ret = 0;

    for(int x: primes){
        // pegar o maior multiplo de X <= suf
        int aux = (suf/x) * x;
        // testa esse cara
        if(!aux) continue;
        if(pref+aux >= lwr){
            ret = max(ret, pref+aux);
        }
    }
    return ret;
}

int gen(int left, int right){
    int mul=1;
    int ret =0;
    for(;right >=0; right--, mul*=10){
        ret += 9*mul;
    }
    for(;left;left/=10,mul*=10){
        ret += mul*(left%10);
    }
    return ret;
}

iii solve(int nl, int nr){
    num.clear();
    for(int x = nr; x; x/=10){
        num.push_back(x%10);
    }

    int left = toNum((num.size() + 1)/2, num.size()-1);
    int right = toNum(0, (num.size()-1)/2);

    vector<int> pl;
    pl = fact(left);

    int sz = ((num.size()-1)/2) + 1;
    int ans = check(nl, left * powl(10, sz), right, pl);
    return {ans, left, right};
}

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("halfnice.in", "r", stdin);

    int t, cs=1;
    cin >> t;
    //sieve();

    while (t--){
        int nl, nr;
        cin >> nl >> nr;

        auto [x, y, z] = solve(nl, nr);
        if(x){
            cout << "Case " << cs++ << ": " << x << '\n';
            continue; 
        }
        y--;
        if(y == 1) y--;
        int newNum = gen(y, (num.size()-1)/2);
        //cout << newNum << endl;
        if(newNum < 10){
            cout << "Case " << cs++ << ": impossible\n";
            continue;
        }
        auto [a, b, c] = solve(nl, newNum); 
        
        if(a){
            cout << "Case " << cs++ << ": " << a << '\n';
        }
        else{
            cout <<"Case " << cs++ <<  ": impossible\n";
        }




          
    }
    
}