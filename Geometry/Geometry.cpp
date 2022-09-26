#include <bits/stdc++.h>
using namespace std;

const double inf = 1e100, eps = 1e-12;
const double PI = acos(-1.0L);

int cmp(double a, double b = 0){
    if(abs(a-b) < eps) return 0;
    return (a < b) ? -1 : +1;
}

// Struct to represent a point/vector
struct PT{
    double x, y;
    PT(double x = 0, double y = 0) : x(x), y(y) {}
    PT operator + (const PT &p) const { return PT(x + p.x, y + p.y); }
    PT operator - (const PT &p) const { return PT(x - p.x, y - p.y); }
    PT operator * (double c) const { return PT(x*c, y*c); }
    PT operator / (double c) const { return PT(x/c, y/c); }
    bool operator < (const PT &p) const {
        if(cmp(x, p.x) != 0) return x < p.x;
        return cmp(y, p.y) < 0;
    }
    bool operator == (const PT &p) const { return !cmp(x, p.x) && !cmp(y, p.y); }
    bool operator != (const PT &p) const { return !(p == *this); }
};

// Debug function
ostream &operator << (ostream &os, const PT &p){
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

// Function to calculate the dot product (u.v)
double dot (PT p, PT q) { return p.x * q.x + p.y*q.y; }

// Function to calculate the cross product (uXv) (2x2 determinant)
double cross (PT p, PT q) { return p.x * q.y - p.y*q.x; }

// Function to calculate the magnitude of the vector (|u|)
double norm (PT p) { return hypot(p.x, p.y); }