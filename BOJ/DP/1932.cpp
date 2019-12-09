#include <iostream>
using namespace std;
int a[502][502] = {0, };
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) 
        for (int j=1; j<=i; j++) 
            cin >> a[i][j];

    for (int i=2; i<=n; i++)
        for (int j=1; j<=i; j++) 
            a[i][j] = (a[i-1][j-1] >= a[i-1][j] ? a[i-1][j-1] : a[i-1][j]) + a[i][j];

    int ans = a[n][1];
    for (int i=2; i<=n; i++) 
        ans = (ans >= a[n][i] ? ans : a[n][i]);
    cout << ans << "\n";
    return 0;
}