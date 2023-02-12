#include <bits/stdc++.h>
using namespace std;
  
#define int long long
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;
 
struct PT{
    int x, y;
};
 
int sq(const int & x){
    return x * x;
}
 
int dist(const PT& a, const PT& b){
    return sq(a.x - b.x) + sq(a.y - b.y);
}
// Divide & Conquer Algorithm
// This solution is O(n*log^2(n))
// To achieve O(n*logn) We pass a vector sorted by "x" 
// and another already sorted by "y" 
// and at each recursion call we pass the same points.
int closestPair(vector<PT> points){
    int n = points.size();
 
    int dmin = 8*1e18;
    // Base Case
    if(n <= 3){
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                dmin = min(dmin, dist(points[i], points[j]));
        return dmin;
    }
 
    // Divide
    vector<PT> left(points.begin(), points.begin() + n/2);
    vector<PT> right(points.begin() + n/2, points.end());
    int dl = closestPair(left);
    int dr = closestPair(right);
    dmin = min(dl, dr);
 
    // Stripe
    vector<PT> stripe;
    for(auto curr : left){
        PT mid = points[n/2];
        if( sq(curr.x - mid.x) < dmin){
            stripe.push_back(curr);
        }
    }
    for(auto curr : right){
        PT mid = points[n/2];
        if( sq(curr.x - mid.x) < dmin){
            stripe.push_back(curr);
        }
    }
 
    sort(stripe.begin(), stripe.end(), [&](const PT& a, const PT& b){
        return a.y < b.y;
    });
 
    // For each point, we just need to look at 7 nexts
    for(int i = 0; i < stripe.size(); i++){
        // This inner loop is O(1)
        for(int j = i + 1; j < stripe.size() && sq(stripe[j].y - stripe[i].y) < dmin; j++){
            dmin = min(dmin, dist(stripe[i], stripe[j]));
        }
    }
 
    return dmin;
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
 
    int n;
    cin >> n;
 
    vector<PT> points(n);
    for(auto &aux : points) cin >> aux.x >> aux.y;
    
    sort(points.begin(), points.end(), [&](const PT& a, const PT& b){
        return a.x < b.x;
    });
    cout << closestPair(points) << '\n';
    return 0;
}