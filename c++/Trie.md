# Trie(트라이)
## Trie(트라이)?
<img width="200" alt="Screen Shot 2020-05-08 at 1 42 31 PM" src="https://user-images.githubusercontent.com/40483081/81371064-ca333500-9131-11ea-9d89-4ba582abf7e7.png">

- Prefix Tree, Digital Search Tree, Re**trie**val Tree 로 불리기도 한다.
- 문자열을 저장하고 효율적으로 탐색하기 위한 트리 형태의 자료구조
- 검색어 자동완성, 사전에서 찾기, 문자열 검사 등에서 사용 가능

## 성능
### 시간복잡도
- 제일 긴 문자열의 길이를 L, 총 문자열들의 수를 M이라 할 때
- **생성시 시간복잡도 : O(M*L)**
- **탐색시 시간복잡도 : O(L)**
### 공간복잡도
- 단점!! 
- 각 노드마다 다음 문자를 가리키는 노드가 필요하다. 예를 들어 알파벳에 대해 트라이 생성시 [a-z] 26개의 포인터 배열을 가지고 있어야 한다.
- 최종 메모리 : O(포인터 크기 * 포인터 개수 * 트라이에 존재하는 총 노드의 개수)
### Map과 비교
- Map은 이진 검색 트리 특성상 O(logM)만큼 시간이 필요하고 그 문자열을 확인하는데 O(L*logM)의 시간이 필요하다.
- 따라서 Map과 Trie의 시간복잡도는 다르다!



## C++ Trie Implementation
```cpp
#include <cstdio>
#include <cstring>

struct Trie {
    bool is_terminal;
    Trie* next[26];
    Trie() : is_terminal(false) {
        memset(next, 0, sizeof(next));
    }
    ~Trie() {
        for (int i = 0; i < 26; i++)
            if (next[i])
                delete next[i];
    }

    void insert(const char* key) {
        if (*key == '\0')
            is_terminal = true;
        else {
            int curr = *key - 'A';
            if (next[curr] == NULL)
                next[curr] = new Trie();
            next[curr]->insert(key + 1);
        }
    }

    Trie* find(const char* key) {
        if (*key == '\0') return this;
        int curr = *key - 'A';
        if (next[curr] == NULL) return NULL;
        return next[curr]->find(key + 1);
    }

    bool exist(const char* key) {
        if (*key == '\0' && is_terminal) {
            return true;
        }
        int index = *key - 'A';
        if (next[index] == NULL) {
            return false;
        }
        return next[index]->exist(key + 1);
    }
};

int main() {
    Trie* root = new Trie();

    const char* words[5] = {"be", "bee", "can", "cat", "cd"};

    for (int i = 0; i < 5; ++i) {
        printf("insert : %s\n", words[i]);
        root->insert(words[i]);
    }

    printf("\n");

    printf("%s : be\n", root->find("be") != 0 ? "Prefix Exist" : "Prefix Not Exist");
    printf("%s : can\n", root->find("can") != 0 ? "Prefix Exist" : "Prefix Not Exist");
    printf("%s : a\n", root->find("a") != 0 ? "Prefix Exist" : "Prefix Not Exist");
    printf("%s : cat\n", root->find("cat") != 0 ? "Prefix Exist" : "Prefix Not Exist");
    printf("%s : c\n", root->find("c") != 0 ? "Prefix Exist" : "Prefix Not Exist");

    printf("\n");

    printf("%s : c\n", root->exist("c") != 0 ? "String Exist" : "String Not Exist");
    printf("%s : be\n", root->exist("be") != 0 ? "String Exist" : "String Not Exist");
    printf("%s : bee\n", root->exist("bee") != 0 ? "String Exist" : "String Not Exist");
    printf("%s : candy\n", root->exist("candy") != 0 ? "String Exist" : "String Not Exist");
    printf("%s : cd\n", root->exist("cd") != 0 ? "String Exist" : "String Not Exist");

    delete root;

    return 0;
}

/*
output
insert : be
insert : bee
insert : can
insert : cat
insert : cd

Prefix Exist : be
Prefix Exist : can
Prefix Not Exist : a
Prefix Exist : cat
Prefix Exist : c

String Not Exist : c
String Exist : be
String Exist : bee
String Not Exist : candy
String Exist : cd

*/
```

<br><hr>
**참고**<br>
https://en.wikipedia.org/wiki/Trie <br>
https://www.crocus.co.kr/1053 <br>
https://twpower.github.io/187-trie-concept-and-basic-problem <br>
