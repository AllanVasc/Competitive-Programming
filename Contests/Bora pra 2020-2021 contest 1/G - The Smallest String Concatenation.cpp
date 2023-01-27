//G - The Smallest String Concatenation
#include<bits/stdc++.h>
using namespace std;
#define forc(i, a, b) for(int i = (int)a; i < int(b); i++)
#define ford(i, a, b) for(int i = int(a); i >= (int)b; i--)
#define tam 100
typedef long long int ll;
typedef pair<ll,ll> ii;
typedef vector<vector<ll>> dpi;
 
bool comp(string a, string b){
    return ((a+b) < (b+a));
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n; cin>>n;
    vector<string>vet;
    string s;
    forc(i,0,n){
        cin>>s;
        vet.push_back(s);
    }
    sort(vet.begin(), vet.end(), comp);
    forc(i,0,n){
        cout<<vet[i];
    }
    cout<<endl;
    return 0;
}