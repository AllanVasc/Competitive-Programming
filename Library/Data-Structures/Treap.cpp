#include <bits/stdc++.h>
using namespace std;

#define int long long
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef struct Node * pNode;
struct Node{
    int key, priority, sz;
    bool rev;
    pNode lc, rc;
    Node(){}
    Node(int x){
        key = x;
        priority = uniform_int_distribution<int>()(rng);
        sz = 1;
        rev = 0;
        lc = rc = NULL;
    }
};

int size(pNode it){ return it ? it->sz : 0; }

void upd_sz(pNode it){
    if(it) it->sz = size(it->lc) + size(it->rc) + 1;
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

// Only works when not an Implicit Treap
// To insert in a Implicit Treap use split + merge
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

// Needs to change when using Implicit Treap
void erase(pNode & t, int key){
    if(t->key == key){
        pNode th = t;
        merge(t, t->lc, t->rc);
        delete th;
    }
    else{
        erase(key < t->key ? t->lc : t->rc, key);
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

void unite(pNode & t, pNode l, pNode r){
    if(!l || !r) return void( t = l ? l : r );
    if(l->priority < r->priority) swap(l, r);
    pNode lt, rt;
    split(r, lt, rt, l->key);
    unite(l->lc, l->lc, lt);
    unite(l->rc, l->rc, rt);
    t = l;
}

pNode kth_element(pNode t, int k) {
    if(!t) return NULL;
    if(t->lc) {
        if(t->lc->sz >= k) return kth_element(t->lc, k);
        else k -= t->lc->sz;
    }
    return (k == 1) ? t : kth_element(t->rc, k - 1);
}

// Show an array that corresponds to the current state of the implicit treap
void debugTreap(pNode t) {
    if(!t) return;
    pushLazy(t);
    debugTreap(t->lc);
    cout << t->key << " ";
    debugTreap(t->rc);
}

/*

Time Complexity:

Split   -> O(logn)
Merge   -> O(logn)
unite   -> O(m*log(n/m))

Links:

https://cp-algorithms.com/data_structures/treap.html
https://usaco.guide/adv/treaps?lang=cpp
https://www.youtube.com/watch?v=6x0UlIBLRsc
https://www.youtube.com/watch?v=erKlLEXLKyY

*/