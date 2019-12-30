#include <iostream>
#include <string>
using namespace std;
int dp[1001][1001];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, ans = 0;
    cin >> n >> m;
    string map[n];
    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0 || map[i][j] == '0') 
                dp[i][j] = map[i][j] - '0';
            else {
                int temp = dp[i-1][j-1];
                if (temp > dp[i][j-1]) temp = dp[i][j-1];
                if (temp > dp[i-1][j]) temp = dp[i-1][j];
                dp[i][j] = temp + 1;
            }
            if (ans < dp[i][j]) ans = dp[i][j];
        }
    }
    cout << ans * ans << "\n";
    return 0;
}