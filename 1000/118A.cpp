// codeforces 118A
// https://codeforces.com/problemset/problem/118/A
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string str; cin >> str;
    for(int i = 0; i < str.size(); i++) {
        // 모음 제거
        if(str[i] == 'A' || str[i] == 'a' || str[i] == 'O' || str[i] == 'o' || str[i] == 'Y' || str[i] == 'y' || str[i] == 'E' ||
        str[i] == 'e' || str[i] == 'U' || str[i] == 'u' || str[i] == 'I' || str[i] == 'i') str[i] = 0;
        // 모든 자음의 대 -> 소
        else if(str[i] >= 'B' && str[i] <= 'Z') str[i] += 32;
    }
    for(int i = 0; i < str.size(); i++) {
        // 모든 자음 앞에 . 추가
        if(str[i] != 0) cout << "." << str[i];
    }
    return 0;
}
