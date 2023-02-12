#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, k, x , y;
        cin >> n >> k >> x >> y;

        vector<int> team_a(k, -INF);
        vector<int> team_b(k, -INF);

        priority_queue<int> pq_a, pq_b;
        for(int i = 0; i < n; i++){
            char team;
            int value;
            cin >> team >> value;
            if(team == 'A') pq_a.push(value);
            else pq_b.push(value);
        }

        int cnt_a = 0;
        while(!pq_a.empty() && cnt_a != k){
            int value = pq_a.top();
            pq_a.pop();
            team_a[cnt_a] = value;
            cnt_a++;
        }
        
        int cnt_b = 0;
        while(!pq_b.empty() && cnt_b != k){
            int value = pq_b.top();
            pq_b.pop();
            team_b[cnt_b] = value;
            cnt_b++;
        }

        bool sorted_b = false;
        if(cnt_b == k){
            sort(team_b.begin(), team_b.end());
            cnt_b = 0;
            sorted_b = true;
        }
        while(!pq_a.empty() && cnt_b != k){
            int value = pq_a.top() - x;
            pq_a.pop();
            if(team_b[cnt_b] < value){
                team_b[cnt_b] = value;
                cnt_b++;
            }
            else{
                break;
            }
            if(!sorted_b && cnt_b == k){
                sort(team_b.begin(), team_b.end());
                cnt_b = 0;
                sorted_b = true;
            }
        }

        bool sorted_a = false;
        if(cnt_a == k){
            sort(team_a.begin(), team_a.end());
            cnt_a = 0;
            sorted_a = true;
        }
        while(!pq_b.empty() && cnt_a != k){
            int value = pq_b.top() - y;
            pq_b.pop();
            if(team_a[cnt_a] < value){
                team_a[cnt_a] = value;
                cnt_a++;
            }
            else{
                break;
            }
            if(!sorted_a && cnt_a == k){
                sort(team_a.begin(), team_a.end());
                cnt_a = 0;
                sorted_a = true;
            }
        }

        int answ = 0;
        for(int i = 0; i < k; i++){
            answ += team_a[i];
            answ += team_b[i];
        }
        cout << answ << '\n';
    }

    return 0;
}