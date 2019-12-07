#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, m;
vector<pair<int,int>> store;
vector<pair<int,int>> home;
bool exist[14] = {false, };
int ans = 10000;

void dfs(int x, int cnt);
int main() {
    cin >> n >> m;
    int temp;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> temp;
            if (temp == 1) home.push_back({i, j});
            else if (temp == 2) store.push_back({i, j});
        }
    }
    dfs(0, 0);
    cout << ans <<"\n";
    return 0;
}

void dfs(int x, int cnt) {
    if (cnt == m) {
        int sum = 0;
        for (int i=0; i<home.size(); i++) {
            int mi = 100;
            for (int j=0; j<store.size(); j++) {
                if (!exist[j]) continue;
                int dist = abs(home[i].first-store[j].first) + abs(home[i].second-store[j].second);
                if (mi > dist) mi = dist;   
            }
            sum += mi;
        }
        if (sum < ans) ans = sum;
        return;
    }
    if (m-cnt > store.size()-x) return; //if (x >= store.size()) return;

    exist[x] = true;
    dfs(x+1, cnt+1);
    exist[x] = false;
    dfs(x+1, cnt);
    return;
}

