#include <iostream>
using namespace std;
long long a[10005];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long k, n, l, r, mid, h;
    r = 0;
    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        if (r < a[i]) r = a[i];
    }
    l = 1;
    while (l <= r) {
        mid = (l + r) / 2;
        long long temp = 0;
        for (int i = 0; i < k; i++) {
            temp += a[i] / mid;
        }
        if (temp < n) {
            r = mid - 1;
        }
        else {
            h = mid;
            l = mid + 1;
        }
    }
    cout << h << "\n";
    return 0;
}