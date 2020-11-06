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
	// Connected Components in an undirected graph
	unordered_map<T, bool> visited;
	void connected_components() {
		for(auto a : adjList) {
		if(!visited[a.first]) {
			util(a.first);
			cout << '\n';
		}
	}
	}
	void util(T node) {
		cout << node << ' ';
		visited[node] = true;
		for(auto a : adjList[node]) {
			if(!visited[a]) {
				util(a);
			}
		}
	}
};

int main() {
	Graph<int> g;
	g.addEdge(1, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 4); 
	g.connected_components();
}