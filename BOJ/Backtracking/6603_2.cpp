#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;
vector<int> v;

void dfs(int n, int cnt, int k);
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int k;
    cin >> k;
    while (k != 0) {
        ans.clear();
        v.clear();
        for (int i=0; i<k; i++) {
            int a;
            cin >> a;
            v.push_back(a);
        }
        dfs(-1, 0, k);
        cout << "\n";
        cin >> k;
    }
    return 0;
}

void dfs(int n, int cnt, int k) {
    if (n > k-6+cnt) return;
    if (cnt == 6) {
        for (int i=0; i<6; i++) cout << v[ans[i]] << " ";
        cout << "\n";
        return;
    }

    for (int i=n+1; i<k; i++) {
        ans.push_back(i);
        dfs(i, cnt+1, k);
        ans.pop_back();
    }
    return;
}