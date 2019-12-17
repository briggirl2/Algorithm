### 위상 정렬 ( Topological Sort )

* *사이클이 없는 방향 그래프 (Directed Acyclic Graph, DAG)* 에서 정점들을 정렬하는 것. 
* 각 노드가 자신으로부터 나가는 간선이 있는 노드들보다 앞에 오게 하는 것.<br>
* ex) 선수 과목, 데드락
* ex) 9466(텀프로젝트)
* 구현 아이디어: indegree가 0인 정점부터 큐에 넣어서 구현

``` c++
void TopologicalSort(struct Graph *G) {
	int cnt = 0;
	for (v = 0; v < G->V; v++) {
		if (indegree[v] == 0)
			Q.push(v);
	}
	while (!Q.empty()) {
		v = Q.top();
		Q.pop();
		cnt++;
		for each w adjacent to v {
			if (--indegree[w] == 0)
				Q.push(w);
		}
	}
	if (cnt != G->V) // cycle!
}
```