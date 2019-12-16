#include <iostream>
#include <queue>
using namespace std;

struct Point {
    int x;
    int y;
    int z;
};
int n, m, h;
bool visited[101][101][101];
int map[101][101][101];
int dx[] = {-1, 0, 1, 0, 0, 0};
int dy[] = {0, -1, 0, 1, 0 ,0};
int dz[] = {0, 0, 0, 0, -1, 1};
int tomato = 0;
int cnt = 0;
int turn = 0;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> m >> n >> h;
    for(int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> map[k][i][j];
                if (map[k][i][j] != -1) tomato++;
            }
        }
    }

    queue<Point> q;
    for(int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[k][i][j] == 1) {
                    q.push({k, i, j});
                    visited[k][i][j] = true;
                }
            }
        }
    }

    while(!q.empty()) {
        turn++;
        int qsize = q.size();
        for (int i = 0; i < qsize; i++) {
            int x = q.front().x;
            int y = q.front().y;
            int z = q.front().z;
            q.pop();
            cnt++;
            for (int j = 0; j < 6; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                int nz = z + dz[j];
                if (nx<0 || nx>=h || ny<0 || ny>=n || nz<0 || nz>=m) continue;
                if (visited[nx][ny][nz]) continue;
                if (map[nx][ny][nz] == 0) {
                    q.push({nx, ny, nz});
                    visited[nx][ny][nz] = true;
                }
            }
        }    
    }

    if (tomato == cnt) {
        cout << turn-1 << "\n";
    } else {
        cout << "-1\n";
    }
    return 0;
}