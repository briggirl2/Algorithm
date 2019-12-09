#include <iostream>
using namespace std;

int cnt[41][2];
int main() {
    cnt[0][0] = 1;
    cnt[1][1] = 1;
    for (int i=2; i<=40; i++) {
        cnt[i][0] = cnt[i-1][0] + cnt[i-2][0];
        cnt[i][1] = cnt[i-1][1] + cnt[i-2][1];
    }
    int n, tc;
    cin >> tc;
    while(tc--) {
        cin >> n;
        cout << cnt[n][0] << " " << cnt[n][1] <<"\n";
    }
    return 0;
}