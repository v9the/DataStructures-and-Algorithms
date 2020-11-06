#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph {
public:
	map<T, vector<T>> adjList;
	void addEdge(T u, T v, bool isBiDir = true) {
		adjList[u].push_back(v);
		if (isBiDir) {
			adjList[v].push_back(u);
		}
	}
	unordered_map<T, bool> visited;
	void dfs(T node) {
		cout << node << ' ';
		visited[node] = true;
		for(auto a : adjList[node]) {
			if(!visited[a]) {
				dfs(a);
			}
		}
	}
};

int main() {
	Graph<int> g;
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.dfs(1);
}