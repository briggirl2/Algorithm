#  2020 Code Jam Qualification Round

### 1. Vestigium

``` cpp
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int n;
        int k = 0, r = 0, c = 0;
        cin >> n;
        vector<int> v[n + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int a;
                cin >> a;
                v[i].push_back(a);
                if (i == j) k += a;
            }
        }
        for (int i = 0; i < n; i++) {
            vector<int> visit(n + 1, 0);
            for (int j = 0; j < n; j++) {
                int a = v[i][j];
                if (visit[a] == 1) {
                    r++;
                    break;
                } else {
                    visit[a] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            vector<int> visit(n + 1, 0);
            for (int j = 0; j < n; j++) {
                int a = v[j][i];
                if (visit[a] == 1) {
                    c++;
                    break;
                } else {
                    visit[a] = 1;
                }
            }
        }
        cout << "Case #" << tc << ": " << k << " " << r << " " << c << '\n';
    }
}
```

### 2. Nesting Depth

``` cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int Tc;
    cin >> Tc;
    for (int tc = 1; tc <= Tc; tc++) {
        vector<char> ans;
        string s;
        cin >> s;

        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            int a = c - '0';
            if (a > cnt) {
                int dif = a - cnt;
                while (dif--) {
                    ans.push_back('(');
                    cnt++;
                }
            } else if (a < cnt) {
                int dif = cnt - a;
                while (dif--) {
                    ans.push_back(')');
                    cnt--;
                }
            }
            ans.push_back(c);
        }
        while (cnt--) {
            ans.push_back(')');
        }

        cout << "Case #" << tc << ": ";
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
        }
        cout << "\n";
    }
    return 0;
}
```

### 3. Parenting Partnering R

``` cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int n;
        cin >> n;
        string ans;
        ans.resize(n);

        vector<pair<pair<int, int>, int>> v;
        for (int i = 0; i < n; i++) {
            int s, e;
            cin >> s >> e;
            v.push_back({{s, e}, i});
        }

        sort(v.begin(), v.end());
        int c = 0, j = 0;
        bool check = true;
        for (int i = 0; i < n; i++) {
            int s = v[i].first.first;
            int e = v[i].first.second;
            int th = v[i].second;

            if (c <= s) {
                c = e;
                ans[th] = 'C';
            } else if (j <= s) {
                j = e;
                ans[th] = 'J';
            } else {
                check = false;
                break;
            }
        }
        if (check) {
            cout << "Case #" << tc << ": " << ans << '\n';
        } else {
            cout << "Case #" << tc << ": IMPOSSIBLE\n";
        }
    }
    return 0;
}
```

### 4. ESAb ATAd

``` cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int num_test_cases, b;
    cin >> num_test_cases >> b;
    if (b == 10) {
        for (int tc = 0; tc < num_test_cases; ++tc) {
            string ans;
            ans.resize(b);

            for (int i = 1; i <= 10; i++) {
                char a;
                cout << i << endl;
                cin >> ans[i - 1];
            }
            cout << ans << endl;
            char result;
            cin >> result;
        }
    }
    return 0;
}

```

### 5. Indicium

``` cpp
#include <iostream>
#include <vector>
using namespace std;

bool find_k = false;
bool find_answer = false;
vector<vector<int>> v;
void fix_k(int now, int n, int k, int s);
void fix_num(int n, int num, int ln);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int TC;
    cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        int n, k;
        cin >> n >> k;

        v.clear();
        for (int i = 0; i < n; i++) {
            vector<int> a(n, 0);
            v.push_back(a);
        }

        find_k = false;
        find_answer = false;
        fix_k(0, n, k, 1);
        if (find_answer == false) {
            cout << "Case #" << tc << ": IMPOSSIBLE\n";
        } else {
            cout << "Case #" << tc << ": POSSIBLE\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << v[i][j] << " ";
                }
                cout << "\n";
            }
        }
    }
    return 0;
}
void fix_k(int now, int n, int k, int s) {
    if (now == n) {
        fix_num(n, 1, 0);
        return;
    }
    for (int i = s; i <= n; i++) {
        if (k - i < n - now - 1) break;
        if (k - i > n * (n - now - 1)) continue;
        v[now][now] = i;
        fix_k(now + 1, n, k - i, i);
        if (find_answer == true) return;
    }
}

void fix_num(int n, int num, int ln) {
    if (num == n + 1) {
        find_answer = true;
        return;
    }
    if (ln == n) {
        fix_num(n, num + 1, 0);
        return;
    }

    for (int i = 0; i < n; i++) {  // num -> ln행 , i열
        if (i == ln && v[ln][i] == num) {
            fix_num(n, num, ln + 1);
            if (find_answer) return;
            continue;
        }
        if (find_answer) return;
        bool possible = true;
        if (v[i][i] == num || v[ln][ln] == num) possible = false;
        if (possible == false) continue;

        for (int j = 0; j < ln; j++) {
            if (v[j][i] == num) {
                possible = false;
                break;
            }
        }
        if (possible && v[ln][i] == 0) {
            v[ln][i] = num;
            fix_num(n, num, ln + 1);
            if (find_answer) return;
            v[ln][i] = 0;
        }
        if (find_answer) return;
    }
}

```
