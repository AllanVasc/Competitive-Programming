#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

typedef double ld;
const ld DINF = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-9;

#define sq(x) ((x)*(x))

bool eq(ld a, ld b) {
	return abs(a - b) <= eps;
}

struct pt { // ponto
	ld x, y;
	pt(ld x_ = 0, ld y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (!eq(x, p.x)) return x < p.x;
		if (!eq(y, p.y)) return y < p.y;
		return 0;
	}
	bool operator == (const pt p) const {
		return eq(x, p.x) and eq(y, p.y);
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const ld c) const { return pt(x*c  , y*c  ); }
	pt operator / (const ld c) const { return pt(x/c  , y/c  ); }
	ld operator * (const pt p) const { return x*p.x + y*p.y; }
	ld operator ^ (const pt p) const { return x*p.y - y*p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

struct line { // reta
	pt p, q;
	line() {}
	line(pt p_, pt q_) : p(p_), q(q_) {}
	friend istream& operator >> (istream& in, line& r) {
		return in >> r.p >> r.q;
	}
};

// PONTO & VETOR

ld dist(pt p, pt q) { // distancia
	return hypot(p.y - q.y, p.x - q.x);
}

ld dist2(pt p, pt q) { // quadrado da distancia
	return sq(p.x - q.x) + sq(p.y - q.y);
}

ld norm(pt v) { // norma do vetor
	return dist(pt(0, 0), v);
}

ld angle(pt v) { // angulo do vetor com o eixo x
	ld ang = atan2(v.y, v.x);
	if (ang < 0) ang += 2*pi;
	return ang;
}

ld sarea(pt p, pt q, pt r) { // area com sinal
	return ((q-p)^(r-q))/2;
}

bool col(pt p, pt q, pt r) { // se p, q e r sao colin.
	return eq(sarea(p, q, r), 0);
}

bool ccw(pt p, pt q, pt r) { // se p, q, r sao ccw
	return sarea(p, q, r) > eps;
}

pt rotate(pt p, ld th) { // rotaciona o ponto th radianos
	return pt(p.x * cos(th) - p.y * sin(th),
			p.x * sin(th) + p.y * cos(th));
}

pt rotate90(pt p) { // rotaciona 90 graus
	return pt(-p.y, p.x);
}

// RETA

bool isvert(line r) { // se r eh vertical
	return eq(r.p.x, r.q.x);
}

bool isinseg(pt p, line r) { // se p pertence ao seg de r
	pt a = r.p - p, b = r.q - p;
	return eq((a ^ b), 0) and (a * b) < eps;
}

ld get_t(pt v, line r) { // retorna t tal que t*v pertence a reta r
	return (r.p^r.q) / ((r.p-r.q)^v);
}

pt proj(pt p, line r) { // projecao do ponto p na reta r
	if (r.p == r.q) return r.p;
	r.q = r.q - r.p; p = p - r.p;
	pt proj = r.q * ((p*r.q) / (r.q*r.q));
	return proj + r.p;
}

pt inter(line r, line s) { // r inter s
	if (eq((r.p - r.q) ^ (s.p - s.q), 0)) return pt(DINF, DINF);
	r.q = r.q - r.p, s.p = s.p - r.p, s.q = s.q - r.p;
	return r.q * get_t(r.q, s) + r.p;
}

bool interseg(line r, line s) { // se o seg de r intersecta o seg de s
	if (isinseg(r.p, s) or isinseg(r.q, s)
		or isinseg(s.p, r) or isinseg(s.q, r)) return 1;

	return ccw(r.p, r.q, s.p) != ccw(r.p, r.q, s.q) and
			ccw(s.p, s.q, r.p) != ccw(s.p, s.q, r.q);
}

ld disttoline(pt p, line r) { // distancia do ponto a reta
	return 2 * abs(sarea(p, r.p, r.q)) / dist(r.p, r.q);
}

ld disttoseg(pt p, line r) { // distancia do ponto ao seg
	if ((r.q - r.p)*(p - r.p) < 0) return dist(r.p, p);
	if ((r.p - r.q)*(p - r.q) < 0) return dist(r.q, p);
	return disttoline(p, r);
}

ld distseg(line a, line b) { // distancia entre seg
	if (interseg(a, b)) return 0;

	ld ret = DINF;
	ret = min(ret, disttoseg(a.p, b));
	ret = min(ret, disttoseg(a.q, b));
	ret = min(ret, disttoseg(b.p, a));
	ret = min(ret, disttoseg(b.q, a));

	return ret;
}

/*
c - d
|   |
a - b
*/
struct Node{
    pt a, b, c, d;
    vector<line> v;
    Node(pt a, pt b, pt c, pt d) : a(a), b(b), c(c), d(d) {
        v.push_back(line(a, b));
        v.push_back(line(b, d));
        v.push_back(line(d, c));
        v.push_back(line(c, a));
    }
};
vector<Node> rect;

const int ms = 200;
double dp[ms];
int vis[ms];

double shortest(Node a, Node b){
    double best = INF;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            best = min(best, distseg(a.v[i], b.v[j]));
        }
    }
    return best;
}

