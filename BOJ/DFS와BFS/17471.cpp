#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int n;
vector<int> v[11]; // v[i]에는 i와 인접한 노드들
vector<int> p; // 인구수
bool visited[11];
int g[11]; // g[i]는 i의 그룹
int total = 0;
int ans = 50000;

void make_g1(int x, int sum1);
int bfs(int k);

int main() {
    cin >> n;
    p.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        total += p[i];
    }
    for (int i = 1; i <= n; i++) {
        int k, tmp;
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> tmp;
            v[i].push_back(tmp);
        }
    }
    g[1] = 1;
    make_g1(2, p[1]);
    cout << ((ans == 50000) ? -1 : ans) << '\n';
    return 0;
}

void make_g1(int x, int sum1) { // 1은 그룹1, 나머지 그룹 1,0 중에 정하기
    if (x == n + 1) {
        if (sum1 == total || sum1 != bfs(1) || total - sum1 != bfs(0)) return;
        int dif = total - sum1 * 2;
        if (dif < 0) dif *= -1;
        if (ans > dif) ans = dif;
        return;
    }
    g[x] = 1;
    make_g1(x + 1, sum1 + p[x]);
    g[x] = 0;
    make_g1(x + 1, sum1);
}

int bfs(int k) { // k그룹에 속하는 노드 정해서 그 노드와 인접하면서 같은 그룹인 것의 인구합 구하기
    memset(visited, false, sizeof(visited));
    int x;
    if (k == 1)
        x = 1;
    else {
        for (int i = 1; i <= n; i++) {
            if (g[i] == 0) {
                x = i;
                break;
            }
        }
    }
    int sum = p[x];
    queue<int> q;
    q.push(x);
    visited[x] = true;
    while (!q.empty()) {
        x = q.front();
        q.pop();
        for (int i = 0; i < v[x].size(); i++) {
            int nx = v[x][i];
            if (visited[nx] == true || g[nx] != k) continue;
            visited[nx] = true;
            sum += p[nx];
            q.push(nx);
        }
    }
    return sum;
}
