#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e6;
const int block = sqrt(MAXN);  // Block size

struct Query{
    int l, r, idx;
    Query(int l, int r, int idx) : l(l), r(r), idx(idx) {}
    bool operator < (Query &other){
        if(l / block != other.l / block) return (l / block) < (other.l / block);
        return (l / block & 1) ? (r < other.r) : (r > other.r);
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

Mo's Algorithm  -> O( (N + Q) * sqrt(N) * F ) Where F is the complexity of add and remove function.

Links:

https://cp-algorithms.com/data_structures/sqrt_decomposition.html
https://www.youtube.com/watch?v=RENzmNgIZ4A&t=1s

*/