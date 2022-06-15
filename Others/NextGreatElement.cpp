#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 0x3f3f3f3f;
using ii = pair<int,int>;
using ll = long long;

const int N = 1e5; // Number of elements

vector<ll> v;

// NGE's answer from all elements in vector "v"
vector<ii> nxt(N,{inf,N});

// Find the Next Great Element for all array elements
// If an element does not exist it is defined as {inf, n}
void NGE(int n){

    // Push the first element {element, idx}
    stack<pair<ll,ll>> s;
    s.push({v[0],0});
 
    // Iterate for rest of the elements
    for (int i = 1; i < n; i++){
 
        if (s.empty()) {    // If the stack is empty just push the next element
            s.push({v[i],i});
            continue;
        }

        // if stack is not empty and the popped element is smaller than next (keep popping)
        while (s.empty() == false && s.top().first < v[i]){
            nxt[s.top().second] = {v[i],i};
            s.pop();
        }
 
        // Push "next" to stack so that we can find NGE for him
        s.push({v[i],i});
    }
 
    // The remaining elements in stack don't have NGE
    while (s.empty() == false) {
        nxt[s.top().second] = {inf,n};
        s.pop();
    }
}

// NGE with the fastest implementation using PGE's logic
// If an element does not exist it is defined as {inf, n}
void NGE(int n){

    // Push the first element {element, idx}
    stack<pair<ll,ll>> s;
    s.push({inf,n});    // The first element must be this

    // Traverse remaining elements (in reverse order of PGE)
    for(int i = n-1; i >= 0; i--){
 
        while (s.empty() == false && s.top().first < v[i])
            s.pop();
 
        if(s.empty())
            nxt[i] = {inf,n};
        else
            nxt[i] = {s.top().first, s.top().second};
 
        s.push({v[i],i});
    }
}

/*

Time Complexity

NGE -> O(n)

Links:

https://www.geeksforgeeks.org/next-greater-element/

*/