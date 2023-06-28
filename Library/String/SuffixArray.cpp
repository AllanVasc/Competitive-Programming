#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>

class SuffixArray{
public:
    string text;
    vector<int> sa;
    vector<int> rank;
    vector<int> lcp;

    void process(string & s){
        text = s;
        text += '$';
        int n = text.size();
        sa.resize(n);
        rank.resize(n);

        vector<pii> list;
        for(int i = 0; i < n; i++){
            list.push_back({text[i], i});
        }
        sort(list.begin(), list.end());
        for(int i = 0; i < n; i++) sa[i] = list[i].second;
        rank[sa[0]] = 0;
        int classe = 0;
        for(int i = 1; i < n; i++){
            if(text[sa[i]] != text[sa[i - 1]]) classe++;
            rank[sa[i]] = classe;
        }
        
        int k = 1;
        while(k < n){
            vector<int> aux(n);
            vector<int> count(n, 0);
            for(int i = 0; i < n; i++) count[rank[i]]++;
            for(int i = 1; i < n; i++) count[i] += count[i - 1];
            for(int i = n - 1; i >= 0; i--){
                int idx = (sa[i] - k + n) % n;
                aux[count[rank[idx]] - 1] = idx;
                count[rank[idx]]--;
            }
            swap(sa, aux);
            aux[sa[0]] = 0;
            classe = 0;
            for(int i = 1; i < n; i++){
                if(rank[sa[i]] != rank[sa[i - 1]] ||
                   rank[(sa[i] + k) % n] != rank[(sa[i - 1] + k) % n]){
                    classe++;
                }
                aux[sa[i]] = classe;
            }
            swap(rank, aux);
            k += k;
        }

        // lcp O(n)
        // lcp[i] = lcp(sa[i], sa[i - 1])
        lcp.assign(n, 0);
        int h = 0;
        for(int i = 0; i < n; i++) rank[sa[i]] = i;
        for(int i = 0; i < n; i++){
            if(rank[i]){
                k = sa[rank[i] - 1];
                while(text[i + h] == text[k + h]) h++;
                lcp[rank[i]] = h;
                if(h) h--;
            }
        }
    }

    bool find(string & pat){
		int l = 0;
		int r = sa.size() - 1;
        for(int i = 0; i < pat.size(); i++){
            int st = l;
            int en = r;
            int answ = text.size();
            while(st <= en){
                int m = (st + en) >> 1;
                int idx = sa[m];
                if(text[idx + i] >= pat[i]){
                    if(text[idx + i] == pat[i]){
                        answ = min(answ, m);
                    }
                    en = m - 1;
                }
                else{
                    st = m + 1;
                }
            }
            if(answ == text.size()) return false;
            l = answ;
            st = answ;
            en = r;
            while(st <= en){
                int m = (st + en) >> 1;
                int idx = sa[m];
                if(text[idx + i] <= pat[i]){
                    if(text[idx + i] == pat[i]){
                        answ = max(answ, m);
                    }
                    st = m + 1;
                }
                else{
                    en = m - 1;
                }
            }
            r = answ;
        }
        return true;
    }
};

/*

Time Complexity:

process -> O(nlogn)
find    -> O(|pat|logn)

Links:

https://www.youtube.com/watch?v=Lu5sByCfPvE
https://usaco.guide/adv/suffix-array?lang=cpp
https://codeforces.com/edu/course/2/lesson/2/1

*/