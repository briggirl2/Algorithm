#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long n, k, t, ans;
    cin >> n >> k;
    vector<pair<long long, long long>> a(n);
    vector<long long> b(k);
    priority_queue<long long> q;
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    for (int i = 0; i < k; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ans = t = 0;
    for (int i = 0; i < k; i++) {
        while (t < n && a[t].first <= b[i]) {
            q.push(a[t++].second);
        }
        if (!q.empty()) {
            ans += q.top();
            q.pop();
        }
    }
    cout << ans << "\n";
    return 0;
}