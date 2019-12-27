#include <iostream>
using namespace std;
int main() {
    long long n, ans = 0;
    cin >> n;
    long long d[n-1];
    long long c[n];
    for (int i = 0; i < n - 1; i++) {
        cin >> d[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    long long  t = c[0];
    long long sum = d[0];
    for (int i = 1; i < n - 1; i++) {
        if (t > c[i]) {
            ans += t * sum;
            t = c[i];
            sum = d[i];
        }
        else {
            sum += d[i];
        }
    }
    ans += t * sum;
    cout << ans << "\n";
    return 0;
}