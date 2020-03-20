#include <iostream>
using namespace std;

int adj[201][201];
int p[201];
int go[1001];

int root(int k);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> adj[i][j];
            if (i < j && adj[i][j] == 1)
            {
                int root_i = root(i);
                int root_j = root(j);
                if (root_i == root_j)
                    continue;
                p[root_i] = root_j;
            }
        }
    }

    bool ans = true;
    cin >> go[0];
    for (int i = 1; i < m; i++)
    {
        cin >> go[i];
        if (go[i - 1] == go[i])
            continue;
        if (root(go[i - 1]) != root(go[i]))
        {
            ans = false;
            break;
        }
    }

    if (ans)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}

int root(int k)
{
    if (p[k] == k)
        return k;

    p[k] = root(p[k]);
    return p[k];
}
