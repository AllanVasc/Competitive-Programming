// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long

using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

typedef double ld;
const ld PI = acos(-1);

struct Complex {
    ld real, imag;
    Complex conj() { return Complex(real, -imag); }
    Complex(ld a = 0, ld b = 0) : real(a), imag(b) {}
    Complex operator + (const Complex &o) const { return Complex(real + o.real, imag + o.imag); }
    Complex operator - (const Complex &o) const { return Complex(real - o.real, imag - o.imag); }
    Complex operator * (const Complex &o) const { return Complex(real * o.real - imag * o.imag, real * o.imag + imag * o.real); }
    Complex operator / (ld o) const { return Complex(real / o, imag / o); }
    void operator *= (Complex o) { *this = *this * o; }
    void operator /= (ld o) { real /= o, imag /= o; }
};

typedef vector<Complex> CVector;
const int ms = 1 << 22;
int bits[ms];
Complex root[ms];

// Start by calling this function
void initFFT() {
    root[1] = Complex(1);
    for(int len = 2; len < ms; len += len) {
        Complex z(cos(PI / len), sin(PI / len));
        for(int i = len / 2; i < len; i++) {
            root[2 * i] = root[i];
            root[2 * i + 1] = root[i] * z;
        }
    }
}

void pre(int n) {
    int LOG = 0;
    while(1 << (LOG + 1) < n) {
        LOG++;
    }
    for(int i = 1; i < n; i++) {
        bits[i] = (bits[i >> 1] >> 1) | ((i & 1) << LOG);
    }
}

CVector fft(CVector a, bool inv = false) {
    int n = a.size();
    pre(n);
    if(inv) {
        reverse(a.begin() + 1, a.end());
    }
    for(int i = 0; i < n; i++) {
        int to = bits[i];
        if(to > i) {
            swap(a[to], a[i]);
        }
    }
    for(int len = 1; len < n; len *= 2) {
        for(int i = 0; i < n; i += 2 * len) {
            for(int j = 0; j < len; j++) {
                Complex u = a[i + j], v = a[i + j + len] * root[len + j];
                a[i + j] = u + v;
                a[i + j + len] = u - v;
            }
        }
    }
    if(inv) {
        for(int i = 0; i < n; i++)
            a[i] /= n;
    }
    return a;
}

// NTT
void fft2in1(CVector &a, CVector &b) {
    int n = (int) a.size();
    for(int i = 0; i < n; i++) {
        a[i] = Complex(a[i].real, b[i].real);
    }
    auto c = fft(a);
    for(int i = 0; i < n; i++) {
        a[i] = (c[i] + c[(n-i) % n].conj()) * Complex(0.5, 0);
        b[i] = (c[i] - c[(n-i) % n].conj()) * Complex(0, -0.5);
    }
}

// NTT
void ifft2in1(CVector &a, CVector &b) {
    int n = (int) a.size();
    for(int i = 0; i < n; i++) a[i] = a[i] + b[i] * Complex(0, 1);
    a = fft(a, true);
    for(int i = 0; i < n; i++) {
        b[i] = Complex(a[i].imag, 0);
        a[i] = Complex(a[i].real, 0);
    }
}

// NTT
vector<long long> mod_mul(const vector<long long> &a, const vector<long long> &b, long long cut = 1 << 15) {
    int n = (int) a.size();
    CVector C[4];
    for(int i = 0; i < 4; i++) C[i].resize(n);
    for(int i = 0; i < n; i++) {
        C[0][i] = a[i] % cut;
        C[1][i] = a[i] / cut;
        C[2][i] = b[i] % cut;
        C[3][i] = b[i] / cut;
    }
    fft2in1(C[0], C[1]);
    fft2in1(C[2], C[3]);
    for(int i = 0; i < n; i++) {
        // 00, 01, 10, 11
        Complex cur[4];
        for(int j = 0; j < 4; j++) cur[j] = C[j/2+2][i] * C[j % 2][i];
        for(int j = 0; j < 4; j++) C[j][i] = cur[j];
    }
    ifft2in1(C[0], C[1]);
    ifft2in1(C[2], C[3]);
    vector<long long> ans(n, 0);
    for(int i = 0; i < n; i++) {
        // if there are negative values, care with rounding
        ans[i] += (long long) (C[0][i].real + 0.5);
        ans[i] += (long long) (C[1][i].real + C[2][i].real + 0.5) * cut;
        ans[i] += (long long) (C[3][i].real + 0.5) * cut * cut;
    }
    return ans;
}

// Function to perform the multiplication of polynomials
vector<int> mul(const vector<int> &a, const vector<int> &b) {
    int n = 1;
    while (n - 1 < (int) a.size() + (int) b.size() - 2) n += n;
    CVector poly(n);
    for(int i = 0; i < n; i++) {
        if(i < (int) a.size()) {
            poly[i].real = a[i];
        }
        if(i < (int) b.size()) {
            poly[i].imag = b[i];
        }
    }
    poly = fft(poly);
    for(int i = 0; i < n; i++) {
        poly[i] *= poly[i];
    }
    poly = fft(poly, true);
    vector<int> c(n, 0);
    for(int i = 0; i < n; i++) {
        c[i] = (int) (poly[i].imag / 2 + 0.5);
    }
    while (c.size() > 0 && c.back() == 0) c.pop_back();
    return c;
}

int32_t main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;

    initFFT();

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n+1, 0);
        for(int i = 0; i <= n; i++){
            cin >> a[i];
        }

        vector<int> b(n+1, 0);
        for(int i = 0; i <= n; i++){
            cin >> b[i];
        }

        vector<int> result = mul(a,b);

        for(int i = 0; i < 2*n + 1; i++){
            if(i < result.size()) cout << result[i] << " ";
            else cout << 0 << " ";
        }
        cout << '\n';
    }
    return 0;
}