#include <iostream>
using namespace std;

int per[2][8] = {{0, 1, 3, 6, 10, 15, 21, 100}, {0, 1, 3, 7, 15, 31, 64, 101}};
int prize[2][8] = {{0, 500, 300, 200, 50, 30, 10, 0}, {0, 512, 256, 128, 64, 32, 0, 0}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        int k = 7;
        int ans = 0;
        while (a <= per[0][k]) {
            k--;
        }
        ans += prize[0][k + 1];
        k = 6;
        while (b <= per[1][k]) {
            k--;
        }
        ans += prize[1][k + 1];
        cout << ans * 10000 << "\n";
    }
    return 0;
}