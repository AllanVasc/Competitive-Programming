#include <bits/stdc++.h>
using namespace std;
 
int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
    int n;
    cin >> n;
 
    int start = 1;
    int end = n;
    int kick = 2;
 
    while(kick != n + 1){
 
        cout << "? " << start << " " << kick << " " << end << endl;
 
        int answ;
        cin >> answ;
        if(answ == 0) start = kick;
        else if(answ == 1) end = kick;
 
        kick++;
    }
 
    cout << "! " << start << '\n';
 
    return 0;
}
