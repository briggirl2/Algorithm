#include <iostream>
using namespace std;
int dfs(int r);
int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << dfs(n) << "\n";
    }
    return 0;
}
int dfs(int r){
    if (r < 0) return 0;
    if (r == 0) return 1;
    return dfs(r-1)+dfs(r-2)+dfs(r-3);
}