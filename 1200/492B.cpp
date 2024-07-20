// codeforces 492B
// https://codeforces.com/problemset/problem/492/B
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, l; cin >> n >> l;
    vector<int> a(n, 0);
    vector<double> min_dist;
    vector<int> diff(n - 1, 0);
    for(int i = 0; i  < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    if(n != 1) {
        for(int i = 0; i < n - 1; i++) diff[i] = (a[i] > a[i + 1] ? a[i] - a[i + 1] : a[i + 1] - a[i]);
    }
    sort(diff.begin(), diff.end());
    min_dist.push_back((double)(a[0] - 0));
    min_dist.push_back((double)(l - a[n - 1]));
    if(n != 1) {
        min_dist.push_back((double)(diff[n - 2] / 2.0));
    }
    cout << setprecision(9);
    cout << *max_element(min_dist.begin(), min_dist.end());
    return 0;
}
