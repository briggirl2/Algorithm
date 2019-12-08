#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, v;
bool visited[1001];
vector<int> e[1001];
void dfs(int x);
void bfs(int x);
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> v;
    while (m--) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        if (!e[i].empty()) sort(e[i].begin(), e[i].end());
    }

    dfs(v);
    cout << "\n";
    fill(visited, visited+n+1, false);
    bfs(v);
    cout << "\n";
    return 0;
}

void dfs(int x) {
    visited[x] = true;
    cout << x << " ";
    int k = e[x].size();
    for (int i=0; i<k; i++) {
        if (!visited[e[x][i]]) dfs(e[x][i]);
    }
}

void bfs(int x) {
    queue<int> q;
    q.push(x);
    visited[x] = true;
    while (!q.empty()) {
        x = q.front(); q.pop();
        cout << x << " ";
        int k = e[x].size();
        for (int i=0; i<k; i++) {
            if (!visited[e[x][i]]) {
                q.push(e[x][i]);
                visited[e[x][i]] = true;
            }
        }
    }
}