#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Fast Modular Exponentiation
ll mod_power(ll x,ll y,ll p){

    ll ans = 1;     // Initialize answer
 
    x = x % p;      // Update 'x' if it is more than or equal to 'p'
  
    if (x == 0) 
        return 0;   // In case 'x' is divisible by 'p';
 
    while(y){

        // If 'y' is odd, multiply 'x' with answer
        if (y & 1)
            ans = (ans*x) % p;
 
        // y must be even now ('y' = 'y'/2)
        y = y >> 1;
        x = (x*x) % p;
    }
    return ans;
}

/*

Time Complexity

mod_power   -> O(log y)

Links:

https://www.youtube.com/watch?v=-3Lt-EwR_Hw
https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/

*/