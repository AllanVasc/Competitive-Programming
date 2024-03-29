#include <bits/stdc++.h>
using namespace std;

#define int long long

// Implementation of Z-function algorithm
struct ZFunction{
    vector<int> z;
    int n, patSz = -1;

    ZFunction(string str, string pattern = ""){ // Initializing
        if(!pattern.empty()){
            str = pattern + "$" + str;
            patSz = pattern.size();
        }
        n = str.size();
        z.assign(n, 0);

        int l = 0, r = 0;
        for(int i = 1; i < n; i++){ // Z-function
            if(i <= r){
                z[i] = min(r - i + 1, z[i - l]);
            }
            while(i + z[i] < n && str[z[i]] == str[i + z[i]]) z[i]++;
            if(i + z[i] - 1 > r){
                l = i;
                r = i + z[i] - 1;
            }
        }
    }

    vector<int> findPattern(){
        vector<int> answ;
        for(int i = 0; i < n; i++){
            if(z[i] == patSz) answ.push_back(i - patSz - 1);
        }
        return answ;
    }
};

/*

Time Complexity:

Z-function -> O(N)

Links:

https://cp-algorithms.com/string/z-function.html#efficient-algorithm-to-compute-the-z-function
https://www.youtube.com/watch?v=CpZh4eF8QBw

*/