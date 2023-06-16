#include <bits/stdc++.h>

using namespace std;

int main(){
    int r;
    cin >> r;

    double a, b, alpha = atan2(3, 4);

    a = r*r*sin(alpha)*cos(alpha);
    b = r*r*alpha;

    cout << setprecision(9) << fixed;
    cout << a + b << "\n";

    return 0;
}