#include <bits/stdc++.h>
using namespace std;

#define int long long

// Fast Modular Exponentiation
int fastModExp(int x, int y, int m){
    int ans = 1;
    x = x % m;      // Update 'x' if it is more than or equal to 'm'
    while(y){ // We walk through the bits of power "y"
        if(y & 1) ans = (ans*x) % m; // If the least significant bit is set, we multiply the answer by "x"
        y = y >> 1; // We walk to the next bit
        x = (x*x) % m;
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

Obs.: 
We can reduce the exponent using Fermat’s Little Theorem.
Example: a^(b^c), we can say that (b^c) = x*(m - 1) + y, then a^(b^c) = a^y. Being y = (b^c) % (m - 1)

*/