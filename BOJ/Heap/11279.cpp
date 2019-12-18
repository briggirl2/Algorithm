#include <iostream>
#include <queue>
using namespace std;
priority_queue<int> q;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n;
    while (n--) {
        cin >> x;
        if (x) {
            q.push(x);
        } else if (q.empty()){
            cout << "0\n";
        } else {
            cout << q.top() << "\n";
            q.pop();
        }
    }
    return 0;
}