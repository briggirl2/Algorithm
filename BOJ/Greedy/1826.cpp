#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<pair<long long, long long>> gs;
priority_queue<long long> pq;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long n, a, b, l, p, i, ans = 0;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a >> b;
        gs.push_back({a, b});
    }
    sort(gs.begin(), gs.end());
    cin >> l >> p;
    i = 0;
    while (p < l) {
        while (i < n && gs[i].first <= p) {
            pq.push(gs[i].second);
            i++;
        }
        if (pq.empty()) break;
        ans++;
        p += pq.top();
        pq.pop();
    }
    if (p < l) {
        cout << "-1\n";
    }
    else {
        cout << ans << "\n";
    }
    return 0;
}