#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int m = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        int temp = 0;
        for (int j = 1; j < i; j++) {
            if (v[j] > v[i]) continue;
            if (temp < dp[j]) temp = dp[j];
        }
        dp[i] = temp + 1;
        if (dp[i] > m) m = dp[i];
    }
    cout << n - m << "\n";
    return 0;
}