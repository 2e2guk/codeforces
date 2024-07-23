// codeforces 1989C
// https://codeforces.com/problemset/problem/1989/C
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    vector<int> res;
    while(tc--) {
        int n; cin >> n;
        vector<int> a(n); vector<int> b(n);
        vector<int> res;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        // neg = 두 영화를 다 싫어하는 사람의 수
        // pos = 두 영화를 다 좋아하는 사람의 수
        int mv1rating = 0, mv2rating = 0, neg = 0, pos = 0;
        for(int i = 0; i < n; i++) {
            // a[i] != b[i] 인 경우, greedy 하게 선택하는 것이 optimal
            if (a[i] > b[i]) {
                mv1rating += a[i];
            } else if (a[i] < b[i]) {
                mv2rating += b[i];
            } else {
                // 두 영화를 다 싫어하거나 좋아하는 사람의 수, 총 pos + neg
                neg += (a[i] < 0);
                pos += (a[i] > 0);
            }
        }
        // 
        int ans = numeric_limits<int>::min();
        // i = 영화 1을 리뷰하게 할 사람의 수
        for (int i = -neg; i <= pos; ++i) {
            // 모든 가능한 경우를 탐색하며, max를 찾는다. 
            // 영화 1, 영화 2 리뷰는 둘 중에서 더 작은 것을 택한다. 
            ans = max(ans, min(mv1rating + i, mv2rating + (pos - neg - i)));
        }
        cout << ans << "\n";
    }
    return 0;
}
