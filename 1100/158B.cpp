// codeforces 158B
// https://codeforces.com/problemset/problem/158/B
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n; 
    int passenger;
    int ans = 0;
    vector<int> groups(5, 0);
    for(int i = 0; i < n; i++) {
        cin >> passenger;
        groups[passenger]++;
    }
    if(groups[3] >= groups[1]) {
        // 3명 그룹의 수가 1명 그룹의 수보다 큰 경우 -> 1명 그룹 전원을 3명 그룹에 포함시킨다.
        ans = groups[4] + groups[3] + ceil(groups[2] / 2.0);
    } else {
        // 3명 그룹의 수가 1명 그룹의 수보다 작은 경우 -> 1명 그룹 중 일부는 남게 된다. 
        ans = groups[4] + groups[3];
        // 1명 그룹 중, 3명 그룹의 수만큼을 태워서 4명으로 만든다. 
        groups[1] -= groups[3];
        // 이제 남은것은 2명 그룹과 1명 그룹. 모두를 인원수로 환산해서 4로 나눈 몫을 올림한다. 
        ans += ceil((2 * groups[2] + groups[1]) / 4.0);
    }
    cout << (int)ans;
    return 0;
}
