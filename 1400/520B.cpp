// codeforces 520B
// https://codeforces.com/problemset/problem/520/B
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, cnt = 0;

    cin >> n >> m;

    while(n < m) {
        // 파란 버튼
        if(m % 2) m++;
        // 빨간 버튼 
        else m = m / 2;
        cnt++;
    }
    // 남은 조작 횟수는, 파란 버튼을 눌러야만 해결할 수 있음 
    cnt += n - m;
    cout << cnt;
    return 0;
}
