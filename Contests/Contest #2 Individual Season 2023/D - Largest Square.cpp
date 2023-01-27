#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> ps;
vector<vector<int>> v;

void build(){
    int n = v.size();
    ps.assign(n + 1, vector<int>(n + 1, 0));
    ps[1][1] = v[0][0];
 
    for (int i = 1; i < n; i++)
        ps[0 + 1][i + 1] = ps[0 + 1][i - 1 + 1] + v[0][i];
    for (int i = 1; i < n; i++)
        ps[i + 1][0 + 1] = ps[i - 1 + 1][0 + 1] + v[i][0];
 
    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
            ps[i + 1][j + 1] = ps[i - 1 + 1][j + 1] + ps[i + 1][j - 1 + 1]  - ps[i - 1 + 1][j - 1 + 1] + v[i][j];
}

int range_query(int i_1, int j_1, int i_2, int j_2){
    return ps[i_2][j_2] - ps[i_1-1][j_2] - ps[i_2][j_1-1] + ps[i_1-1][j_1-1];
}

bool check(int len_window, int max_b){

    int n = v.size();
    // cout << "size = " << len_window << '\n';
    
    for(int i = 0; i < n - len_window + 1; i++){
        int curr = 0;
        for(int j = 0; j < n - len_window + 1; j++){
            curr = range_query(i + 1, j + 1, i + len_window - 1 + 1, j + len_window - 1 + 1);
            if(curr <= max_b) return true;
            // cout << i << " " << j << " ate " << i + len_window - 1 << " " << j + len_window - 1 << " deu = " << curr << '\n';
        }

        // if(curr <= max_b) return true;
    }

    return false;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n,w,l;
        cin >> n >> w >> l;

        v.assign(n, vector<int>(n, 0));
        for(int i = 0; i < w; i++){
            int a, b;
            cin >> a >> b;
            v[a-1][b-1] = 1;
        }
        build();

        int left = 1;
        int right = n;
        int answ = 0;

        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         cout << v[i][j] << " ";
        //     }
        //     cout << '\n';
        // }

        // cout << "bit" << "\n";
        // for(int i = 0; i < n + 1; i++){
        //     for(int j = 0; j < n + 1; j++){
        //         cout << ps[i][j] << " ";
        //     }
        //     cout << '\n';
        // }

        // check(0, l);

        // cout << range_query(0,0,0,0) << '\n';
        // cout << range_query(0,0,3,3) << '\n';
        // cout << range_query(1,1,1,1) << '\n';
        

        // check(1, l);
        // check(2, l);
        // check(3, l);
        // check(4, l);

        while(left <= right){

            int mid = left + (right - left)/2;
            if(check(mid,l)){
                answ = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        
        cout << answ*answ << '\n';
    }
    return 0;
}