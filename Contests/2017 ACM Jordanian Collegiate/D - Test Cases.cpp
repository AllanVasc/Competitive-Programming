//D - Test Cases
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
 
//PLACE CODE UNDER PASTEFLAG
 
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
 
bool mp[1000005];
 
int check(const int& k, vi& vec){
	int n = (int)vec.size(), sz = 0, ans = 0;
	
	for (int i = 0; i < k; i++){
		mp[vec[i]] = !mp[vec[i]];
		sz += (mp[vec[i]]) ? 1 : -1;
	}
	ans+=(sz == 1);
	
	for (int i = k; i < n; i++){
		mp[vec[i-k]] = !mp[vec[i-k]];
		mp[vec[i]] = !mp[vec[i]];
		
		if (vec[i-k]!=vec[i]){
			sz += (mp[vec[i]]&1) ? 1 : -1;
			sz += (mp[vec[i-k]]&1) ? 1 : -1;
		}
		
		ans+=(sz == 1);
	}
 
	return ans;	
}
 
void start(){
	int n; scanf("%d",&n); vi vec(n);
	
	for (int i = 0; i < n; i++){
		scanf("%d",&vec[i]);
	}
 
	
	//(n/2 -1) * n
	//The total sum of n overall test cases doesn't exceed 72000.
	/*
		14*(2499 * 5000) + 2000*999
		176928000
	*/
	int ans = n;
	for (int k = 3; k <= n; k+=2){
		memset(mp,0,sizeof(mp));
		int cc = check(k, vec);
		ans += cc;
		//printf("%d => %d\n", k ,cc);
	}
	printf("%d\n", ans);
}
 
int prestart(){
	int t; scanf("%d",&t); return t;
	return 1;
}
 
int32_t main(){
	freopen("cases.in","r",stdin);
	ios::sync_with_stdio(false), cin.tie(0);
	int t = prestart();
	for (int i = 1; i <= t; i++){
		//cout << "Case #" << i << ": ";
		start();
	}
	
	return 0;
}