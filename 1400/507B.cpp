// codeforces 507B
// https://codeforces.com/problemset/problem/507/B
#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

double Dist(const Point& p1, const Point& p2) {
    double dist;
    dist = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int r; Point p1, p2;
    cin >> r >> p1.x >> p1.y >> p2.x >> p2.y;
    double center_dist = Dist(p1, p2);
    if(center_dist == 0) cout << 0;
    else cout << (int)ceil((center_dist - 2*r) / (2*r)) + 1;
    return 0; 
}
