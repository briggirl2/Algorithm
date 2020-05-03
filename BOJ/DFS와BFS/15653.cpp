#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct state {
    int rx;
    int ry;
    int bx;
    int by;
    int cnt;
};
vector<string> map;
queue<state> q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int visited[11][11][11][11];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    map.resize(n);
    int rx, ry, bx, by;
    for (int i = 0; i < n; i++) {
        cin >> map[i];
        if (map[i].find('R') != string::npos) {
            rx = i;
            ry = map[i].find('R');
        }
        if (map[i].find('B') != string::npos) {
            bx = i;
            by = map[i].find('B');
        }
    }
    visited[rx][ry][bx][by] = 1;
    q.push({rx, ry, bx, by, 0});
    while (!q.empty()) {
        int rx = q.front().rx;
        int ry = q.front().ry;
        int bx = q.front().bx;
        int by = q.front().by;
        int cnt = q.front().cnt;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nrx = rx;
            int nry = ry;
            int nbx = bx;
            int nby = by;
            int inc_r = 0;
            int inc_b = 0;
            while (map[nrx + dx[i]][nry + dy[i]] != '#' && map[nrx][nry] != 'O') {
                nrx += dx[i];
                nry += dy[i];
                inc_r++;
            }
            while (map[nbx + dx[i]][nby + dy[i]] != '#' && map[nbx][nby] != 'O') {
                nbx += dx[i];
                nby += dy[i];
                inc_b++;
            }
            if (map[nbx][nby] == 'O') continue;
            if (map[nrx][nry] == 'O') {
                cout << cnt + 1 << "\n";
                return 0;
            }
            if (nrx == nbx && nry == nby) {
                if (inc_r > inc_b) {
                    nrx -= dx[i];
                    nry -= dy[i];
                } else {
                    nbx -= dx[i];
                    nby -= dy[i];
                }
            }
            if (visited[nrx][nry][nbx][nby] == 1) continue;
            visited[nrx][nry][nbx][nby] = 1;
            q.push({nrx, nry, nbx, nby, cnt + 1});
        }
    }
    cout << "-1\n";
    return 0;
}
