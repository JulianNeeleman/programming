#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

double INF = 9999999999;

using namespace std;

// All functions should also work with other number types (doubles, floats)
struct Point {
    int x, y;

    bool operator<(const Point &rhs) const {
        return x == rhs.x ? y < rhs.y : x < rhs.x;
    }
    
    bool operator==(const Point &rhs) const {
        return x == rhs.x && y == rhs.y;
    }
};

// Check orientation of point triplets
int orient(Point p, Point q, Point r) {
    int v = (q.y - p.y) * (r.x - q.x) -
        (q.x - p.x) * (r.y - q.y);
    if(v == 0) return 0;
    return v < 0 ? -1 : 1;
}

// Given three colinear points p, q and r, return
// whether q lies on pr
bool on_segment(Point p, Point q, Point r) {
    return q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y);
}

// Check segment-segment intersection
bool intersect(Point p, Point q, Point r, Point s) {
    if(p == r || p == s || q == r || q == s) return false;

    int a = orient(p, q, r),
        b = orient(p, q, s),
        c = orient(r, s, p),
        d = orient(r, s, q);

    // General case
    if(a != b && c != d) return true;
   
    // Special cases
    //if(a == 0 && on_segment(p, q, r)) return true;
    //if(b == 0 && on_segment(p, s, q)) return true;
    //if(c == 0 && on_segment(r, p, s)) return true;
    //if(d == 0 && on_segment(r, q, s)) return true;

    // Otherwise
    return false;
}

// Compute Euclidean distance between points
double dist(Point p, Point q) {
    return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.x - q.y));
}

vector<Point> convex_hull(vector<Point> ps) {
    int n = ps.size(), k = 0;
    vector<Point> hull(2 * n);

    sort(ps.begin(), ps.end());
    
    for(int i = 0; i < n; i++) {
        while(k >= 2 && orient(hull[k - 2], hull[k - 1], ps[i]) <= 0) k--;
        hull[k++] = ps[i];
    }

    for(int i = n - 2, t = k + 1; i >= 0; i--) {
        while(k >= t && orient(hull[k - 2], hull[k - 1], ps[i]) <= 0) k--;
        hull[k++] = ps[i];
    }   

    hull.resize(k - 1);
    return hull;
}

double dijkstra(const vector<vector<pair<int, double> > >& g, int s, int t) {

    vector<double> dst (g.size(), INF);
    dst[s] = 0;
    priority_queue<pair<double, int> > q;
    q.push({0.0, s});
    vector<bool> seen(g.size(), false);

    while(!q.empty()) {
        pair<double, int> p = q.top();
        int w = p.second;
        if(w == t) break;
        q.pop();
        if(!seen[w]) {
            seen[w] = true;
            for(auto to : g[w]) {
                if(dst[to.first] > dst[w] + to.second) {
                    dst[to.first] = dst[w] + to.second;
                    q.push({-dst[to.first], to.first});
                }
            }
        }
    }
    return dst[t];
}

int main() {
    int n, m;

    cin >> n;
    vector<Point> inner(n);
    for(int i = 0; i < n; i++) cin >> inner[i].x >> inner[i].y;

    cin >> m;
    vector<Point> outer(m);
    for(int i = 0; i < m; i++) cin >> outer[i].x >> outer[i].y;

    // Perform convex hull
    vector<Point> ps = convex_hull(inner);
    int h = ps.size();

    // Insert outer polygon to obtain complete set of points
    ps.insert(ps.end(), outer.begin(), outer.end());

    cout << ps.size() << " " << h + m << endl; 

    // For each pair of vertices, check if no line intersections
    // Construct graph from this
    vector<vector<pair<int, double> > > g(h + m);
    for(int i = 0; i < h + m; i++) {
        for(int j = i + 1; j < h + m; j++) {
            bool coll = false;
            for(int k = 0; k < n; k++) coll |= intersect(ps[i], ps[j], inner[k], inner[(k + 1) % n]);
            for(int k = 0; k < m; k++) coll |= intersect(ps[i], ps[j], outer[k], outer[(k + 1) % m]);
            if(!coll) {
                g[i].push_back({j, dist(ps[i], ps[j])});
                g[j].push_back({i, dist(ps[i], ps[j])});
                cout << ps[i].x << " " << ps[i].y << " " << ps[j].x << " " << ps[j].y << endl;
            }
        }
    }

    double ans = 0.0;

    // Perform Dijkstra
    for(int i = 0; i < h; i++) {
        double in = dijkstra(g, i, (i + 1) % h);
        ans += in;
        //cout << ps[i].x << " " << ps[i].y << " " << ps[i + 1].x << " " << ps[i + 1].y << " " << in << endl;
    }

    cout << ans << endl;    

    return 0;
}
