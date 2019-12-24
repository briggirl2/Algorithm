#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, c, l, r, m, ans;
    cin >> n >> c;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    l = 1;
    r = v[n-1] - v[0];
    while (l <= r) {
        m = (l + r) / 2;
        int temp = 1;
        int k = 0;
        for (int i = k + 1; i < n; i++) {
            if (v[i] - v[k] >= m) {
                temp++;
                k = i;
            }
        }
        if (temp < c) {
            r = m - 1;
        }
        else {
            l = m + 1;
            ans = m;
        }
    }
    cout << ans << "\n";
    return 0;
}