#include <iostream>
#include <algorithm>
using namespace std;

int n, tc, ans;
int a[100001];
bool visited[100001];
bool checked[100001]; 
void dfs(int now);
int main() {
    cin >> tc;
    for (int t = 0; t < tc; t ++) {
        ans = 0;
        cin >> n;
        fill (checked, checked+n+1, false);
        fill (visited, visited+n+1, false);
        for (int i = 1; i <= n; i++)    cin >> a[i];
        for (int i = 1; i <= n; i++) {
            if (!checked[i]) {
                dfs(i);
            }
        }
        cout << n-ans << "\n";
    }
    return 0;
}

void dfs(int now) {
    visited[now] = true;
    int next = a[now];
    if (!visited[next]) {
        dfs(next);
    }
    else if (!checked[next]) {
        ans++;
        for (int i = now; a[i] != now; i = a[i]) {
            ans++;
        }
    }
    checked[now] = true;
}


