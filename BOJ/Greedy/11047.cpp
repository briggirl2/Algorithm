#include <iostream>
using namespace std;
int main() {
    int n, k, ans = 0;
    cin >> n >> k;
    int coin[n];
    for (int i = 0; i < n; i++) cin >> coin[i];
    while (k != 0) {
        ans += k / coin[--n];
        k = k % coin[n];
    }
    cout << ans << "\n";
    return 0;
}