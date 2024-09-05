// codeforces 479C
// https://codeforces.com/problemset/problem/479/C
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<pi> schedule(n);

    for(int i = 0; i < n; i++) cin >> schedule[i].first >> schedule[i].second;

    // 원래 시험 일자 기준, 오름차순 정렬
    sort(schedule.begin(), schedule.end());

    int lastday = -1;

    for(int i = 0; i < n; i++) {
        if(schedule[i].second >= lastday) lastday = schedule[i].second;
        else lastday = schedule[i].first;
    }
    cout << lastday;
    return 0;
}
