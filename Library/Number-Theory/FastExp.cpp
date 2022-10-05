#include <bits/stdc++.h>
using namespace std;

#define int long long
using ll = long long;

// Fast Modular Exponentiation
int fastModExp(int x, int y, int p){
    int ans = 1;
    x = x % p;      // Update 'x' if it is more than or equal to 'p'
    if (x == 0) return 0;   // In case 'x' is divisible by 'p';
    while(y){ // We walk through the bits of power "y"
        if (y & 1) ans = (ans*x) % p; // If the least significant bit is set, we multiply the answer by "x"
        y = y >> 1; // We walk to the next bit
        x = (x*x) % p;
    }
    return ans;
}

/*

Time Complexity

fastModExp  -> O(logy)

Links:

https://www.youtube.com/watch?v=HN7ey_-A7o4
https://www.youtube.com/watch?v=-3Lt-EwR_Hw
https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/

*/