#include <bits/stdc++.h>
using namespace std;
  
#define int long long

struct SparseTable{
    int n, LOG;
    vector<vector<int>> st;
    vector<int> lg2;
    int type;
    
    SparseTable(vector<int>& v, int type) : type(type) {
        n = v.size();
        LOG = 25;
        st.assign(LOG, vector<int>(n, 0));
        lg2.assign(n + 1, 0);

        for(int i = 0; i < n; i++) st[0][i] = v[i];
        for(int i = 2; i <= n; i++) lg2[i] = lg2[i/2] + 1;

        for(int i = 1; i < LOG; i++){
            for(int j = 0; j + (1 << i) - 1 < n; j++){
                st[i][j] = func(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int func(int x, int y){
        if(type == 0) return x + y;
        else if(type == 1) return min(x, y);
        else return max(x, y);
    }

    int query(int l, int r){
        if(type == 0){
            int answ = 0;
            for(int i = LOG - 1; i >= 0; i--){
                if((1 << i) <= r - l + 1){
                    answ += st[i][l];
                    l += (1 << i);
                }
            }
            return answ;
        }
        else{
            int i = lg2[r - l + 1];
            return func(st[i][l], st[i][r - (1 << i) + 1]);
        }
    }

    void update(int idx, int val){
        st[0][idx] = val;
        int k = 1;
        for(int i = 1; i < LOG; i++){
            for(int j = max(0LL, idx - 2*k + 1); (j <= idx) && (j + (1 << i) - 1 < n); j++){
                st[i][j] = func(st[i - 1][j], st[i - 1][j + k]);
            }
            k *= 2;
        }
    }
};

/*

Time Complexity:

Build       -> O(n*logn)
QuerySum    -> O(logn)
QueryMin    -> O(1)
QueryMax    -> O(1)
QueryGCD    -> O(1)
Update      -> We don't use!

Links:

https://cp-algorithms.com/data_structures/sparse-table.html
https://www.youtube.com/watch?v=0jWeUdxrGm4

*/