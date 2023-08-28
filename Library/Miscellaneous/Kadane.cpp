#include <bits/stdc++.h>
using namespace std;

#define int long long

// Kadane's Algorithm (Works in array's that have only negative numbers)
int kadane(int n, vector<int> &v){
    int answ = 0;   // If possible be an empty subarray
    int curr = 0;
    for(int i = 0; i < n; i++){
        curr = max(v[i], curr + v[i]); // We have two option, ours current sum is actually starting at v[i] or is the sum of previous subarray + v[i]
        answ = max(answ, curr);
    }
    return answ;
}

// Kadane circular array (Method 1)
int maxCircularSumMethod1(int n, vector<int> &v){

    // Ours answer don't have the corners (Just need to use Kadane)
    int max_kadane = kadane(n, v);

    // if maximum sum using standard kadane is less than 0
    if(max_kadane < 0)
      return max_kadane;
 
    // Ours answer can have the corners
    int max_wrap = 0;

    for(int i = 0; i < n; i++) {
        max_wrap += v[i];   // Calculate array-sum
        v[i] = -v[i];       // invert the array (change sign)
    }
 
    // Max sum with corner elements will be:
    // array-sum - (-max subarray sum of inverted array)
    max_wrap = max_wrap + kadane(n, v);
 
    // The maximum circular sum will be maximum of two sums
    return max(max_wrap, max_kadane);
}

// Kadane circular array (Method 2)
int maxCircularSumMethod2(int n, vector<int> &v){

    // Corner Case
    if (n == 1)
        return v[0];
 
    // Initialize sum variable which store total sum of the array.
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += v[i];
    }
 
    // Initialize every variable with first value of array.
    int bestMax = v[0];
    int currSumMax = v[0];

    int bestMin = v[0];
    int currSumMin = v[0];
 
    // Concept of Kadane's Algorithm
    for (int i = 1; i < n; i++) {
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

Kadane's Algorithm -> O(n)

Links:

https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
https://www.geeksforgeeks.org/maximum-contiguous-circular-sum/

*/