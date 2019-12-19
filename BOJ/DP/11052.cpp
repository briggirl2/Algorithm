#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int p[n+1];
    int dp[n+1];
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = p[i];
        for (int j = 1; j <= i/2; j++)
        {
            int temp = dp[j] + dp[i-j];
            if (dp[i] < temp)   dp[i] = temp;
        }
    }
    cout << dp[n] << "\n";
    return 0;       
}