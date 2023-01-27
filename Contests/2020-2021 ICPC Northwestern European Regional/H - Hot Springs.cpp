//H. Hot Springs
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    vector<int>t(n);
    for(int& x : t)cin>>x;
    sort(t.begin(),t.end());
    vector<int>nt;
    for(int l=0,r=n-1,op=0;l<=r;op^=1){
        if(op){
            nt.push_back(t[r--]);
        }else{
            nt.push_back(t[l++]);
        }
    }
    reverse(nt.begin(),nt.end());
    for(int x : nt){
        cout<<x<<' ';
    }
    cout<<'\n';
    return 0;
}