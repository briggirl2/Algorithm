#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
int main() {
    int tc;
    cin >> tc;
    while (tc --) {
        vector<int> v;
        queue<pair<int, int>> q;
        int n, m, x;
        cin >> n >> m;
        for (int i=0; i<n; i++) {
            cin >> x;
            v.push_back(x);
            q.push({x, i});
        }
        sort(v.begin(),v.end(),greater<int>());
        for (int i=0; i<n; i++) {
            while (v[i] > q.front().first) {
                q.push(q.front());
                q.pop();
            }
            if (q.front().second == m) {
                cout << i+1 << "\n";
                break;
            }
            q.pop();
        }
    }
    return 0;
}