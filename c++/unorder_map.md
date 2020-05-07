# Unordered_map

>Unordered map 은 Hash-table 기반의 유일한 Key를 가지는 Key 와 Value 쌍으로 값으로 가지는 Hash-container이다.

## unordered_map Class

```cpp
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, int> um;
int main() {
    // 삽입: insert, um[key] 사용
    um.insert(make_pair("aa", 1));
    um.insert(make_pair("bb", 2));
    um.insert(make_pair("cc", 3));
    um["dd"] = 4;
    um["ee"] = 5;

    // count
    if (um.count("aa")) {
        cout << um["aa"] << "\n";
    }
    // output: 1

    //find
    auto item = um.find("dd");
    if (item != um.end()) {
        cout << item->first << " " << item->second << "\n";
    }
    //output: dd 4
    return 0;
}
// 참고: https://umbum.tistory.com/744
```
<br>
<a href="https://docs.microsoft.com/ko-kr/cpp/standard-library/unordered-map-class?view=vs-2019#remarks">
- MSDN | unordered_map Class</a><br>

<a href="http://www.cplusplus.com/reference/unordered_map/unordered_map/">
- cplusplus | unordered_map</a>


## map VS hash_map(unordered_map) 비교

### map

- Red-Black Tree(RB Tree)기반 : O(logN) 보장
- 모든 데이터는 정렬되어 저장됨

### unordered map

- hash-table 기반

### 성능 비교

[C++] map vs hash_map(unordered_map): https://gracefulprograming.tistory.com/3 [Peter의 우아한 프로그래밍]

- 데이터가 많은 경우에는 unordered_map이 유리
- 문자열을 key로 사용하는 경우 문자열이 길어질수록 unordered_map이 map에 비해 더 성능 저하가 심하다.
- 유사도가 높은 문자열 집합을 key로 사용하는 경우 balancing(node rotation) 비용에 의해 map의 성능이 떨어질 수 있다.

**"결론적으로 key를 이용해 정렬을 해야하는 경우를 제외하고 대량의 데이터를 저장할 때는 unordered_map 사용 추천!"**

