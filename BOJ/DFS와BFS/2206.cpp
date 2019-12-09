#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int map[1001][1001];
int visited[1001][1001][2];
struct Point {
    int x;
    int y;
    int crush;
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    cin.get();
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            map[i][j] = cin.get() - '0';
        }
        cin.get();
    }
    queue<Point> q;
    q.push({1, 1, 0});
    visited[1][1][0] = 1;
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int crush = q.front().crush;
        if (x == n && y == m) {
            cout << visited[x][y][crush] << "\n";
            return 0;
        }
        q.pop();
        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx<1 || nx>n || ny<1 || ny>m) continue;
            if (map[nx][ny] == 1 && crush == 1) continue;
            if (map[nx][ny] == 1 && !visited[nx][ny][1]) {
                q.push({nx, ny, 1});
                visited[nx][ny][1] = visited[x][y][crush] + 1;
            }
            else if (map[nx][ny] == 0 && !visited[nx][ny][crush]) {
                q.push({nx, ny, crush});
                visited[nx][ny][crush] = visited[x][y][crush] + 1;
            }
        }
    }
    cout << "-1\n";
    return 0;
}