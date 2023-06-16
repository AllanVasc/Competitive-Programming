#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int sum  = 0;
    for(int i = 0; i < n-1; i++){
        int x;
        cin >> x;

        sum+=x;
    }

    int fixed = sum%n;

    for(int i = 0; i < n; i++){
        int val = (n + i - fixed) % n;
        cout << (val <= 20 ? val:-1) << "\n";
    }


    return 0;
}