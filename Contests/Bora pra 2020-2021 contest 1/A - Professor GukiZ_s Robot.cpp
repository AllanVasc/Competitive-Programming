//A - Professor GukiZ's Robot
#include<bits/stdc++.h>
using namespace std;
#define forc(i, a, b) for(int i = (int)a; i < int(b); i++)
#define ford(i, a, b) for(int i = int(a); i >= (int)b; i--)
#define tam 100
typedef long long int ll;
typedef pair<ll,ll> ii;
typedef vector<vector<ll>> dpi;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll ix,iy, fx, fy;
    cin>>ix>>iy>>fx>>fy;
    ll distx = fx - ix, disty = fy - iy;
    ll Mdistx = abs(distx), Mdisty = abs(disty);
    ll maximo = max(Mdistx, Mdisty);
    cout<<maximo<<endl;
    return 0;
}