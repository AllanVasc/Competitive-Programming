//  G - K-th Number 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

const int MAXN = 100000 + 100;

vector<int> segTree[4*MAXN];
vector<int> v(MAXN,0);
// Time Complexity: O(N log N)
// Memory Complexity: O(N log N) extra space
void build(int p, int l, int r){
    if(l == r){
        segTree[p] = vector<int>(1, v[l]);
    }
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        build(lc,l,m);
        build(rc,m+1,r);

        merge(segTree[lc].begin(), segTree[lc].end(), 
              segTree[rc].begin(), segTree[rc].end(),
              back_inserter(segTree[p]));
    }
}

// Time Complexity: O(Log N * Log N)
int query(int p, int l, int r, int ql, int qr, int x){
    if(ql <= l && r <= qr){
        return upper_bound(segTree[p].begin(), segTree[p].end(), x) - segTree[p].begin();
    }
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        if(qr <= m){
            return query(lc,l,m,ql,qr, x);
        }
        else if(ql > m){
            return query(rc,m+1,r,ql,qr, x);
        }
        else{
            int left = query(lc,l,m,ql,qr, x);
            int right = query(rc,m+1,r,ql,qr, x);

            return left + right;
        }
    }
}

int search(int n, int ql, int qr, int k){
    int l = -1e9 - 100;
    int r = 1e9 + 100;

    int answer;
    while(l <= r){
        int m = l + (r-l)/2;

        if(query(1,1,n,ql,qr,m) >= k){
            answer = m;
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    return answer;
}

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,q;
    cin >> n >> q;
    
    for(int i = 0; i < n; i++) cin >> v[i+1];

    build(1,1,n);

    for(int i = 0; i < q; i++){
        int ql,qr,k;
        cin >> ql >> qr >> k;
        
        cout << search(n,ql,qr,k) << '\n';
    }

    return 0;
}
