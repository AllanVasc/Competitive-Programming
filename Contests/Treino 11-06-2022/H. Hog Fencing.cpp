// H. Hog Fencing
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 0x3f3f3f3f;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
 
int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
 
    int maxArea = 0;
 
    for(int i = 1; i < n; i++){
 
        for(int j = i; j < n; j++){
 
            if(2*i + 2*j <= n) maxArea = max(maxArea, i*j);
            else break;
 
        }
    }
 
    cout << maxArea << '\n';
    
    return 0;
}