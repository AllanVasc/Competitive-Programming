// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;
const int MOD = 1e9 + 7;

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        priority_queue<int> pq_a, pq_b;

        for(int i = 0; i < n; i++){
            int aux;
            cin >> aux;
            pq_a.push(aux);
        }

        for(int i = 0; i < n; i++){
            int aux;
            cin >> aux;
            pq_b.push(aux);
        }

        int answ = 0;
        while(!pq_a.empty()){
            int n1 = pq_a.top();
            pq_a.pop();

            int n2 = pq_b.top();
            pq_b.pop();

            if(n1 == n2) continue;
            answ++;
            if(n1 > n2){
                n1 = (int) log10(n1) + 1;
            }
            else{
                n2 = (int) log10(n2) + 1;
            }
                pq_a.push(n1);
                pq_b.push(n2);
        }

        cout << answ << '\n';
    }
    return 0;
}