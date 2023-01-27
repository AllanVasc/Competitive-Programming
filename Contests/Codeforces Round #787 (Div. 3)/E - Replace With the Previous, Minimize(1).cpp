// E - Replace With the Previous, Minimize
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int N = 26; // Number of vertex

// Disjoint Set Union implementation using array (0-Based)
int parent[N];

// Function used to initialize Disjoint Set
void Build(){
    for(int i = 0; i < N; i++){
        parent[i] = i;
    }
}

// Returns the representative of the set that contains the element "v" (Path Compression Optimization)
int Find(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = Find(parent[v]);
}

// Joins two different sets (Union by Size Optimization)
void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) {
        if (b < a)
            swap(a, b);
        parent[b] = a;
    }
}

int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    ll t;
 
    cin >> t;
 
    while(t--){

        ll n,k; 
        cin >> n >> k;

        string s;
        cin >> s;

        Build();

        for(int i = 0; i < n; i++){
            
            s[i] = Find(s[i]- 'a') + 'a';

            if(s[i] == 'a')
                continue;
            
            while(k != 0 && s[i] != 'a'){

                Union(s[i]- 'a', s[i] - 'a' - 1);
                s[i] = Find(s[i]- 'a') + 'a';
                k--;
            }
    
        }
        cout << s << '\n';
    }
 
    return 0;
}
