// 1158
#include <iostream>
#include <queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    queue<int> q;
    for (int i=1; i<=n; i++) q.push(i);
    cout << "<";
    while (q.size() != 1) {
        for (int i=1; i<k; i++) {
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << ">\n";
    return 0;
}