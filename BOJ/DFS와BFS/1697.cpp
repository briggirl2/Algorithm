#include <iostream>
#include <queue>
using namespace std;
bool visited[200001];
int n, k;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    int ans = 0;
    queue<int> q;
    q.push(n);
    visited[n] = true;
    while(!q.empty()) {
        int m = q.size();
        while(m--) {
            int x = q.front();
            if (x == k) {
                cout << ans << "\n";
                return 0;
            }
            q.pop();
            int nx[3] = {x-1, x+1, x*2};
            for (int i=0; i<3; i++) {
                if (nx[i]<0 || nx[i]>200000 || visited[nx[i]]) continue;
                q.push(nx[i]);
                visited[nx[i]] = true;
            }
        }
        ans++;
    }
    return 0;
}