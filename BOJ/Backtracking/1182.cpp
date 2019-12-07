#include <iostream>
using namespace std;
int n, s;
int a[20];
int dfs(int x, int r);
int main() {
    cin >> n >> s;
    for (int i=0; i<n; i++)  cin >> a[i];
    cout << dfs(0, s) << "\n";
    return 0;
}
int dfs(int x, int r) {
    if (x >= n) return 0;
    return (dfs(x+1, r) + dfs(x+1, r-a[x]) + (a[x]==r));
}