#include <iostream>
#include <queue>
using namespace std;

int n, tc, ans;
int a[100001];
int visited[100001];
int indegree[100001]; 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> tc;
    while(tc--) {
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            visited[i] = indegree[i] = 0;
        }
        for (int i = 1; i <= n; i++)    indegree[a[i]]++;
        queue<int> q;
        for (int i = 1; i <= n; i++) 
            if (indegree[i] == 0)   q.push(i);
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            ans++;
            int next = a[now];
            indegree[next]--;
            if (indegree[next] == 0) q.push(next); 
        }
        cout << ans << "\n";
    }
    return 0;
}