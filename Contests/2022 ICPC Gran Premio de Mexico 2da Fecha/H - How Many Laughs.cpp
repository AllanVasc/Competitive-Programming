#include <bits/stdc++.h>
using namespace std;

#define int long long

void bruteforce(vector<int>& numbers, int x){
    vector<bool> marked(x + 1, false);
    for(auto cur : numbers){
        for(int j = cur; j <= x; j += cur){
            marked[j] = true;
        }
    }
    int answ = 0;
    for(int i = 0; i < marked.size(); i++) if(marked[i]) answ++;
    cout << "BRUTE: " << answ << '\n';
}

int gcd(int x, int y){
    if(x == 0) return y;
    return gcd(y % x, x);
}

int mmc(int x, int y){
    return x * y / gcd(x, y);
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> numbers(n);
    for(int i = 0; i < n; i++){
        cin >> numbers[i];
    }

   //  bruteforce(numbers, x);

    int answ = 0;
    for(int mask = 1; mask < (1 << n); mask++){
        int check = __builtin_popcount(mask);
        
        int val = 1;
        for(int j = 0; j < n; j++){
            if(mask & (1 << j)){
                val = mmc(val, numbers[j]);
                if(val > x) break;
            }
        }
        if(val > x) continue;
        
        if(check % 2 == 1){
            answ += x / val;
        }
        else{
            answ -= x / val;
        }
    }

    cout << answ << '\n';
    return 0;
}