#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

typedef struct Node * pNode;
struct Node{
    int key, priority, sz;
    int answ;
    bool rev;
    pNode lc, rc;
    Node(){}
    Node(int x){ // add key if not implicit
        key = x;
        answ = key;
        priority = uniform_int_distribution<int>()(rng);
        sz = 1;
        rev = 0;
        lc = rc = NULL;
    }
};

int size(pNode it){ return it ? it->sz : 0; }
int answer(pNode it){ return it ? it->answ : 0; }

void upd_sz(pNode it){
    if(it){
        it->sz = size(it->lc) + size(it->rc) + 1;
        it->answ = answer(it->lc) + answer(it->rc) + it->key;
    }
}

void pushLazy(pNode it){
    if(it && it->rev){
        it->rev = false;
        swap(it->lc, it->rc);
        if(it->lc) it->lc->rev ^= 1;
        if(it->rc) it->rc->rev ^= 1;
    }
}

// Split Treap "t" in t1 = l and t2 = r by value "key"
void split(pNode t, pNode & l, pNode & r, int key){
    if(!t) return void(l = r = 0);
    pushLazy(t);
    int cur_key = size(t->lc); // cur_key = t->key if not implicit
    if(key <= cur_key){
        split(t->lc, l, t->lc, key);
        r = t;
    }
    else{
        split(t->rc, t->rc, r, key - (1 + size(t->lc))); // key if not implicit
        l = t;
    }
    upd_sz(t);
}

// Merge treap "l" and "r" in "t".
// It works under the assumption that "l" and "r"
// are ordered (all keys in "l" are smaller than keys in "r")
void merge(pNode & t, pNode l, pNode r){
    pushLazy(l), pushLazy(r);
    if(!l || !r) t = (l ? l : r);
    else if(l->priority > r->priority){
        merge(l->rc, l->rc, r);
        t = l;
    }
    else{
        merge(r->lc, l, r->lc);
        t = r;
    }
    upd_sz(t);
}

void insert(pNode & t, pNode it){
    if(!t) t = it;
    else if(it->priority > t->priority){
        split(t, it->lc, it->rc, it->key);
        t = it;
    }
    else{
        insert(t->key <= it->key ? t->rc : t->lc, it);
    }
}

void reverse(pNode t, int l, int r){
    pNode t1, t2, t3;
    split(t, t1, t2, l);
    split(t2, t2, t3, r - l + 1);
    t2->rev ^= 1;
    merge(t, t1, t2);
    merge(t, t, t3);
}

void debugTreap(pNode t, int depth = 0) {
    if(!t) return;
    pushLazy(t);
    debugTreap(t->lc, depth + 1);
    cout << "dep = " << depth << "[" << (t->key) << "," << (t->answ) << "] ";
    debugTreap(t->rc, depth + 1);
}

int32_t main() {
    optimize;
    
    int n, m;
    cin >> n >> m;

    pNode treap = NULL;
    for(int i = 0; i < n; i++){
        int curr; cin >> curr;
        pNode it = new Node(curr);
        pNode tl, tr;
        split(treap, tl, tr, i);
        merge(treap, tl, it);
        merge(treap, treap, tr);
    }

    // debugTreap(treap); cout << '\n';
    // cout << "total = " << answer(treap) << '\n';
    for(int i = 0; i < m; i++){
        int cmd, l , r;
        cin >> cmd >> l >> r;
        l--, r--;
        if(cmd == 1){
            reverse(treap, l, r);
        }
        else{
            pNode t1,t2,t3;
            split(treap, t1, t2, l);
            split(t2, t2, t3, r - l + 1);
            cout << answer(t2) << '\n';
            merge(treap, t1, t2);
            merge(treap, treap, t3);
        }
    }
    return 0;
}