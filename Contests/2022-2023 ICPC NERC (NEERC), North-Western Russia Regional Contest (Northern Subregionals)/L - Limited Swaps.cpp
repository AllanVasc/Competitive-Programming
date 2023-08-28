#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> answ;

void printAnsw(bool inverted, int n){
    cout << answ.size() << '\n';
    for(auto x : answ){
        if(inverted){
            cout << (n - x - 1) << " ";
        }
        else{
            cout << (x + 1) << " ";
        }
    }
    cout << '\n';
}

bool solve(vector<int> & orig, vector<int> & final){
    int n = orig.size();
    vector<int> pos(n + 1, -1);
    for(int i = 0; i < n; i++) pos[orig[i]] = i;

    for(int i = n - 1; i >= 0; i--){
        int val = final[i];
        for(int j = pos[val]; j < i; j++){
            if(abs(orig[j] - orig[j + 1]) < 2){
                return false;
            }
            answ.push_back(j);
            int nxt = orig[j + 1];
            pos[nxt] = j;
            pos[val] = j + 1;
            swap(orig[j], orig[j + 1]);
        }
    }
    return true;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    bool debug = false;  // TIRAR AQ
    int n; cin >> n;
    vector<int> orig(n), final(n);
    for(int i = 0; i < n; i++) cin >> orig[i];
    for(int i = 0; i < n; i++) cin >> final[i];
    if(solve(orig, final)){
        if(debug) cout << "de prima" << '\n';
        printAnsw(false, n);
    }
    else{
        reverse(orig.begin(), orig.end());
        reverse(final.begin(), final.end());
        answ.clear();
        if(solve(orig, final)){
            printAnsw(true, n);
        }
        else{
            cout << -1 << '\n';
        }
    }
    return 0;
}