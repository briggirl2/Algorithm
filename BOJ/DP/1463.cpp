#include <iostream>
using namespace std;
int cnt[1000001] = {0, };
int main() {
    int n;
    cin >> n;
    for (int i=2; i<=n; i++) {
        int temp = cnt[i-1];
        if (i%3 == 0) temp = temp <= cnt[i/3] ? temp : cnt[i/3];
        if (i%2 == 0) temp = temp <= cnt[i/2] ? temp : cnt[i/2];
        cnt[i] = temp + 1;
    }
    cout << cnt[n] << "\n";
    return 0;
}