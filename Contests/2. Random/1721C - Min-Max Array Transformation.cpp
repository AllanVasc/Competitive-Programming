// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a,b;
        a.assign(n, 0);
        b.assign(n, 0);

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        priority_queue<int> pq;
        for(int i = 0; i < n; i++){
            pq.push((-1)*b[i]);
        }

        vector<int> answ_min;
        for(int i = 0; i < n; i++){
            int aux = pq.top();
            aux = abs(aux);
            pq.pop();
            if(a[i] <= aux){
                answ_min.push_back(aux - a[i]);
                pq.push((-1)*aux);
            }
            else{
                i--;
            }
        }

        vector<int> answ_max;
        int a_count = 0;
        int b_count = 0;
        for(int i = n-1; i >= 0; i--){
            a_count++;
            auto point = lower_bound(b.begin(), b.end(), a[i]);
            int idx = point - b.begin();
            b_count = (b.size() - idx);

            answ_max.push_back(b.back() - a[i]);
            if(a_count == b_count){
                while(a_count){
                    b.pop_back();
                    a_count--;
                }
            }
        }

        reverse(answ_max.begin(), answ_max.end());

        for(int i = 0; i < n; i++){
            cout << answ_min[i] << " ";
        }
        cout << '\n';

        for(int i = 0; i < n; i++){
            cout << answ_max[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}