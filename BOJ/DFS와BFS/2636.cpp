#include <iostream>
#include <queue>
using namespace std;

int n, m, total, air, turn, temp;
int map[100][100];
bool visited[100][100];
int dx[] = {-1, 0 ,1, 0};
int dy[] = {0, -1, 0 ,1};
queue<pair<int,int>> q;
int bfs();
int main() {
    ios_base::sync_with_stdio(false);   cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    total = n * m;
    air = turn = temp = 0;
    q.push({0, 0});
    visited[0][0] = true;
    air = bfs();

    while (air != total) {
        turn++;
        temp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j]) {
                    q.push({i, j});
                }
            }
        }
        int qsize = q.size();
        while (qsize--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
                if (visited[nx][ny] || map[nx][ny] == 0) continue;
                q.push({nx, ny});
                visited[nx][ny] = true;
                temp++;
                map[nx][ny] = 0;
            }
        }
        air += bfs();
    }
    cout << turn << "\n" << temp << "\n";
    return 0;
}
int bfs() {
    int t = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        t++;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if (visited[nx][ny] || map[nx][ny] == 1) continue;
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    return t;
}