#include <iostream>
using namespace std;

int p[1000001];

int root(int k);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; i++)
    {
        p[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 0)
        {
            if (a == b)
                continue;
            int rootA = root(a);
            int rootB = root(b);
            if (rootA == rootB)
                continue;
            p[rootA] = rootB;
        }
        else if (a == b || root(a) == root(b))
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }

    return 0;
}

int root(int k)
{
    if (p[k] == k)
        return k;

    p[k] = root(p[k]);
    return p[k];
}
