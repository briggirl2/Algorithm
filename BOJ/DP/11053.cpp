#include <iostream>
using namespace std;
int main() {
    int n, i, j, m = 1;
    cin >> n;
    int a[n+1];
    int dp[n+1];
    for (i = 1; i <= n; i++) cin >> a[i];
    dp[1] = a[1];
    for (i = 2; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (dp[j] >= a[i]) {
                dp[j] = a[i];
                break;
            }
        }
        if (j == m + 1) {
            dp[++m] = a[i];
        }
    }

    // 부분 수열 출력
    // for (i = 1; i <= m; i++) {
    //     cout<< dp[i] <<" ";
    // }
    // cout<<"\n";

    cout << m << "\n";
    return 0;
}