// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const double inf = 1e100, eps = 1e-12;
const double PI = acos(-1.0L);

// Struct to represent a point/vector
struct PT{
    int x, y;
    PT(int x = 0, int y = 0) : x(x), y(y) {}
    PT operator + (const PT &p) const { return PT(x + p.x, y + p.y); }
    PT operator - (const PT &p) const { return PT(x - p.x, y - p.y); }
    PT operator * (double c) const { return PT(x*c, y*c); }
    PT operator / (double c) const { return PT(x/c, y/c); }
    bool operator < (const PT &p) const {
        if(x != p.x) return x < p.x;
        return y < p.y;
    }
    bool operator == (const PT &p) const { return x == p.x && y == p.y; }
    bool operator != (const PT &p) const { return !(p == *this); }
};

// Debug function
ostream &operator << (ostream &os, const PT &p){
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

// Function to calculate the dot product (u.v)
int dot (PT p, PT q) { return p.x * q.x + p.y*q.y; }

// Function to calculate the cross product (uXv) (2x2 determinant)
int cross (PT p, PT q) { return p.x * q.y - p.y*q.x; }

vector<PT> convexHull(vector<PT>& p, bool needSort = 1){
    if(needSort) sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    int n = p.size(), k = 0;
    if(n <= 1) return p;
    vector<PT> answ(n + 2);   // Must be 2*n + 1 for collinear points

    // Lower hull
    for(int i = 0; i < n; i++){
        while(k >= 2 && cross(answ[k-1] - answ[k-2], p[i] - answ[k-2]) <= 0) k--; // If collinear points are allowed put only "<"
        answ[k++] = p[i];
    }

    // Upper hull
    for(int i = n - 2, t = k + 1; i >= 0; i--) {
        while(k >= t && cross(answ[k - 1] - answ[k - 2], p[i] - answ[k - 2]) <= 0) k--; // If collinear points are allowed put only "<"
        answ[k++] = p[i];
    }

    answ.resize(k-1); // n+1 points where the first is equal to the last
    return answ;
}

bool ptInSegment (PT a, PT b, PT c) { // ponto c esta em um segmento a - b
  if (a == b) return a == c;
  a = a-c, b = b-c;
  return cross(a, b) == 0 && dot(a, b) <= 0;
}

bool ptInsideTriangle(PT p, PT a, PT b, PT c) {
  if(cross(b-a, c-b) < 0) swap(a, b);
  if(ptInSegment(a,b,p)) return 1;
  if(ptInSegment(b,c,p)) return 1;
  if(ptInSegment(c,a,p)) return 1;
  bool x = cross(b-a, p-b) < 0;
  bool y = cross(c-b, p-c) < 0;
  bool z = cross(a-c, p-a) < 0;
  return x == y && y == z;
}

bool pointInConvexPolygon(const vector<PT> &p, PT q) {
  if (p.size() == 1) return p.front() == q;
  int l = 1, r = p.size()-1;
  while(abs(r-l) > 1) {
    int m = (r+l)/2;
    if(cross(p[m]-p[0] , q-p[0]) < 0) r = m;
    else l = m;
  }
  return ptInsideTriangle(q, p[0], p[l], p[r]);
}

// Determina se o ponto esta na borda do poligno
bool pointOnPolygon(const vector<PT> &p, PT q) {
  for(int i = 0; i < p.size(); i++)
    if(ptInSegment(p[i], p[(i + 1) % p.size()], q))
      return true;
    return false;
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<PT> nazi;
    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        nazi.push_back(PT(x,y));
    }

    int s;
    cin >> s;
    vector<PT> soviet;
    for(int i = 0; i < s; i++){
        int x, y;
        cin >> x >> y;
        soviet.push_back(PT(x,y));
    }

    vector<PT> ch = convexHull(nazi);

    int answ = 0;
    if(ch.size() >= 4){
        for(int i = 0; i < s; i++){
            if(pointInConvexPolygon(ch, soviet[i])){
                answ++;
            }
        }
    }
    else if(ch.size() == 3){  // ConvexHull formou um Triangulo, precisa ver se tem ponto interno
        bool valid = false;

        for(int i = 0; i < n; i++){
            if(!pointOnPolygon(ch, nazi[i])){
                valid = true;
            }
        }

        if(valid){
            for(int i = 0; i < s; i++){
                if(pointInConvexPolygon(ch, soviet[i])){
                    answ++;
                }
            }
        }
        else{
            vector<PT> inside;
            for(int i = 0; i < s; i++){
                if(pointInConvexPolygon(ch, soviet[i])){
                    inside.push_back(soviet[i]);
                }
            }

            // cout << "inside = " << '\n';
            // for(int i = 0; i < inside.size(); i++){
            //     cout << inside[i] << '\n';
            // }

            // cout << "convexzao = " << '\n';
            // for(int i = 0; i < ch.size(); i++){
            //     cout << ch[i] << '\n';
            // }

            vector<vector<PT>> triangulopracarai;

            for(int i = 0; i < ch.size(); i++){ // Construindo triangulos inválidos
                vector<PT> line_a;
                vector<PT> line_b;

                PT pivo = ch[i];
                PT ant = ch[((i-1)+3)%3];
                PT prox = ch[((i+1)%3)];
                
                for(int j = 0; j < n; j++){
                    if(nazi[j] == pivo) continue;
                    if(nazi[j] == ant) continue;
                    if(nazi[j] == prox) continue;

                    if(ptInSegment(pivo, ant, nazi[j])){
                        line_a.push_back(nazi[j]);
                    }
                    else if(ptInSegment(pivo, prox, nazi[j])){
                        line_b.push_back(nazi[j]);
                    }
                }

                if(line_a.size() == 0) continue;
                if(line_b.size() == 0) continue;

                sort(line_a.begin(), line_a.end(), [pivo](PT a, PT b){
                    return dot(a-pivo, a-pivo) < dot(b-pivo, b-pivo);
                });

                sort(line_b.begin(), line_b.end(), [pivo](PT a, PT b){
                    return dot(a-pivo, a-pivo) < dot(b-pivo, b-pivo);
                });
                

                // cout << "seg_A " << '\n';
                // for(int j = 0; j < line_a.size(); j++){
                //     cout << line_a[j] << '\n';
                // }

                // cout << "seg_b " << '\n';
                // for(int j = 0; j < line_b.size(); j++){
                //     cout << line_b[j] << '\n';
                // }

                vector<PT> triangle;
                triangle.push_back(pivo);
                triangle.push_back(line_a.front());
                triangle.push_back(line_b.front());

                triangulopracarai.push_back(triangle);
            }

            if(!triangulopracarai.empty()){
                for(int i = 0; i < inside.size(); i++){
                    bool in = false;

                    for(auto triangle : triangulopracarai){
                        if(ptInSegment(triangle[1], triangle[2], inside[i])){
                            in = true;
                        }
                        if(!ptInsideTriangle(inside[i], triangle[0], triangle[1], triangle[2])){
                            in = true;
                        }
                    }
                    answ += in;
                }
            }
        }
    }

    cout << answ << '\n';

    return 0;
}