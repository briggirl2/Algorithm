#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
priority_queue<int> q1;
priority_queue<int, vector<int>, greater<int>> q2;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n;
    while (n--) {
        cin >> x;
        if (x) {
            if (x < 0) q1.push(x);
            else q2.push(x);
        } else if (q1.empty() && q2.empty()){
            cout << "0\n";
        } else if (q1.empty()) {
            cout << q2.top() << "\n";
            q2.pop();
        } else if (q2.empty()) {
            cout << q1.top() << "\n";
            q1.pop();
        } else if (-1 * q1.top() <= q2.top()) {
            cout << q1.top() << "\n";
            q1.pop();
        } else {
            cout << q2.top() << "\n";
            q2.pop();
        }
    }
    return 0;
}