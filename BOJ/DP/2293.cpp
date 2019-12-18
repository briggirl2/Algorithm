#include <iostream>
using namespace std;
int a[100];
int dp[10001];
int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; 
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = a[i]; j <= k; j++) {
            dp[j] += dp[j-a[i]];
        }
    }
    cout << dp[k] << "\n";
    return 0;
    
}