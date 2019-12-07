#include <iostream>
#include <vector>
using namespace std;

int n, k, ans = 50000;
vector<int> A, B;
vector<int> v[20];

void dfs(int x);
int main() {
    cin >> n;
    k = n / 2;
    int tmp;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> tmp;
            v[i].push_back(tmp);
        }
    }
    A.push_back(0);
    dfs(1);
    cout << ans << "\n";
    return 0;
}

void dfs(int x) {
    if (x >= n) {
        int a = 0, b = 0;
        for (int i=0; i<k; i++) {
            for (int j=i+1; j<k; j++) {
                a += v[A[i]][A[j]] + v[A[j]][A[i]];
                b += v[B[i]][B[j]] + v[B[j]][B[i]];
            }
        }
        int dif = a-b >= 0 ? a-b : b-a;
        if (ans > dif) ans = dif;
        return;
    }
    if (A.size() < k) {
        A.push_back(x);
        dfs(x+1);
        A.pop_back();
    }

    if (B.size() < k) {
        B.push_back(x);
        dfs(x+1);
        B.pop_back();
    }
}

