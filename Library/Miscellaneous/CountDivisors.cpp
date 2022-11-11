#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 1e6 + 10;
vector<int> count_div(ms, 0);

// Preprocesses the number of divisors from all numbers up to ms
void countDivisors(){
    for(int i = 1; i < ms; i++){
        for(int j = i; j < ms; j += i){
            count_div[j]++;
        }
    }
}

/*

Time Complexity

countDivisors  -> O(n*logn) n = ms

Obs.: 
If we have a very large number we need to use another algorithm that runs on O(n^(1/3))

*/