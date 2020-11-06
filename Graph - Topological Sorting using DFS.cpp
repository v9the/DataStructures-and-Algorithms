#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph {
public:
	map<T, vector<T>> adjList;
	void addEdge(T u, T v, bool isBiDir = false) {
		adjList[u].push_back(v);
		if (isBiDir) {
			adjList[v].push_back(u);
		}
	}
	// only in DAG
	unordered_map<T, bool> visited;
	void tls() {
		for(auto a : adjList) {
			if(!visited[a.first]) {
				util(a.first);
			}
		}
	}
	stack<T> store;
	void util(T node) {
		visited[node] = true;
		for(auto a : adjList[node]) {
			if(!visited[a]) {
				util(a);
			}
		}
		store.push(node);
	}
	void print() {
		while(!store.empty()) {
			cout << store.top() << ' ';
			store.pop();
		}
	}
};

int main() {
	Graph<int> g;
	g.addEdge(1, 5);
	g.addEdge(2, 5);
	g.addEdge(5, 4);
	g.addEdge(5, 6);
	g.addEdge(4, 3);
	g.addEdge(4, 7);
	g.addEdge(6, 7);
	g.tls();
	g.print();
}