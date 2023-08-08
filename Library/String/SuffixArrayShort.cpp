#include <bits/stdc++.h>
using namespace std;

// O(nlogn)
vector<int> suffix_array(string & s){
    s += '$';
    int n = s.size();
    int cntSz = max(n, 260);
    vector<int> sa(n), rnk(n);
    for(int i = 0; i < n; i++) sa[i] = i, rnk[i] = s[i];

    for(int k = 0; k < n; k ? k *= 2 : k++){
        vector<int> nsa(sa), nrnk(n), cnt(cntSz);

        for(int i = 0; i < n; i++) nsa[i] = (nsa[i] - k + n) % n, cnt[rnk[i]]++;
        for(int i = 1; i < cntSz; i++) cnt[i] += cnt[i - 1];
        for(int i = n - 1; i >= 0; i--) sa[--cnt[rnk[nsa[i]]]] = nsa[i];

        for(int i = 1, r = 0; i < n; i++){
            r += rnk[sa[i]] != rnk[sa[i - 1]] || rnk[(sa[i] + k) % n] != rnk[(sa[i - 1] + k) % n];
            nrnk[sa[i]] = r;
        }
        rnk = nrnk;
        if(rnk[sa[n - 1]] == n - 1) break;
    }
    return sa;
}

// Kasai lcp O(n)
// lcp[i] = lcp(sa[i], sa[i + 1]) 
vector<int> kasai(string & s, vector<int> & sa){
    int n = s.size(), h = 0;
    vector<int> rnk(n), lcp(n);
    for(int i = 0; i < n; i++) rnk[sa[i]] = i;
    for(int i = 0; i < n; i++){
        if(rnk[i] == n - 1) { h = 0; continue; }
        int nxt = sa[rnk[i] + 1];
        while(i + h < n && nxt + h < n && s[i + h] == s[nxt + h]) h++; // && s[i + h] != separator, if needed
        lcp[rnk[i]] = h;
        if(h) h--;
    }
    return lcp;
}