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
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        bool possible = true;
        vector<int> p(n, -1);
        vector<int> q(n, -1);
        map<int, int> freq_p;
        map<int,int> freq_q;

        priority_queue<ii, vector<ii>, greater<ii>> pq;
        for(int i = 0; i < n && possible; i++){
            if(freq_p[a[i]] == 0){
                if(a[i] > n) possible = false;
                p[i] = a[i];
                freq_p[a[i]]++;
            }
            else{
                if(freq_q[a[i]] == 0){
                    if(a[i] > n) possible = false;
                    q[i] = a[i];
                    freq_q[a[i]]++;
                    pq.push({q[i], i});
                }
                else{
                    possible = false;
                }
            }
        }

        // cout << "primeira atrib" << '\n';
        // cout << "p = ";
        // for(int i = 0; i < n; i++) cout << p[i] << " ";
        // cout << "\n";
        // cout << "q = ";
        // for(int i = 0; i < n; i++) cout << q[i] << " ";
        // cout << "\n";

        // Colocando resto em "P"
        int minvalue = 1;
        while(!pq.empty() && possible){
            auto [value, pos] = pq.top();
            pq.pop();
            while(freq_p[minvalue]) minvalue++;

            if(p[pos] == -1){
                if(minvalue > n){
                    possible = false;
                }
                if(minvalue > q[pos]) possible = false;
                p[pos] = minvalue;
                freq_p[minvalue]++;
            }
        }

        // tava errado

        // for(int i = 0; i < n && possible; i++){
        //     while(freq_p[minvalue]) minvalue++;
        //     if(p[i] == -1){
        //         if(minvalue > n){
        //             possible = false;
        //         }
        //         if(minvalue > q[i]) possible = false;
        //         p[i] = minvalue;
        //     }
        // }

        // cout << "perm p final: ";
        // for(int i = 0; i < n; i++) cout << p[i] << " ";
        // cout << '\n';
        // if(!possible) cout << "ja deu merda" << '\n';

        for(int i = 0; i < n; i++){
            pq.push({p[i], i});
        }

        int min_used_q = 1;
        while(!pq.empty() && possible){
            auto [value, pos] = pq.top();
            pq.pop();
            while(freq_q[min_used_q]) min_used_q++;

            if(q[pos] == -1){
                if(min_used_q > n){
                    possible = false;
                }
                if(min_used_q > p[pos]) possible = false;
                q[pos] = min_used_q;
                freq_q[min_used_q]++;
            }
        }

        if(possible){
            cout << "YES" << '\n';
            for(int i = 0; i < n; i++) cout << p[i] << " ";
            cout << '\n';
            for(int i = 0; i < n; i++) cout << q[i] << " ";
            cout << '\n';
        }
        else{
            cout << "NO" << '\n';
        }

    }
    return 0;
}