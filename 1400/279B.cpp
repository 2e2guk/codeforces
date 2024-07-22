// codeforces 279B
// https://codeforces.com/problemset/problem/279/B
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, t;
    cin >> n >> t;
    vector<int> books(n);
    
    for (int i = 0; i < n; ++i) cin >> books[i];
    
    int start = 0, end = 0, current_sum = 0, max_books_read = 0;
    
    while (end < n) {
        // 현재 책을 읽는 데 필요한 시간을 더함
        current_sum += books[end];
        
        // 만약 현재 합이 t를 초과하면 start 포인터를 오른쪽으로 이동시킴
        while (current_sum > t) {
            current_sum -= books[start];
            start++;
        }
        
        // 최대 읽을 수 있는 책의 수를 업데이트
        max_books_read = max(max_books_read, end - start + 1);
        
        // end 포인터를 오른쪽으로 이동시킴
        end++;
    }
    
    cout << max_books_read << '\n';
    
    return 0;
}
