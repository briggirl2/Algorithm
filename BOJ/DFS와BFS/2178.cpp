#include <iostream>
#include <queue>
using namespace std;
int n, m;
int dx[] = {-1, 0 ,1, 0};
int dy[] = {0, -1, 0, 1};
char map[101][101];
bool visited[101][101];
int main() {
    cin >> n >> m;
    cin.get();
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) map[i][j] = cin.get();
        cin.get();
    }

    int ans = 1;
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = true;
    while(!q.empty()) {
        int k = q.size();
        while(k--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (x == n-1 && y == m-1) {
                cout << ans << "\n";
                return 0;
            }

            for(int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
                if (map[nx][ny]=='0' || visited[nx][ny]) continue;
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
        ans++;
    }
    return 0;
}