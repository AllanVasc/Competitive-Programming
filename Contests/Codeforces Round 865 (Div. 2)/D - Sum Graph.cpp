#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

void putEdge(int x){
    cout << "+ " << x << endl;
    int answ;
    cin >> answ;
    assert(answ == 1);
}

int ask(int i, int j){
    cout << "? " << i << " " << j << endl;
    int answ;
    cin >> answ;
    assert(answ != -2);
    return answ;
}

void output(vector<int>& answ1, vector<int>& answ2){
    cout << "! ";
    for(auto x : answ1) cout << x << " ";
    for(auto x : answ2) cout << x << " ";
    cout << endl;
    int answ;
    cin >> answ;
    assert(answ == 1);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        if(n == 2){
            vector<int> answ1 = {1, 2};
            vector<int> answ2 = {2, 1};
            output(answ1, answ2);
        }
        else{
            putEdge(n + 1);
            putEdge(n + 2);

            vector<int> chain;
            int start = 1;
            int end = n;
            for(int i = 0; i < n; i++){
                if(i % 2 == 0){
                    chain.push_back(start);
                    start++;
                }
                else{
                    chain.push_back(end);
                    end--;
                }
            }

            // cout << "chain: ";
            // for(auto x : chain) cout << x << " ";
            // cout << endl;

            int endpointPos = 0;
            int mxDist = 0;
            for(int i = 2; i <= n; i++){
                int aux = ask(1, i);
                if(aux > mxDist){
                    mxDist = aux;
                    endpointPos = i - 1;
                }
            }

            vector<int> answ1(n, -1);
            vector<int> answ2(n, -1);
            answ1[endpointPos] = chain[0];
            answ2[endpointPos] = chain[n - 1];
            // cout << "pos = " << endpointPos << " = " << chain[0] << " ou " << chain[n - 1];
            for(int i = 1; i <= n; i++){
                if(i == endpointPos + 1) continue;
                int dist = ask(endpointPos + 1, i);
                answ1[i - 1] = chain[0 + dist];
                answ2[i - 1] = chain[n - 1 - dist];
            }

            output(answ1, answ2);
        }
    }
    return 0;
}