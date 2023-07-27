#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("grave.in", "r", stdin);
    freopen("grave.out", "w", stdout);

    int x1, x2, y1, y2;
    int cx1, cx2, cy1, cy2;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> cx1 >> cy1 >> cx2 >> cy2;

    int w, h;
    cin >> w >> h;

    if(y2 - y1 >= h){
        if(x2 - cx2 >= w){
            cout << "Yes\n";
            return 0;;
        }
        if(cx1 - x1 >= w){
            cout << "Yes\n";
            return 0;;
        }
    }
    if(x2 - x1 >= w){
        if(y2 - cy2 >= h){
            cout << "Yes\n";
            return 0;;
        }

        if(cy1 - y1 >= h){
            cout << "Yes\n";
            return 0;;
        }
    }

    cout << "No\n";

    return 0;
}