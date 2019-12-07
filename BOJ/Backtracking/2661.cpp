#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;

bool dfs(int x);
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    dfs(0);
    return 0;
}

bool dfs(int x) {
    if (x == n) {
        for (int i=0; i<n; i++) cout << v[i];
        cout << "\n";
        return true;
    }

    for (int i=1; i<=3; i++) {
        if (x>0 && v[x-1]==i) continue;
        v.push_back(i);
        bool isPossible = true;
        for (int j=2; j<=(x+1)/2; j++) {
            bool same = true;
            for (int k=j; k<=x-j+1; k++) {
                same = true;
                for (int l=0; l<j; l++) {
                    if (v[k+l-j] != v[k+l]) {
                        same = false;
                        break;
                    }
                }
                if (same) break;
            }
            if (same) {
                isPossible = false;
                break;
            }
        }
        if (isPossible && dfs(x+1)) return true;
        v.pop_back();
    }
    return false;
}