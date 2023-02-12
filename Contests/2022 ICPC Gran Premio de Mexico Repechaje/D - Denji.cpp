#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

class multi_indexed_set{

    tree<pair<long long, long long>, null_type, less<pair<long long, long long>>, rb_tree_tag,
	    tree_order_statistics_node_update> miset;
    unordered_map<long long, long long> freq;

    public:
	void insert(long long x){
	    freq[x]++;
	    miset.insert({x, freq[x]});
	}
	void erase(long long x){
	    if(!freq[x]) return;
	    miset.erase({x, freq[x]});
	    freq[x]--;
	}
	long long order_of_key(long long x){ return miset.order_of_key({x, 0}); }
	long long count(long long x) { return freq[x]; }
	long long size(){ return miset.size(); }

};

multi_indexed_set ms;
const long long MAXN = 1e5 + 100;
long long arr[MAXN];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long q;
    cin >> q;
    for(int op = 0; op < q; op++){
        long long cmd;
        cin >> cmd;

        // cout << "arr: ";
        // for(long long i = 0; i < cnt; i++){
        //     if(arr[i] == INF) cout << "X" << " ";
        //     else cout << arr[i] << " "; 
        // }
        // cout << '\n';

        if(cmd == 1){
            long long val;
            cin >> val;
            ms.insert(val);
            arr[op] = val;
        }
        else if(cmd == 2){
            long long pos;
            cin >> pos;
            long long val = arr[pos - 1];
            ms.erase(val);
            arr[pos - 1] = -1;
        }
        else if(cmd == 3){
            long long pos, add;
            cin >> pos >> add;
            long long val = arr[pos - 1];
            ms.erase(val);

            long long new_val = val + add;
            // assert(new_val >= 0);
            arr[pos - 1] = new_val;
            ms.insert(new_val);
        }
        else{
            long long pos;
            cin >> pos;
            long long val = arr[pos - 1];
            cout << ms.order_of_key(val) << '\n';
        }
    }
    
    return 0;
}