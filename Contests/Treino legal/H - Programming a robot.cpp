//  H - Programming a robot
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;
 
long double distance(int x, int y){
    return sqrt((x-0)*(x-0) + (y-0)*(y-0));
}
 
int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int xo,yo;
    char e;
    cin >> xo >> yo >> e;
 
    int xd,yd;
    cin >> xd >> yd;
 
    int answ = 0;
    vector<pair<char,int>> v;
 
    while(!(xo == xd && yo == yd)){
 
        // cout << "pos: " << xo << " " << yo << '\n';
 
        if(e == 'N'){   // Norte
            //cout << "norte:" << '\n';
            if(yd > yo){
                //cout << "andei frente" << '\n'; 
                answ++;
                v.push_back({'A', yd-yo});
                yo = yd;
            }
            if(yo != yd || xd != xo){
                //cout << "virei -> E" << '\n';
                answ++;
                v.push_back({'D', 0});
                e = 'E';
            }
        }
        else if(e == 'E'){   // Leste
            //cout << "leste:" << '\n';
            if(xd > xo){
                //cout << "andei frente" << '\n';
                answ++;
                v.push_back({'A', xd-xo});
                xo = xd;
            }
            if(yo != yd || xd != xo){
                //cout << "virei -> S" << '\n';
                answ++;
                v.push_back({'D',0});
                e = 'S';
            }
        }
        else if(e == 'S'){   // Sul
            //cout << "sul:" << '\n';
            if(yd < yo){
                //cout << "andei frente" << '\n';
                answ++;
                v.push_back({'A', abs(yd-yo)});
                yo = yd;
            }
            if(yo != yd || xd != xo){
                //cout << "virei -> O" << '\n';
                answ++;
                v.push_back({'D',0});
                e = 'O';
            }
        }
        else if(e == 'O'){   //Oeste
            //cout << "oeste:" << '\n';
            if(xd < xo){
                //cout << "andei frente" << '\n';
                answ++;
                v.push_back({'A', abs(xd-xo)});
                xo = xd;
            }
            if(yo != yd || xd != xo){
                //cout << "virei -> N" << '\n';
                answ++;
                v.push_back({'D', 0});
                e = 'N';
            }
        }
    }
 
    cout << answ << '\n';
    for(int i = 0; i < v.size(); i++){
        if(v[i].first == 'D') cout << "D" << '\n';
        else{
            cout << v[i].first << " " << v[i].second << '\n';
        }
    }
 
    return 0;
}
