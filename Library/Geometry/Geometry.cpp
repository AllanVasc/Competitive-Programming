#include <bits/stdc++.h>
using namespace std;

const double inf = 1e100, eps = 1e-12;
const double PI = acos(-1.0L);

// Note: Whenever possible, work only with integers!
// If integers are used, the "cmp" function will no longer work.
// It's necessary to remove it from all locations!
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
    return os << "(" << p.x << "," << p.y << ")";
}

// Function to calculate the dot product (u.v)
double dot (PT p, PT q) { return p.x * q.x + p.y * q.y; }

// Function to calculate the cross product (uXv) (2x2 determinant)
double cross (PT p, PT q) { return p.x * q.y - p.y * q.x; }

// Function to calculate the magnitude of the vector (|u|)
double norm (PT p) { return hypot(p.x, p.y); }

// Function to calculate the distance of 2 points
double dist (PT p, PT q) { return hypot(p.x - q.x, p.y - q.y); }

// Function to project point c onto segment a - b
PT projPtInSegment(PT a, PT b, PT c){
    double r = dot(b - a, b - a);
    if(cmp(r) == 0) return a;
    r = dot(b - a, c - a) / r;
    if(cmp(r, 0) < 0) return a;
    if(cmp(r, 1) > 0) return b;
    return a + (b - a) * r;
}

// Function to calculate the minimum distance between point c and segment a-b
double distPtSegment(PT a, PT b, PT c){
    return dist(c, projPtInSegment(a, b, c));
}

// Returns true if a point c is on segment a-b
bool ptInSegment(PT a, PT b, PT c){
    if(a == b) return a == c;
    a = a - c, b = b - c;
    return cmp(cross(a, b)) == 0 && cmp(dot(a, b)) <= 0;
}

// Returns true if 2 lines are parallel
bool parallel(PT a, PT b, PT c, PT d){
    return cmp(cross(b - a, c - d)) == 0;
}

// Returns true if two segments are collinear
bool collinear(PT a, PT b, PT c, PT d){
    return parallel(a, b, c, d) && cmp(cross(a - b, a - c)) == 0 && cmp(cross(c - d, c - a)) == 0;
}

// Returns true if two segments are intersecting at some point
bool segmentIntersection(PT a, PT b, PT c, PT d){
    if(collinear(a, b, c, d)){
        if(a == c || a == d || b == c || b == d) return true;
        if(cmp(dot(c - a, c - b)) > 0 && cmp(dot(d - a, d - b)) > 0 && cmp(dot(c - b, d - b)) > 0) return false;
        return true;
    }
    if(cmp(cross(d - a, b - a) * cross(c - a, b - a)) > 0) return false;
    if(cmp(cross(a - c, d - c) * cross(b - c, d - c)) > 0) return false;
    return true;
}

// Returns the position of the point relative to the simple polygon
// Polygon is simple if its boundary doesn't cross itself
// Returns -1 if the point is strictly inside the polygon
// Returns 0 if the point is on the boundary
// Returns 1 if the point is outside the polygon
int pointInPolygon(const vector<PT> &p, PT q){ // O(n)
    int windingNumber = 0;
    for(int i = 0; i < p.size(); i++){
        if(p[i] == q) return 0;
        int j = (i + 1) % p.size();
        if(p[i].y == q.y && p[j].y == q.y){ // "Throwing" the horizontal ray
            if(ptInSegment(p[i], p[j], q))
                return 0;
        }
        else{
            bool below = p[i].y < q.y;
            if(below == (p[j].y < q.y)) continue;
            auto orientation = cross(q - p[i], p[j] - p[i]);
            if(cmp(orientation) == 0) return 0;
            if(below == (orientation < 0)) windingNumber += below ? 1 : -1;
        }
    }
    return windingNumber == 0 ? 1 : -1;
}

// Polygon area using Shoelace Formula.
// Points need to be sorted in clockwise or counterclockwise.
double signedPolygonArea(const vector<PT> &p){
    double area = 0;
    for(int i = 0; i < p.size(); i++){
        int j = (i + 1) % p.size();
        area += p[i].x * p[j].y - p[j].x * p[i].y;
    }
    return area/2.0;
}

double polygonArea(const vector<PT> &p){ return abs(signedPolygonArea(p)); }