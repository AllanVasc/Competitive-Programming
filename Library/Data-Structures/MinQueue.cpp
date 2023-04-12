#include <bits/stdc++.h>
using namespace std;
  
#define int long long

struct MinQueue{
    queue<int> q;
    deque<int> mins;

    void push(int x){
        q.push(x);
        while(!mins.empty() && mins.back() > x){
            mins.pop_back();
        }
        mins.push_back(x);
    }

    void pop(){
        if(q.empty()) return;
        int x = q.front();
        q.pop();
        if(mins[0] == x) mins.pop_front();
    }

    int min(){
        return mins[0];
    }
};

/*

Time Complexity

push    -> O(1)
pop     -> O(1)
min     -> O(1)

Links:

https://cp-algorithms.com/data_structures/stack_queue_modification.html

*/