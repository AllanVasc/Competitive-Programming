#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 0x3f3f3f3f;
using ii = pair<int,int>;
using ll = long long;

const int N = 1e5; // Number of elements

vector<ll> v;

// PGE's answer from all elements in vector "v"
vector<ii> pre(N,{inf,-1});

// Find the previous great element for all array elements
// If an element does not exist it is defined as {inf,-1}
void PGE(int n){

    // Push the first element {element, idx}
    stack<pair<ll,ll>> s;
    s.push({v[0],0});
     
    // Traverse remaining elements
    for(int i = 1; i < n; i++){
 
        // Pop elements from stack while stack is not empty
        // and top of stack is smaller than arr[i]. We
        // always have elements in decreasing order in a
        // stack.
        while (s.empty() == false && s.top().first < v[i])
            s.pop();
 
        // If stack becomes empty, then no element is greater
        // on left side. Else top of stack is previous
        // greater.
        if(s.empty())
            pre[i] = {inf,-1};
        else
            pre[i] = {s.top().first, s.top().second};
 
        s.push({v[i],i});
    }
}

/*

Time Complexity

PGE -> O(n)

Links:

https://www.geeksforgeeks.org/previous-greater-element/

*/