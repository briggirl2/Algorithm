#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, now, ans;
    cin >> n;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].second >> v[i].first;
    }
    sort(v.begin(), v.end());
    now = ans = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].second < now) continue;
        now = v[i].first;
        ans++;
    }
    cout << ans << "\n";
    return 0;
}