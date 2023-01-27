//G - WiFi Password
#include <bits/stdc++.h>
#define ll long long
#define x first
#define y second
#define pb push_back
#define ii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define si set<int>
using namespace std;
 
 
const int maxn = 1000005;
//PLACE CODE UNDER PASTEFLAG
//SegmentTree.cpp
int cell[maxn], tree[4*maxn];
 
void build(int pos, int i, int j){
	int mid = (i+j)/2;
	int esq = pos*2;
	int dir = pos*2 + 1;
	if (i==j){
		tree[pos] = cell[i];
		return;
	}
	build(esq, i, mid);
	build(dir, mid+1, j);
	
	tree[pos] = tree[esq] | tree[dir];
}
 
int query(int pos, int i, int j, int l, int r){
	int mid = (i+j)/2;
	int esq = pos*2;
	int dir = pos*2 + 1;
	
	if (j < l || i > r){
		return 0;
	}
	if (i >= l && j <= r){
		return tree[pos];
	}
	
	return query(esq, i, mid, l, r) | query(dir, mid+1, j, l, r);
}
 
//PrintVector.cpp
template <class T>
void printN(T &vec){
	for (auto it = vec.begin(); it != vec.end(); it++){
		cout << *it;
		it++; cout << " \n"[it==vec.end()]; it--;
	}
}
 
//ReadVector.cpp
template <class T>
void readN(T &vec){
	for (auto &it : vec) cin >> it;
}
 
//IMPORTED CODE ABOVE
 
int MX,N;
 
bool check(int k){
	
	for (int i = 0; i+k <= N; i++){
		if (query(1, 1, N, i+1, i+k) <= MX) return true;
	}
	
	return false;
}
 
void start(){
	cin >> N >> MX; vi vec(N); readN(vec);
	for (int i = 0; i < N; i++){
		cell[i+1] = vec[i];
	}
	build(1,1,N);
	
	//cout << query(1, 1, N, 1, N) << endl;
	
	int l = 1, r = N;
	while(l<r){
		int m = (l+r+1)/2;
		if(check(m)) l=m;
		else r=m-1;
	}
	
	cout << (check(r) ? r : 0) << endl;
}
 
int prestart(){
	int t; cin >> t; return t;
	return 1;
}
 
int32_t main(){//wifi.in
	freopen("wifi.in","r",stdin);
	ios::sync_with_stdio(false), cin.tie(0);
	int t = prestart();
	for (int i = 1; i <= t; i++){
		//cout << "Case #" << i << ": ";
		start();
	}
	
	return 0;
}