#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long a, b, v, l, r, mid, h;
    cin >> a >> b >> v;
    l = v / a;
    r = v / (a-b) + 1;
    while (l <= r) {
        mid = (l + r) / 2;
        long long temp = a * mid - b * (mid - 1);
        if (temp < v) {
            l = mid + 1;
        }
        else {
            h = mid;
            r = mid -1;
        }
    }
    cout << h << "\n";
    return 0;
}