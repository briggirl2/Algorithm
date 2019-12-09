#include <iostream>
using namespace std;
int dp[1001][3];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>> n;
    for (int i=0; i<n; i++) cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
    for (int i=1; i<n; i++) {
        dp[i][0] += dp[i-1][1] <= dp[i-1][2] ? dp[i-1][1] : dp[i-1][2];
        dp[i][1] += dp[i-1][0] <= dp[i-1][2] ? dp[i-1][0] : dp[i-1][2];
        dp[i][2] += dp[i-1][1] <= dp[i-1][0] ? dp[i-1][1] : dp[i-1][0];
    }
    dp[n-1][0] = dp[n-1][0] <= dp[n-1][1] ? dp[n-1][0] : dp[n-1][1];
    dp[n-1][0] = dp[n-1][0] <= dp[n-1][2] ? dp[n-1][0] : dp[n-1][2];
    cout << dp[n-1][0] << "\n";
    return 0;
}