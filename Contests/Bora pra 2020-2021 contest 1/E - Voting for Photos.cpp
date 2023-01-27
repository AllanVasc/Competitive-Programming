//E - Voting for Photos
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main(){ 
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
 
    int n;
    cin >> n;
    
    pair<int,int> max = {-1,-1};
    map<int,int> frequency;
 
    for(int i = 0; i < n; i++){
        int aux;
        cin >> aux;
        frequency[aux]++;
 
        if(frequency[aux] > max.second){
            max.first = aux;
            max.second = frequency[aux];
        }
    }
 
    cout << max.first << endl;
 
    return 0;
}
 
 
/*
 
 
*/