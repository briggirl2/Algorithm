#include <iostream>
using namespace std;
int main() {
    int n, ans;
    cin >> n;
    int a[n];
    int dp[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ans = dp[0] = a [0];
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i-1] < 0 ? a[i] : dp[i-1] + a[i];
        if (ans < dp[i]) ans = dp[i];
    }
    cout << ans << "\n";
    return 0;
}