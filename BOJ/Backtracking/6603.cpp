#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ans;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a, k;
    cin >> k;
    while (k != 0) {
        v.clear();
        ans.clear();
        for (int i=0; i<k; i++) {
            cin >> a;
            v.push_back(a); 
        }

        for (int i=0; i<6; i++) ans.push_back(0);
        for (int i=0; i<k-6; i++) ans.push_back(1);

        do {
            for (int i=0; i<k; i++) 
                if (ans[i] == 0) 
                    cout << v[i] << " ";
        } while ((cout << "\n") && next_permutation(ans.begin(), ans.end()));
        cout << "\n";
        cin >> k;
    }
    return 0;
}