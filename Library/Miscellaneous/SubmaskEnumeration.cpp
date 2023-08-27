#include <bits/stdc++.h>
using namespace std;

#define int long long

void enumerate(int mask){
    for(int s = mask; ; s = (s - 1) & mask){
        // you can use submask "s"
        if(s == 0) break;
    }
}

/*

Time Complexity:

enumerate -> O(2^k) Being "k" the amount of active bits in mask
enumerate all masks -> O(3^n)

Links:

https://cp-algorithms.com/algebra/all-submasks.html

*/