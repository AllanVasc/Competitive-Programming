#include <bits/stdc++.h>
using namespace std;

#define int long long

// Implementation of Knuth-Morris-Pratt algorithm
template<typename T>
struct KMP{
    T pattern;
    int m;
    vector<int> lps;

public:
    KMP(T pattern){
        m = pattern.size();
        this->pattern = pattern;
        get_lps();
    }

    vector<int> findPattern(T text){
        vector<int> matches;
        int n = text.size(), last = 0;
        for(int i = 0; i < n; i++){
            int j = last;
            while(j > 0 && (j >= m || text[i] != pattern[j]))
                j = lps[j - 1];
            
            last = (j < m && text[i] == pattern[j]) ? j + 1 : 0;
            if(last == m) matches.push_back(i - m + 1);
        }
        return matches;
    }

private:
    // Find Longest proper prefix which is also suffix
    void get_lps(){
        lps.assign(m, 0);
        for(int i = 1; i < m; i++){
            int j = lps[i - 1];
            while(j > 0 && pattern[i] != pattern[j])
                j = lps[j - 1];
            if(pattern[i] == pattern[j]) lps[i] = j + 1;
        }
    }
};

/*

Time Complexity

KMP -> O(n + m)

Links:

https://cp-algorithms.com/string/prefix-function.html
https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
https://www.youtube.com/watch?v=GTJr8OvyEVQ

*/