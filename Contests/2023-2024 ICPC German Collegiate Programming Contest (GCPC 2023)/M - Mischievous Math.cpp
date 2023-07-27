#include<bits/stdc++.h>
using namespace std;

#define int long long
bool check3(int a, int b, int c, int d){
    if((a + b + c) == d) return true;
    if((a + b - c) == d) return true;
    if((a + (b * c)) == d) return true;
    if(((a + b) * c) == d) return true;
    if(b % c == 0 && (a + (b / c) == d)) return true;
    if((a + b) % c == 0 && ( ((a + b) / c) == d)) return true;
    
    if(a - b + c == d) return true;
    if(a - b - c == d) return true;
    if(a - (b * c) == d) return true;
    if((a - b) * c == d) return true;
    if(b % c == 0 && (a - (b / c) == d)) return true;
    if((a - b) % c == 0 && ((a - b) / c == d)) return true;

    if(a * (b + c) == d) return true;
    if((a * b) + c == d) return true;
    if(a * (b - c) == d) return true;
    if((a * b) - c == d) return true;
    if(a * b * c == d) return true;
    if((a * b) % c == 0 && (a * b / c == d)) return true;

    if(a % (b + c) == 0 && (a / (b + c) == d)) return true;
    if(a % b == 0 && ((a / b) + c == d)) return true;
    if(a % (b - c) == 0 && (a / (b - c) == d)) return true;
    if(a % b == 0 && ((a / b - c) == d)) return true;
    if(a % b == 0 && (a / b * c == d)) return true;
    if(a % b == 0 && ((a / b) % c == 0) && (a / b / c == d)) return true;

    return false;
}

bool check2(int x, int y, int d){
    if(x + y == d) return true;
    if(x - y == d) return true;
    if(x * y == d) return true;
    if(x % y == 0 && (x  / y == d)) return true;

    return false;
}
bool check1(int x, int d){
    if(x == d) return true;
    return false;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n; cin >> n;
    
    tuple<int,int,int> answ = {-1, -1, -1};
    for(int a = 1; a <= 100; a++){
        for(int b = a + 1; b <= 100; b++){
            for(int c = b + 1; c <= 100; c++){
                bool found = false;
                found |= check3(a, b, c, n);
                found |= check3(a, c, b, n);
                found |= check3(b, a, c, n);
                found |= check3(b, c, a, n);
                found |= check3(c, a, b, n);
                found |= check3(c, b, a, n);

                found |= check2(a, b, n);
                found |= check2(b, a, n);
                found |= check2(a, c, n);
                found |= check2(c, a, n);
                found |= check2(b, c, n);
                found |= check2(c, b, n);

                found |= check1(a, n);
                found |= check1(b, n);
                found |= check1(c, n);
                if(!found){
                    answ = {a, b, c};
                   // cout << a << " " << b << " " << c << '\n';
                }
            }
        }
    }

    auto [a, b, c] = answ;
    cout << a << " " << b << " " << c << '\n';
    assert(a != -1);
    return 0;
}