#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int k;
int in1[10], in2[10], ans1[10], ans2[10];
vector<int> a[10], b[10];
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
    cin >> k;
    char c;
    for (int i = 0; i < k; i++) {
        cin >> c;
        if (c == '<') {
            in1[i]++;
            a[i+1].push_back(i);
            in2[i+1]++;
            b[i].push_back(i+1);
        } else {
            in1[i+1]++;
            a[i].push_back(i+1);
            in2[i]++;
            b[i+1].push_back(i);
        }
    }

    for (int i = 0; i < k+1; i++) {
        if (in1[i] == 0) pq.push(i);
    }
    int t = 9;
    while (!pq.empty()) {
        int i = pq.top();
        pq.pop();
        ans1[i] = t--;
        for (int j = 0; j < a[i].size(); j++) {
            if (--in1[a[i][j]] == 0) pq.push(a[i][j]);
        }
    }

    for (int i = 0; i < k+1; i++) {
        if (in2[i] == 0) pq.push(i);
    }
    t = 0;
    while (!pq.empty()) {
        int i = pq.top();
        pq.pop();
        ans2[i] = t++;
        for (int j = 0; j < b[i].size(); j++) {
            if (--in2[b[i][j]] == 0) pq.push(b[i][j]);
        }
    }
    
    for (int i = 0; i < k+1; i++) {
        cout << ans1[i];
    }
    cout << "\n";
    for (int i = 0; i < k+1; i++) {
        cout << ans2[i];
    }
    cout << "\n";
    return 0;
}