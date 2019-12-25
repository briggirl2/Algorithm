#include <iostream>
using namespace std;
int main() {
    int n, i, ans = 0;
    cin >> n;
    bool notPrime[1001] = {false, };
    notPrime[1] = true;
    for (i=2; i*i<=1000; i++) {
        if (notPrime[i]) continue;
        for (int j=i+i; j<=1000; j+=i) {
            notPrime[j] = true;
        }
    }
    while (n--) {
        cin >> i;
        if (!notPrime[i]) ans++;
    }
    cout << ans << "\n";
    return 0;
}