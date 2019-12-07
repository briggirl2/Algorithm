//5430
#include <iostream>
#include <deque>
#include <string>
using namespace std;
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        deque<int> deq;
        string p;
        cin >> p;
        int n;
        cin >> n;
        cin.ignore();

        char c;
        int x = -1;
        while ((c = cin.get()) != '\n') {
            if (c < '0' || c > '9') {
                if (c != '[' && x != -1) {
                    deq.push_back(x);
                    x = 0;
                }
                continue;
            }
            else {
                int a = c - '0';
                if (x == -1) x = a;
                else x = x * 10 + a;
            }
        }

        int i;
        x = p.length();
        int toright = 1;
        for (i=0; i<x; i++) {
            if (p[i] == 'R') {
                toright = 1 - toright;
            }
            else if (deq.empty()) {
                break;
            }
            else if (toright == 1) {
                deq.pop_front();
            }
            else {
                deq.pop_back();
            }
        }

        if (i != x) cout << "error\n";
        else if (deq.empty()) cout << "[]\n";
        else if (toright == 1) {
            cout << "[";
            while (deq.size() > 1) {
                cout << deq.front() << ",";
                deq.pop_front();
            }
            cout << deq.front() << "]\n";
        }
        else {
            cout << "[";
            while (deq.size() > 1) {
                cout << deq.back() << ",";
                deq.pop_back();
            }
            cout << deq.back() << "]\n";
        }
    }
    return 0;
}