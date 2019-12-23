#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>()); 
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int temp = (i+1) * a[i];
        if (ans < temp) ans = temp;
    }
    cout << ans << "\n";
    return 0;
}