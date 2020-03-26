#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<long double> a(n + 1);
    vector<long double> sum(n + 1);
    vector<long double> squared(n + 1);
    sum[0] = 0;
    squared[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        squared[i] = squared[i - 1] + a[i] * a[i];
    }
    if (k == 1) {
        cout << "0\n";
        return 0;
    }
    long double ans = LLONG_MAX;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + k; j <= n; j++) {
            long double m = (sum[j] - sum[i]) / (j - i);
            long double temp = (squared[j] - squared[i]) / (j - i) - m * m;
            if (ans > temp) ans = temp;
        }
    }
    cout << fixed;
    cout.precision(12);
    cout << sqrt(ans) << '\n';
    return 0;
}