// codeforces 1A
// https://codeforces.com/problemset/problem/1/A
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll n, m, a; cin >> n >> m >> a;
    ll rowmin = n / a;
    ll colmin = m / a;
    if((n - rowmin * a) % a != 0) rowmin++;
    if((m - colmin * a) % a != 0) colmin++;
    ll ans  = rowmin * colmin;
    cout << ans;
    return 0;
}
