# Heap?

* Heap이란 완전 이진 트리의 일종으로 부모 노드와 자식 노드 간에 항상 대소 관계가 성립하는 자료구조
*  부모 노드가 자식 노드보다 항상 크면 최대힙(Max Heap), <br> 부모 노드가 자식 노드보다 항상 작으면 최소힙(Min Heap)
*  이 때 부모와 자식 노드의 관계만을 고려하며 형제 노드들 간의 관계는 고려할 필요가 없다.
*  std::priority_queue를 이용해서 구현이 가능
*  제자리 정렬이다  -> 부가적인 공간이 필요 없다. 
*  안정적인 정렬은 아니다. -> 같은 키를 가진 항목들에 대한 상대적 순서가 유지되지 않을 수도 있다. 
*  삽입/삭제 시 원소 하나당 *logN*

# Heap 구현

### 공통

* 완전 이진 트리는 배열로 구현, 편의상 배열의 인덱스는 1부터 사용
* 특정 노드의 인덱스 = *cur* 라고 하면<br>부모노드의 인덱스 = *cur / 2* <br> 자식노드의 인덱스 = *cur* * *2* , *cur* *  *2 + 1*

### 삽입

완전 이진 트리의 가장 끝에 원소를 추가하고<br>
추가한 원소와 해당 원소의 부모 노드의 크기를 비교해가면서 위치를 찾는다.

```c++
void push(int data) {
	heap[++heap_cnt] = data;
	int child = heap_cnt;
	int parent = child / 2;
	while (child > 1 && heap[parent] < heap[child]) {
		swap(&heap[parent], &heap[child]);
		child = parent;
		parent = child / 2;
	}
}
```

### 삭제

힙의 루트 노드를 반환하고 루트 노드에 힙의 가장 끝 원소를 대입한다. <br>
루트 노드부터 시작해서 자식과 게쏙 비교해가면서 힙을 재정렬한다.<br>
이 때, 자식은 왼쪽 오른쪽 중에서 더 큰 자식과 바꾼다. (최대 힙일 경우)

```c++ 
int pop() {
	int result  = heap[1];
	heap[1] = heap[heap_cnt--];
	int parent = 1;
	int child = parent * 2;
	if (child + 1 <= heap_cnt) {
		child = (heap[child] > heap[child+1]) ? child : child + 1;
	}
	while (child <= heap_cnt && heap[parent] < heap[child]) {
		swap(&heap[parent], &heap[child]);
		parent = child;
		child = child * 2;
		if (child + 1 <= heap_cnt) {
			child = (heap[child] > heap[child+1]) ? child : child + 1;
		}
	}
	return result;
```