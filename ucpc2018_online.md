## UCPC 2018 _ 온라인 예선
**A. 수학은 체육과목입니다**<br>

```cpp
#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	long long n;
	cin >> n;
	cout << 4 * n << '\n';
	return 0;
}
```

**B. 카드 합체 놀이**<br>

```cpp
#include<iostream>
#include<queue>
#include <vector>
#include<functional>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	priority_queue<long long, vector<long long>, greater<long long>> q;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		q.push(k);
	}
	for (int i = 0; i < m; i++) {
		long long x = q.top();
		q.pop();
		long long y = q.top();
		q.pop();
		q.push(x + y);
		q.push(x + y);
	}
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += q.top();
		q.pop();
	}
	cout << sum << '\n';
	return 0;
}
```

**D. 나무 탈출**<br>

```cpp
#include<iostream>
#include<vector>
#include <queue>
using namespace std;
vector<int> v[500005];
bool visit[500005];
int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	long long sum = 0;
	queue<pair<int, int>> q;
	q.push({ 1,0 });
	visit[1] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		int check = 0;
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int next = v[x][i];
			if (visit[next] == true) continue;
			check++;
			visit[next] = true;
			q.push({ next, cnt + 1 });
		}
		if (check == 0)
			sum = sum + cnt;
	}
	if (sum % 2) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}
	return 0;
}
```

**G. UCPC는 무엇의 약자일까?**<br>

```cpp
#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string ucpc = "UCPC";
	char str[1002];
	int check = 0;
	cin.getline(str, 1002);
	int i = 0;
	while (1) {
		if (str[i] == NULL)	break;
		if (str[i] == ucpc[check])	check++;
		if (check == 4) {
			cout << "I love UCPC\n";
			return 0;
		}
		i++;
	}
	cout << "I hate UCPC\n";
	return 0;
}

**H. 잘못 구현한 에라토스테네스의 체**<br>

```cpp
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	long long ans = 0;
	int j = n, i;
	for (i = 1; i <= sqrt(n - 1); i++) {
		int k = (n - 1) / i;
		ans += (k + 1);
		ans += i*(j - k);
		j = k;
	}
	i = i - 1;
	if (i != j) {//i==(n-1)/i
		for (int k = i + 1; k <= j; k++) {
			ans += (n - 1) / k + 1;
		}
	}
	cout << ans << '\n';
	return 0;
}
```