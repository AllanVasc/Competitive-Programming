//A. Chrome Tabs
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
 
void start(){
 
	int n,k; cin >> n >> k;
	
	if (n==1){
		cout << "0\n";return;
	}
	
	if (n==k || k==1){
		cout << "1\n";return;
	}
	cout << "2\n";return;
}
 
int prestart(){
	int t; cin >> t; return t;
	return 1;
}
 
int32_t main(){
	freopen("tabs.in","r",stdin);
	//ios::sync_with_stdio(false), cin.tie(0);
	int t = prestart();
	for (int i = 1; i <= t; i++){
		//cout << "Case #" << i << ": ";
		start();
	}
	
	return 0;
}