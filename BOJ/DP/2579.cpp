#include <iostream>
#include <algorithm>
using namespace std;
int dp[301][3];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a[n+1];
    for (int i=1; i<=n; i++)    cin >> a[i];

    dp[1][0] = a[1];
    for (int i=2; i<=n; i++) {
        dp[i][1] = dp[i-1][0] + a[i];
        dp[i][0] = max(dp[i-2][0], dp[i-2][1]) + a[i];
    }
    cout << max(dp[n][0], dp[n][1]) << "\n";
    return 0;
}