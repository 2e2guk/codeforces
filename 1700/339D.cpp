// codeforces 339D
// https://codeforces.com/problemset/problem/339/D
#include <bits/stdc++.h>
using namespace std;

struct node {
    int val = 0;
    bool flag = true;
};

struct Seg {
    vector<node> t;

    Seg(const int n) : t((2 * n) - 1) {}

    // bitwise OR, XOR 을 수행하는 부분.
    node query(node l, node r) {
        if (l.flag) {
            return {l.val | r.val, false};
        } else {
            return {l.val ^ r.val, true};
        }
    }

    // x = 현재 노드 번호, l, r = 현재 노드(x)가 표현하는 구간, pos = 업데이트하고자 하는 위치, newval = 업데이트할 값. 
    void update(const int x, const int l, const int r, const int pos, const int newval) {
        if (l == r) {
            t[x].val = newval;
            return;
        }
        const int mid = (l + r) >> 1;
        const int l_child = 2 * x + 1;
        const int r_child = 2 * x + 2;
        if (pos <= mid) {
            update(l_child, l, mid, pos, newval);
        } else {
            update(r_child, mid + 1, r, pos, newval);
        }
        t[x] = query(t[l_child], t[r_child]);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    n = 1 << n;
    vector<int> a(n);
    Seg seg(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        seg.update(0, 0, n - 1, i, a[i]);
    }
    while (m--) {
        // 1-based indexed input
        int pos, newval; cin >> pos >> newval; 
        seg.update(0, 0, n - 1, pos - 1, newval);
        cout << seg.t[0].val << "\n";
    }
    return 0;
}
