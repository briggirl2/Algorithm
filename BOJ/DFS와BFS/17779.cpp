#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;
int map[25][25];
int linesum[25][25];
int local[6];
int total = 0;
int ans = 50000;

int calc_local1(int k, int x, int y);
int calc_local2(int k, int x, int y);
int calc_local3(int k, int x, int y);
int calc_local4(int k, int x, int y);

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
            total += map[i][j];
            linesum[i][j] = linesum[i][j - 1] + map[i][j];
        }
    }
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            for (int d1 = 1; d1 < n - x && y - d1 >= 1; d1++) {
                for (int d2 = 1; x + d1 + d2 <= n && y + d2 <= n; d2++) {
                    int mini, maxi;
                    local[1] = calc_local1(d1, x, y);
                    local[2] = calc_local2(d2, x, y);
                    local[3] = calc_local3(d2, x + d1, y - d1);
                    local[4] = calc_local4(d1, x + d2, y + d2);
                    local[5] = total - local[1] - local[2] - local[3] - local[4];

                    sort(local + 1, local + 6);
                    if (local[1] == 0) continue;
                    if (ans > local[5] - local[1]) ans = local[5] - local[1];
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
int calc_local1(int k, int x, int y) {
    int tmp = 0;
    for (int i = 1; i < x; i++) tmp += linesum[i][y];
    for (int i = 0; i < k; i++) tmp += linesum[x + i][y - i - 1];
    return tmp;
}
int calc_local2(int k, int x, int y) {
    int tmp = 0;
    for (int i = 1; i <= x; i++) tmp += linesum[i][n] - linesum[i][y];
    for (int i = 1; i <= k; i++) tmp += linesum[x + i][n] - linesum[x + i][y + i];
    return tmp;
}
int calc_local3(int k, int x, int y) {
    int tmp = 0;
    for (int i = 0; i < k; i++) tmp += linesum[x + i][y + i - 1];
    for (int i = x + k; i <= n; i++) tmp += linesum[i][y + k - 1];
    return tmp;
}
int calc_local4(int k, int x, int y) {
    int tmp = 0;
    for (int i = 1; i <= k; i++) tmp += linesum[x + i][n] - linesum[x + i][y - i];
    for (int i = x + k + 1; i <= n; i++) tmp += linesum[i][n] - linesum[i][y - k - 1];
    return tmp;
}
