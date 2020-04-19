#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int cnt[30];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    fill(cnt, cnt + 30, -1);
    for (int i = 0; i < s.length(); i++) {
        if (cnt[s[i] - 'a'] == -1) {
            cnt[s[i] - 'a'] = i;
        }
    }
    for (int i = 0; i <= 'z' - 'a'; i++) {
        cout << cnt[i] << " ";
    }
    cout << "\n";
    return 0;
}
