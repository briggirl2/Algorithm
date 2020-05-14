# Vector 중복 제거 (sort, unique, erase/resize)

**unique**<br>
연속된 값들을 비교해서 같은 값을 제거한다. 따라서 미리 sort 해야한다. <br>
쓰레기 값이 등장하는 위치를 반환한다.<br>
<br>
**erase/resize**<br>
erase나 resize를 사용해서 벡터에서 쓰레기 값 전까지 접근할 수 있도록 함<br>
<br>

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> a = {1, 2, 2, 3, 2, 1, 1, 4};
    unique(a.begin(), a.end());
    for (auto &i : a) {
        cout << i << ' ';
    }  // 1 2 3 2 1 4 (1 4)

    //////////////////////////////////////////////
    
    vector<int> b = {1, 2, 2, 3, 2, 1, 1, 4};
    sort(b.begin(), b.end());
    // 1 1 1 2 2 2 3 4

    vector<int>::iterator it = unique(b.begin(), b.end());
    // 1 2 3 4 (2 2 3 4)
    cout << it - b.begin() << "\n";  // 4 -> 따라서 index 4 부터 쓰레기값!

    b.resize(distance(b.begin(), it)); // ==  b.erase(it, b.end());
    for (auto &i : b) {
        cout << i << ' ';
    }  // 1 2 3 4
    return 0;
}
```
**예제**<br>
<a href="https://www.acmicpc.net/problem/18870">18870 좌표 압축</a>
