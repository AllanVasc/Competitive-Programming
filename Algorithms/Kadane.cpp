#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> v;

// Kadane’s Algorithm (Works in array's that have only negative numbers)
ll kadane(int size){

    ll best = 0;
    ll currSum = 0;

    for(int i = 0; i < size; i++){

        // We have two option, ours current sum is actually starting at v[i] or is the sum of previous subarray + v[i]
        currSum = max(v[i],currSum + v[i]);

        // Ours answer is the max between the previously answer or the current sum
        best = max(best,currSum);

    }

    return best;

}

// Kadane circular array (Method 1)
ll maxCircularSumMethod1(int size){

    // Ours answer don't have the corners (Just need to use Kadane)
    ll max_kadane = kadane(size);

    // if maximum sum using standard kadane' is less than 0
    if(max_kadane < 0)
      return max_kadane;
 
    // Ours answer can have the corners
    ll max_wrap = 0;

    for(int i = 0; i < size; i++) {
        max_wrap += v[i];   // Calculate array-sum
        v[i] = -v[i];       // invert the array (change sign)
    }
 
    // Max sum with corner elements will be:
    // array-sum - (-max subarray sum of inverted array)
    max_wrap = max_wrap + kadane(size);
 
    // The maximum circular sum will be maximum of two sums
    return max(max_wrap, max_kadane);
}

// Kadane circular array (Method 2)
ll maxCircularSumMethod2(int size){

    // Corner Case
    if (size == 1)
        return v[0];
 
    // Initialize sum variable which store total sum of the array.
    ll totalSum = 0;
    for (int i = 0; i < size; i++) {
        totalSum += v[i];
    }
 
    // Initialize every variable with first value of array.
    ll bestMax = v[0];
    ll currSumMax = v[0];

    ll bestMin = v[0];
    ll currSumMin = v[0];
 
    // Concept of Kadane's Algorithm
    for (int i = 1; i < size; i++) {
        // Kadane's Algorithm to find Maximum subarray sum.
        currSumMax = max(v[i], currSumMax + v[i]);
        bestMax = max(bestMax, currSumMax);
 
        // Kadane's Algorithm to find Minimum subarray sum.
        currSumMin = min(v[i], currSumMin + v[i]);
        bestMin = min(bestMin, currSumMin);
    }
    
    // All values are negative, just return bestMax
    if (bestMin == totalSum)
        return bestMax;
 
    // Else, we will calculate the maximum value
    return max(bestMax, totalSum - bestMin);
}

/*

Time Complexity

Kadane’s Algorithm -> O(n)

Links:

https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
https://www.geeksforgeeks.org/maximum-contiguous-circular-sum/

*/