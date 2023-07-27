#include <bits/stdc++.h>

using namespace std;
#define int long long

const double eps = 1e-8;

int cmp(double a, double b){
    if(abs(a - b) < eps) return 0;
    return (a > b ? 1:-1);
}

int32_t main(){
    int d;
    double p;

    cin >> d >> p;

    vector <int> v(d);
    for(int i = 0; i < d; i++)
        cin >> v[i];

    vector <int> ps(d, 0);
    for(int i = 1; i < d; i++){
        int x = v[i] - v[i-1];
        ps[i] = ps[i-1] + x*x;
    }
    
    int pos = 0, neg = 0;
    for(int l = 0; l < d; l++){
        for(int r = l; r < d; r++){
            if(r - l + 1 < 3) continue;

            // cout << l << " " << r << "\n";
            // cout << ps[r] << " " << ps[l] << " " << ps[r] - ps[l] << "\n\n";

            double A = (v[r] - v[l]) * (1.0 / (r - l));
            double D = ps[r] - ps[l] - (v[r] - v[l])*(v[r] - v[l]) * 1.0 / (r - l);
            D *= (1.0 / (r - l));
            D = sqrt(D);

            // cout << A/D << "\n";

            if(!cmp(D, 0)){
                if(cmp(A, 0) > 0) pos++;
                else if(cmp(A, 0) < 0) neg++;
            }

            else if(cmp(A/D, p) >= 0) pos++;
            else if(cmp(A/D, -p) <= 0){
                neg++;
                // cout << A/D << " " << -p << "\n";
                // cout << "ACHEI\n";
            }
        }
    }

    cout << pos << " " << neg << "\n";

    return 0;
}