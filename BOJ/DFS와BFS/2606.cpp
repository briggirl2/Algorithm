#include <iostream>
#include <vector>
using namespace std;
int n, m, ans=-1;
vector<int> v[101];
bool visited[101];
void dfs(int x);
int main() {
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    cout << ans << "\n";
    return 0;
}
void dfs(int x) {
    visited[x] = true;
    ans++;
    int k = v[x].size();
    for (int i=0; i<k; i++) {
        if(visited[v[x][i]]) continue;
        dfs(v[x][i]);
    }
}