#include<bits/stdc++.h>
using namespace std;

#define int long long
const double PI = acos(-1.0);

int sq(int x){
    return x * x;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    vector<int> v(4);
    for(int i = 0; i < 4; i++) cin >> v[i];

    sort(v.rbegin(), v.rend());
    swap(v[1], v[3]);

    double ans = 0;
    for(double alpha = 0.0; alpha <= 2*PI; alpha += 0.00001){
        double answ = 0.0;
        double x = sqrt(v[0]*v[0] + v[1] * v[1] - 2*v[0]*v[1]*cos(alpha));
        //checar se é próprio
        if(v[2] + v[3] < x || v[2] + x < v[3] || x + v[3] < v[2]) continue;
        double a1, a2;
        a1 = v[0] * v[1] * sin(alpha);
        double beta = acos((v[2]*v[2] + x*x - v[3] * v[3])/(2 * v[2] * x));
        a2 = x * v[2] * sin(beta);

        a1 = abs(a1);
        a2 = abs(a2);

        answ = (a1 + a2)/2;
        ans = max(ans, answ);
    }
    
    
    
    cout << setprecision(10) << fixed;
    cout << ans << '\n';


    return 0;
}