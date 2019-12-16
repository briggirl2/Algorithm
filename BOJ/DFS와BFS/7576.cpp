#include <iostream>
#include <queue>
using namespace std;

int n, m;
bool visited[1001][1001];
int map[1001][1001];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int tomato = 0;
int cnt = 0;
int turn = 0;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] != -1) tomato++;
        }
    }

    queue<pair<int,int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 1) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    while(!q.empty()) {
        turn++;
        int qsize = q.size();
        for (int i = 0; i < qsize; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            cnt++;
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
                if (visited[nx][ny]) continue;
                if (map[nx][ny] == 0) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
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