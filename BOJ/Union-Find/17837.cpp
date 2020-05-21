#include <iostream>
using namespace std;
int map[13][13];
int top[13][13];
struct A {
    int x;
    int y;
    int dir;
    int p;
} a[11];
int n, k;
int ans = 1;
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

int get_p(int c);
bool in_map(int r, int c);
int count_p(int c);

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> map[i][j];
    for (int i = 1; i <= k; i++) {
        cin >> a[i].x >> a[i].y >> a[i].dir;
        a[i].p = 0;
        top[a[i].x][a[i].y] = i;
    }

    for (; ans < 1000; ans++) {
        int i;
        for (i = 1; i <= k; i++) {
            int r = i;
            int t = get_p(i);
            int x = a[t].x;
            int y = a[t].y;
            int d = a[i].dir;
            int nx = x + dx[d];
            int ny = y + dy[d];
            int tmp = a[i].p;
            if (!in_map(nx, ny) || map[nx][ny] == 2) {  // 반대방향
                nx = x - dx[d];
                ny = y - dy[d];
                if (d % 2)
                    a[i].dir += 1;
                else
                    a[i].dir -= 1;
                if (!in_map(nx, ny) || map[nx][ny] == 2) continue;
            }
            if (map[nx][ny] == 1) {  // 뒤집기
                int u = top[x][y], v = a[u].p, w = a[v].p;
                r = u;
                a[u].x = nx;
                a[u].y = ny;
                while (u != i) {
                    a[v].p = u;
                    u = v;
                    v = w;
                    w = a[w].p;
                }
                a[top[x][y]].p = v;
                top[x][y] = i;
            }
            // 이동
            a[r].p = top[nx][ny];
            top[nx][ny] = top[x][y];
            top[x][y] = tmp;
            int front = get_p(r);
            a[front].x = nx;
            a[front].y = ny;
            if (count_p(top[nx][ny]) >= 4) break;
        }
        if (i != k + 1) {
            cout << ans << '\n';
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}
int get_p(int c) {
    if (a[c].p == 0) return c;
    return get_p(a[c].p);
}
bool in_map(int r, int c) {
    if (r < 1 || r > n || c < 1 || c > n) return false;
    return true;
}
int count_p(int c) {
    if (a[c].p == 0) return 1;
    return count_p(a[c].p) + 1;
}
