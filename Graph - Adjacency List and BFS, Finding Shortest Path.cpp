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
	void bfs(T src, T dest) {
		queue<T> q;
		q.push(src);
		unordered_map<T, bool> visited;
		unordered_map<T, T> dist, parent;
		visited[src] = true;
		parent[src] = -1;
		dist[src] = 0;
		while (!q.empty()) {
			T node = q.front();
			q.pop();
			cout << node << ' ';
			for (auto a : adjList[node]) {
				if (!visited[a]) {
					q.push(a);
					visited[a] = true;
					parent[a] = node;
					dist[a] = dist[node] + 1;
				}
			}
		}
		cout << '\n';
		cout << dest << ' ' << dist[dest] << '\n';
		while (dest != -1) {
			cout << dest << "<--";
			dest = parent[dest];
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
	g.bfs(1, 5);
}