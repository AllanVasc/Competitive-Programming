#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e6;
const int block = sqrt(MAXN);  // Block size

// Ordering based on the Hilbert curve
inline int64_t hilbertOrder(int x, int y, int pow, int rotate){
    if(pow == 0) return 0;
    int hpow = 1 << (pow - 1);
    int seg = (x < hpow) ? ( (y < hpow) ? 0 : 3) : ( (y < hpow) ? 1 : 2);
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (2*pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = hilbertOrder(nx, ny, pow - 1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}

struct Query{
    int l, r, idx;
    int64_t ord;
    Query(int l, int r, int idx) : l(l), r(r), idx(idx) {
        ord = hilbertOrder(l, r, 21, 0);
    }
    bool operator < (Query &other){
        return ord < other.ord;
    }
};

vector<Query> queries;
int v[MAXN], answ[MAXN], curr_answ;

// Need to change the current answer according to the problem
void add(int x){}
void remove(int x){}

// Mo's Algorithm to answer offline queries
void Mo(){
    int curr_l = 0, curr_r = -1;
    sort(queries.begin(), queries.end());
    for(Query q : queries){
        while(curr_l > q.l){
            curr_l--;
            add(curr_l);
        }
        while(curr_r < q.r){
            curr_r++;
            add(curr_r);
        }
        while(curr_l < q.l){
            remove(curr_l);
            curr_l++;
        }
        while(curr_r > q.r){
            remove(curr_r);
            curr_r--;
        }
        answ[q.idx] = curr_answ;
    }
}

/*

Time Complexity

Mo's using Hilbert  -> O( N * sqrt(Q) )

Links:

https://cp-algorithms.com/data_structures/sqrt_decomposition.html
https://www.youtube.com/watch?v=RENzmNgIZ4A&t=1s
https://codeforces.com/blog/entry/61203

*/