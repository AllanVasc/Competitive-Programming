// C - Minimum Extraction
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n; 
        cin >> n;

        priority_queue <ll, vector<ll>, greater<ll> > pq;

        for(int i = 0; i < n; i++){
            ll aux;
            cin >> aux;
            pq.push(aux);
        }

        ll count = 0;
        ll answer = LONG_LONG_MIN;

        if(n == 1){
            cout << pq.top() << '\n';
        }
        else{

            while(pq.size() != 1){
                
                ll aux = pq.top() - count;
                pq.pop();

                answer = max(answer, aux);

                count += aux;
            }

            answer = max(answer, pq.top() - count);

            cout << answer << '\n';
        }
    }

    return 0;
}