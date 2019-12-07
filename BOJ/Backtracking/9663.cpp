#include <iostream>
#include <cmath>
using namespace std;
int n, ans;
int r[15];
void dfs(int x);
int main() {
    cin >> n;
    dfs(0);
    cout << ans << "\n";
    return 0;
}
void dfs(int x) {
    if (x == n) {
        ans++;
        return;
    }
    for(int i=0; i<n; i++) {
        bool can = true;
        for (int j=0; j<x; j++) {
            if (r[j] == i || r[j]-i == j-x || r[j]-i == x-j) {
                can = false;
                break;
            }
        }
        if (can) {
            r[x] = i;
            dfs(x+1);
        }
    }
}