## 1. 크레인 인형뽑기 게임
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
```cpp
#include <stack>
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
<br>

## 3. 불량 사용자
```cpp
#include <algorithm>
#include <string>
#include <vector>

#include <iostream>

using namespace std;

int user_cnt, banned_id_cnt;
bool used[10];
vector<vector<int>> v;
int answer = 0;

void dfs(int n, vector<string> user_id, vector<string> banned_id) {
    if (n == banned_id_cnt) {
        vector<int> temp;
        for (int i = 0; i < user_cnt; i++) {
            if (used[i]) {
                temp.push_back(i);
            }
        }
        bool check = false;
        for (int i = 0; i < v.size(); i++) {
            bool check2 = true;
            for (int j = 0; j < v[i].size(); j++) {
                if (temp[j] != v[i][j]) {
                    check2 = false;
                    break;
                }
            }
            if (check2 == true) {
                check = true;
                break;
            }
        }
        if (check == false) {
            v.push_back(temp);
            answer += 1;
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
<br>

## 4. 호텔 방 배정
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
}```
