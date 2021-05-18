#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> v;

// Longest Increasing Subsequence (Bottom-Up approach)
ll lis(int size){

    ll dp[size];

    for(int i = 0; i < size; i++){

        // Everyone has at least 1 solution that is just having himself in the sequence
        dp[i] = 1;

        for(int j = 0; j < i; j++){

            // If there is a smaller value before the "i" position, we have to know if it is in the sequence or not
            if(v[j] < v[i]){
                // We have 2 solutions for the answer, do not put v[j] or put v[j].
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return dp[size-1];

}

/*

Time Complexity

lis -> O(n^2)

Links:

https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/

*/