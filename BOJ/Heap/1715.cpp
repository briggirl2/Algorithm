#include <iostream>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> q;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, x, y;
    cin >> n;
    while (n--) {
        cin >> x;
        q.push(x);
    }
    while (q.size() != 1) {
        x = q.top();
        q.pop();
        y = q.top();
        q.pop();
        n += x + y;
        q.push(x+y);
    }
    cout << n + 1 << "\n";
    return 0;
}