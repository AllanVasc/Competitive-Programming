//C. Contest Struggles
#include<bits/stdc++.h>
using namespace std;
//2 1
//100 10
// soma(1..2) = 200
// (1/1)*soma(1..1) = 10
// soma(1..1) = 10
// soma(2..2) = 190
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    int d,s;
    cin>>d>>s;
    int soma1 = d*n;
    int soma2 = s*k;
    int soma3 = soma1-soma2;
    double val = soma3/(double)(n-k);
 
    if(val > 100 || val < 0){
        cout<<"impossible\n";
    }else{
        cout<<setprecision(15)<<fixed<<val<<'\n';
    }
 
    
    return 0;
}