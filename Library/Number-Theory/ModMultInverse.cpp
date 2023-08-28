#include <bits/stdc++.h>
using namespace std;

#define int long long

// If we know MOD is prime, then we can use Fermats's little theorem to find the inverse. 
int ModMultInv(int n){ return fastModExp(n, MOD-2, MOD); }

/*

Time Complexity:

ModMultInv -> O(logMOD)

Links:

https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/

*/