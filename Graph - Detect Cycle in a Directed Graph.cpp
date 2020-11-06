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
	// Detect Cycle in a Directed Graph
	unordered_map<T, bool> visited, stack;
	bool is_cyclic() {
		for (auto a : adjList) {
			if (util(a.first))
				return true;
		}
		return false;
	}
	bool util(T node) {
		if (!visited[node]) {
			visited[node] = stack[node] = true;
			for (auto a : adjList[node]) {
				if (!visited[a] && util(a))
					return true;
				else if (stack[a])
					return true;
			}
		}
		stack[node] = false;
		return false;
	}
};

int main() {
	Graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	//g.addEdge(2, 0);
	g.addEdge(2, 3);
	//g.addEdge(3, 3);
	g.addEdge(2, 4);
	//g.addEdge(4, 1);
	g.addEdge(0, 5);
	g.addEdge(5, 5);
	g.is_cyclic() ? cout << "true" : cout << "false";
}