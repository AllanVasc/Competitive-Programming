// 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int INF = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;

long double pita(long double x, long double y){
    return sqrtl(x*x + y*y);
}

long double func(long double side1, long double side2, long double x, int w){
    return pita(side1, x) + pita(side2, w-x);
}

long double search(long double l, long double r, int side1, int side2, int w){
    
    for(int i = 0; i < 200; i++){
        long double m1 = l + (r-l)/3.0;
        long double m2 = r - (r-l)/3.0;
        
        if(func(side1, side2, m1, w) > func(side1, side2, m2, w)){
            l = m1;
        }
        else 
            r = m2;
    }

    return func(side1, side2, l, w);
}

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    cout << fixed << setprecision(8);

    for(int i = 0; i < n; i++){
        int w,g,h,r;
        cin >> w >> g >> h >> r;

        long double answ_min = pita(w, h-g);
        long double answ_max = search(0, w, g-r, h-r, w);

        cout << answ_min << " " << answ_max << '\n';
    }
    
    return 0;
}
