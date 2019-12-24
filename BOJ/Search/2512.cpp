#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long n, m, l, r, mid, ans;
    cin >> n;
    long long a[n];
    r = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (r < a[i]) r = a[i];
    }
    cin >> m;
    l = 1;
    while (l <= r) {
        mid = (l+r) / 2;
        long long temp = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] >= mid) temp += mid;
            else temp += a[i];
        }
        if (temp > m) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
            ans = mid;
        }
    }
    cout << ans << "\n";
    return 0;
}