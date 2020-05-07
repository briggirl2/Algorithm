## 1. 크레인 인형뽑기 게임
**c++**
```cpp
#include <stack>
#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    for (int i = 0; i < moves.size(); i++) {
        int m = moves[i] - 1;
        for (int j = 0; j < board.size(); j++) {
            if (board[j][m] != 0) {
                if (s.empty() || s.top() != board[j][m]) {
                    s.push(board[j][m]);
                } else {
                    s.pop();
                    answer += 2;
                }
                board[j][m] = 0;
                break;
            }
        }
    }
    return answer;
}
```
**python3**
```py
def solution(board, moves):
    answer = 0
    s = []
    for i in moves:
        for j in range(len(board)):
            if board[j][i - 1] != 0:
                if len(s) == 0 or s[-1] != board[j][i - 1]:
                    s.append(board[j][i - 1])
                else:
                    s.pop()
                    answer += 2
                board[j][i - 1] = 0
                break
    return answer

```
<br>

## 2. 튜플
**c++**
```cpp
#include <string>
#include <vector>

using namespace std;

vector<int> subset[505];
bool visited[100005];

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> temp;
    int n = 0;
    int all = 0;
    for (int i = 1; i < s.length() - 1; i++) {
        if (s[i] == '{') {
            temp.clear();
            n = 0;
            all++;
        } else if (s[i] == '}') {
            temp.push_back(n);
            n = 0;
            int k = temp.size();
            subset[k] = temp;
            i += 1;
        } else if (s[i] == ',') {
            temp.push_back(n);
            n = 0;
        } else {
            int t = s[i] - '0';
            n = n * 10 + t;
        }
    }

    for (int i = 1; i <= all; i++) {
        for (int j = 0; j < i; j++) {
            int k = subset[i][j];
            if (!visited[k]) {
                visited[k] = true;
                answer.push_back(k);
                break;
            }
        }
    }
    return answer;
}
```
**python3**
```py
import re
from collections import Counter
def solution(s):

    s = Counter(re.findall("\d+", s))
    return list(
        map(int, [k for k, v in sorted(s.items(), key=lambda x: x[1], reverse=True)])
    )
```
<br>

## 3. 불량 사용자
**c++**
```cpp
#include <set>
#include <string>
#include <vector>
using namespace std;

int user_cnt, banned_id_cnt;
bool used[10];
int answer = 0;
set<vector<int>> s;

void dfs(int n, vector<string> user_id, vector<string> banned_id) {
    if (n == banned_id_cnt) {
        vector<int> temp;
        for (int i = 0; i < user_cnt; i++) {
            if (used[i]) {
                temp.push_back(i);
            }
        }
        if (s.find(temp) == s.end()) {
            s.insert(temp);
            answer++;
        }
        return;
    }
    for (int i = 0; i < user_cnt; i++) {
        if (used[i]) continue;
        if (banned_id[n].length() != user_id[i].length()) continue;
        bool possible = true;
        for (int k = 0; k < banned_id[n].length(); k++) {
            if (banned_id[n][k] == '*') continue;
            if (banned_id[n][k] != user_id[i][k]) {
                possible = false;
                break;
            }
        }
        if (possible) {
            used[i] = true;
            dfs(n + 1, user_id, banned_id);
            used[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    user_cnt = user_id.size();
    banned_id_cnt = banned_id.size();
    dfs(0, user_id, banned_id);
    return answer;
}
```
**python3**
```py
from collections import defaultdict

answer = []
used = defaultdict(int)


def dfs(n, user_id, banned_id):
    global answer
    global used
    if n == len(banned_id):
        tmp = []
        for i in range(len(user_id)):
            if used[user_id[i]] == 1:
                tmp.append(user_id[i])
        if tmp not in answer:
            answer.append(tmp)
        return

    for i in user_id:
        if used[i] == 1 or len(banned_id[n]) != len(i):
            continue
        possible = True
        for idx, k in enumerate(banned_id[n]):
            if k != "*" and k != i[idx]:
                possible = False
                break
        if possible:
            used[i] = 1
            dfs(n + 1, user_id, banned_id)
            used[i] = 0


def solution(user_id, banned_id):
    global answer
    global used
    dfs(0, user_id, banned_id)
    return len(answer)
```
<br>

## 4. 호텔 방 배정
**c++**
```cpp
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<long long, long long> m;

long long find(long long x) {
    if (m.find(x) == m.end()) {
        m[x] = x + 1;
        return m[x];
    } else {
        return m[x] = find(m[x]);
    }
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    for (int i = 0; i < room_number.size(); i++) {
        long long now = room_number[i];

        long long a = find(now);
        answer.push_back(a - 1);
    }

    return answer;
}
```
**python3**
```py
def solution(k, room_number):
    answer = []
    room_dic = {}
    for i in room_number:
        tmp = i
        update = [tmp]
        while tmp in room_dic:
            tmp = room_dic[tmp]
            update.append(tmp)
        answer.append(tmp)
        for j in update:
            room_dic[j] = tmp + 1
    return answer
```
<br>

## 5. 징검다리 건너기
**c++ : multiset(segment tree)**
```cpp
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

multiset <int> s;

int solution(vector<int> stones, int k) {
    int ans = 200000001;
    for (int i = 0; i < k - 1; i++) 
        s.insert(stones[i]);
    for (int i = k-1; i<stones.size(); i++) {
        s.insert(stones[i]);
        auto it = s.end();
        it--;
        ans = min(ans, *it);
        s.erase(s.find(stones[i-(k-1)]));
    }
    return ans;
}
```

**c++ : binary search**
```cpp
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
    int left = 1;
    int right = 200000001;
    while (left <= right) {
        int mid = (left + right) / 2;
        int now = 0;
        bool possible = true;
        for (int i = 0; i < stones.size(); i++) {
            now = (stones[i] - mid <= 0)? now+1: 0;
            if (now >= k) {
                possible = false;
                break;
            }
        }
        if (possible)
            left = mid + 1;
        else
            right = mid -1;
    }
    return left;
}
```
