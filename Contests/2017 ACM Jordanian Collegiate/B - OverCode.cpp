//B. OverCode
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
 
bool check(deque<int>& vec){
	int sz = (int)vec.size();
	if (sz != 6) return false;
	
	for (auto x : vec){
		for (auto y : vec){
			if (abs(x-y) > 1000) return false;
		}
	}
	
	
	return true;
}
 
void start(){
 
	int n; cin >> n;
	vi vec(n); readN(vec);
	
	sort(vec.begin(), vec.end());
	
	int tot = 0;
	
	while(!vec.empty()){
		bool used = false;
		int team = 0; int sz = (int)vec.size();
		deque<int> teamv;
		for (int i = 0; i < min(6,sz); i++){
			teamv.pb(vec[i]);
		}
		
		used = check(teamv);
		
		for (int i = 6; !used && i < sz; i++){
			teamv.pop_front();
			teamv.pb(vec[i]);
			used = check(teamv);
			team = i-5;
		}
		
		if (used){
			vi newArr;
			tot++;
			for (int i = 0; i < team; i++) newArr.pb(vec[i]);
			for (int i = team+6; i < sz; i++) newArr.pb(vec[i]);
			
			vec = newArr;
		}else break;
		
		//printN(vec);
	}
	
	
	cout << tot << endl;
}
 
int prestart(){
	int t; cin >> t; return t;
	return 1;
}
 
int32_t main(){
	freopen("overcode.in","r",stdin);
	ios::sync_with_stdio(false), cin.tie(0);
	int t = prestart();
	for (int i = 1; i <= t; i++){
		//cout << "Case #" << i << ": ";
		start();
	}
	
	return 0;
}