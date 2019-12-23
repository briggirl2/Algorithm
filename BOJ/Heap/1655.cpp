#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
priority_queue<int> q1;
priority_queue<int, vector<int>, greater<int>> q2;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    q1.push(-100001);
    q2.push(100001);
    int n, x;
    cin >> n;
    while (n--) {
        cin >> x;
        if (q2.top() < x) {
            q2.push(x);
        } else {
            q1.push(x);
        }
        
        if (q1.size() < q2.size()) {
            q1.push(q2.top());
            q2.pop();
        } else if (q1.size() > q2.size()+1) {
            q2.push(q1.top());
            q1.pop();
        }
        cout << q1.top() << "\n";
    }
    return 0;
}