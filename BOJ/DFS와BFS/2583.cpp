#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int m, n, k;
int map[101][101];
bool visited[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int dfs(int x, int y);
int main() {
    cin >> m >> n >> k;
    while (k--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int i = b; i < d; i++) 
            for (int j = a; j < c; j++) 
                map[i][j] = 1;
    }

    vector<int> ans;
    for (int i = 0; i < m; i++) 
        for (int j = 0; j < n; j++) 
            if (map[i][j] == 0 && !visited[i][j]) 
                ans.push_back(dfs(i,j));

    int ansSize = ans.size();
    sort(ans.begin(), ans.end());
    cout << ansSize << "\n";
    for (int i = 0; i < ansSize; i++) 
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}
int dfs(int x, int y) {
    visited[x][y] = true;
    int temp = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx<0 || nx>=m || ny<0 || ny>=n) continue;
        if (visited[nx][ny] || map[nx][ny] != 0) continue;
        temp += dfs(nx, ny);
    }
    return temp;
}