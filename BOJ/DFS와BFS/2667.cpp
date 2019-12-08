#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int dx[] = {-1, 0 ,1, 0};
int dy[] = {0, 1, 0, -1};
int map[25][25];
vector<int> ans;
void bfs(int x, int y);
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cin.get();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) map[i][j] = cin.get()-'0';
        cin.get();
    }

    for(int i=0; i<n; i++) 
        for (int j=0; j<n; j++) 
            if (map[i][j]) bfs(i, j);
    
    n = ans.size();
    cout << n << "\n";
    sort(ans.begin(), ans.end());
    for (int i=0; i<n; i++) cout << ans[i] << "\n";
    return 0;
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    map[x][y] = 0;
    int cnt = 0;
    while(!q.empty()) {
        x = q.front().first; y = q.front().second; 
        q.pop(); cnt++;
        for (int i=0; i<4; i++) {
            int nx = x + dx[i]; int ny = y + dy[i];
            if (nx<0 || nx>=n || ny<0 || ny>=n || !map[nx][ny]) continue;
            q.push({nx, ny});
            map[nx][ny] = 0;
        }
    }
    ans.push_back(cnt);
}