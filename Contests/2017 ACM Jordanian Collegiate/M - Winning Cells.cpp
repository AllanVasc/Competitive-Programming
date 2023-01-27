//M - Winning Cells
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
	ll n,k; cin >> n >> k;
	ll ans = n*n - 1LL;
	
	//PA => start=n-(k+1), razao= -(k+1)
	ll razao = k+1LL;
	ll a1 = n - (k+1LL);
	ll qtd = a1 / razao;
	
	ll an = a1 - qtd*razao;
	
	ans -= (a1+an)*(n/razao);
	//cout << a1 << " " << an << " " << qtd <<" "<< (a1+an)*qtd<<endl;
	ans -= n-1LL;
	
	cout << ans << endl;
	
		
return;
/*
30
40
52
66
82
100
 
 
	
	int mat[100][100]; memset(mat, 1, sizeof(mat));
	for (int i = 0;  i < 100; i++) for (int j = 0; j < 100; j++) mat[i][j] = 1;
	
	for (int i = 0; i < n; i+=k+1){
		for (int j = 0; i+j < n && j < n; j++){
			mat[i+j][j] = 2;		
		}
		
	}
	mat[0][0] = 0;
	int ans =n*n - 1, tt=0;
	for (int i = 0; i < n; i++){
		
		for (int j = 0; j < i; j++)
			{
				if (mat[i][j]==2) tt++;
			}
		
	}
	ans -= tt*2;
	
	for (int i = 0;  i < n; i++) for (int j = 0; j <= i; j++) cout << mat[i][j] << " \n"[j==i];
	
	cout << ans - (n-1) << endl;
	*/
}
 
int prestart(){
	int t; cin >> t; return t;
	return 1;
}
 
int32_t main(){
	freopen("chess.in","r",stdin);
	ios::sync_with_stdio(false), cin.tie(0);
	int t = prestart();
	for (int i = 1; i <= t; i++){
		//cout << "Case #" << i << ": ";
		start();
	}
	
	return 0;
}