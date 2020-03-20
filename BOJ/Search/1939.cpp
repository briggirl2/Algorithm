#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> adj[10001];
int n, m, s, d;
int maxi = 1, mini = 1;
bool visited[10001];

void input();
bool possible(int k);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    int ans;

    while (mini <= maxi)
    {
        int k = (mini + maxi) / 2;
        fill(visited, visited + n + 1, false);
        if (possible(k) == true)
        {
            ans = k;
            mini = k + 1;
        }
        else
        {
            maxi = k - 1;
        }
    }

    cout << ans << '\n';
    return 0;
}

void input()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (maxi < c)
            maxi = c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    cin >> s >> d;
}

bool possible(int k) // bfs
{
    queue<int> q;
    visited[s] = true;
    q.push(s);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        if (now == d)
        {
            return true;
        }

        for (int i = 0; i < adj[now].size(); i++)
        {
            int next = adj[now][i].first;
            if (!visited[next] && adj[now][i].second >= k)
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return false;
}