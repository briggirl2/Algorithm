#include <iostream>
using namespace std;
long long a[1000000];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long n, m, l, r, mid, h;
    l = r = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (r < a[i]) r = a[i];
    }
    while (l <= r) {
        mid = (l + r) / 2;
        long long temp = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > mid) temp += (a[i] - mid);
        }
        if (temp < m) {
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