double solve(int idx){
    int n = rect.size();
    if(idx == n - 1) return 0;
    if(vis[idx]) return dp[idx];

    double answ = INF;
    for(int i = idx  + 1; i < n; i++){
        answ = min(answ, shortest(rect[idx], rect[i]) + solve(i));
        // cout << "De " << idx << " ate " << i << " com dist igual a " << shortest(rect[idx], rect[i]) << '\n';
    }
    vis[idx] = true;
    return dp[idx] = answ;
}

ostream &operator << (ostream &os, const pt &p){
    return os << "(" << p.x << "," << p.y << ")";
}


signed main() {
    optimize;
    
    freopen("street.in", "r", stdin); // CHANGE
    
    int t; cin >> t;
    while(t--){
        int n, H, W;
        cin >> n >> H >> W;
        for(int i = 0; i < n; i++){
            int h, w, d, k;
            cin >> h >> w >> d >> k;
            if(!k){ // left
                pt lowerL(0, d), lowerR(w, d);
                pt upperL(0, d + h), upperR(w, d + h);
                rect.push_back(Node(lowerL, lowerR, upperL, upperR));
            }
            else{
                pt lowerL(W - w, d), lowerR(W, d);
                pt upperL(W - w, d + h), upperR(W, d + h);
                rect.push_back(Node(lowerL, lowerR, upperL, upperR));
            }
        }
        rect.push_back(Node(pt(0,-1), pt(W,-1), pt(0,0), pt(W, 0)));
        rect.push_back(Node(pt(0,H), pt(W, H), pt(0,H), pt(W, H)));

        sort(ALL(rect), [&](const Node & a, const Node & b){
            if(a.a.y != b.a.y) return a.a.y < b.a.y;
            return a.a.x < b.a.x;
        });
        // for(int i = 0; i < rect.size(); i++){
        //     cout << "i = " << i << ": ";
        //     cout << " a = " << rect[i].a << " ";
        //     cout << " b = " << rect[i].b << " ";
        //     cout << " c = " << rect[i].c << " ";
        //     cout << " d = " << rect[i].d << " ";
        //     cout << '\n';
        // }
        // cout << "De " << 5 << " ate " << 6 << " com dist igual a " << shortest(rect[5], rect[6]) << '\n';
        // cout << "segmento: " << rect[5].v[1] << " " << rect[5].v[2] << " ate " << rect[6].a << " = " << distPtSegment(rect[5].v[1], rect[5].v[2], rect[6].a) << '\n';
        for(int i = 0; i < rect.size(); i++){
            dp[i] = INF;
            vis[i] = false;
        }
        cout << setprecision(6) << fixed;
        cout << solve(0) << '\n';
        rect.clear();
    }

    return 0;
}