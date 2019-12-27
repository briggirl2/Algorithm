#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
bool book[1001];
vector<pair<int,int>> v;
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m, a, b, ans;
        cin >> n >> m;
        v.clear();
        memset(book, false, sizeof(book));
        ans = 0;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            v.push_back({b, a});
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < m; i++) {
            for (int j = v[i].second; j <= v[i].first; j++) {
                if (!book[j]) {
                    ans++;
                    book[j] = true;
                    //cout << j << " " << v[i].second << " "<<v[i].first<<"\n";
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}