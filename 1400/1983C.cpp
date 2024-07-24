// codeforces 1983C
// https://codeforces.com/problemset/problem/1983/C
#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        vector<vector<int>> arr(3, vector<int>(n + 1, 0));
        // 3명의 평가의 누적 합을 저장할 배열
        vector<vector<ll>> prefixsum(3, vector<ll>(n + 1, 0));
        for(int i = 0; i < 3; i++) {
            for(int j = 1; j <= n; j++) {
                cin >> arr[i][j];
                prefixsum[i][j] = prefixsum[i][j - 1] + arr[i][j]; 
            }
        }
        // 모든 가능한 경우를 탐색하기 위한 순열. 
        vector<int> cases = {0, 1, 2};
        // 되는 경우를 발견하면 나갈 bool 변수
        bool flag = false;
        ll minval = (prefixsum[0][n] % 3) ? prefixsum[0][n] / 3 + 1 : prefixsum[0][n] / 3;
        // cases 로 만들 수 있는 경우의 수는 총 6가지이다. 
        for (int i = 0; i < 6; i++) {
            int cur = 1; 
            // alice, bob, charlie 중 아무나 한명에게 케이크의 초기 부분을 전달하려 시도
            while(cur <= n && prefixsum[cases[0]][cur] < minval) cur++;
            // 나머지 2명에게 배분하고, 조건만족하는지 체크
            for(int j = cur + 1; j < n; j++) {
                if(prefixsum[cases[1]][j] - prefixsum[cases[1]][cur] >= minval && 
                prefixsum[cases[2]][n] - prefixsum[cases[2]][j] >= minval) {
                    vector<pair<int, int>> ans(3);
                    ans[cases[0]] = {1, cur};
                    ans[cases[1]] = {cur + 1, j};
                    ans[cases[2]] = {j + 1, n};
                    for(const auto & ele : ans) cout << ele.first << " " << ele.second << " ";
                    cout << "\n";
                    flag = true;
                    break;
                }
            }
            if(flag) break;
            next_permutation(cases.begin(), cases.end());
        }
        if(!flag) cout << -1 << "\n";
    }
    return 0;
}
